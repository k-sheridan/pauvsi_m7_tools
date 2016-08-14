classdef Quadcopter
    %QUADCOPTER Summary of this class goes here
    %   performs the operations that a quadrotor performs
    
    properties
        %variables
        pos = [0, 0, 0]; %in meters
        velocity = [0, 0, 0]; %in m/s
        angleQuat = [1, 0, 0, 0]; %in quarternion
        angularVelocity = [0; 0; 0]; % in rad/s 
        motorForces = [0, 0, 0, 0]; % the motor forces are in newtons
        
        positionIntegral = 0; % the I in PID for position matching.
        
        Trajectory;
        Waypoints;
        trajectoryTimer = 0; % this is the current time in the current trajectory
        trajectoryFlightTime = 0;
        
        nextTrajectoryTimer = 0; % this variable tracks how long until next trajectory update
        trajectoryUpdateInterval = readParam('SimulationParams.txt', 'trajectoryUpdateInterval');
        
        touching = 0; % bool for whether the quad is touching a roomba or not
        touchTimer = 0; % timer for touch maneuver
        
        targetIndex = -1; %the index of the roomba that is a target. -1 = no target
        
        flightMode = 1; %mode 1 is position tracking, mode 2 is trajectory following
        
        targetPosition = [0, 0, 2.5]; % this is the target position for the quad when in mode 1
        
        %Constants for state update
        I = [readParam('SimulationParams.txt', 'quadMomentX'), 0, 0;
             0, readParam('SimulationParams.txt', 'quadMomentY'), 0;
             0, 0, readParam('SimulationParams.txt', 'quadMomentZ')]; %moment of inertia for vehicle
        M = readParam('SimulationParams.txt', 'quadMass'); %mass of quad in kg
        G = 9.806; %m/s/s close to G in Georgia
        D = .27 / sqrt(2); % the distance from CM to motorAxle in X and Y
        C = 0; % coefficient of drag for yaw moment 
        %Gains
        POSITION_GAINS_P = [1, 0, 0;
                            0, 1, 0;
                            0, 0, 1];
        POSITION_GAINS_I = [1, 0, 0;
                            0, 1, 0;
                            0, 0, 1];
        POSITION_GAINS_D = [1, 0, 0;
                            0, 1, 0;
                            0, 0, 1];
        MOMENT_GAINS_P = [1, 0, 0;
                          0, 1, 0;
                          0, 0, 1];
        MOMENT_GAINS_D = [1, 0, 0;
                          0, 1, 0;
                          0, 0, 1];
    end
    
    methods
        %% Constructor for Quadcopter
        function obj = Quadcopter(pos)
            obj.pos = pos;
        end
        
        %% the run function
        function [obj, usedRNG] = run(obj, dt, randomNumberGen, roombas, obstacles)
            %set the random number generator for repeatablilty
            rng(randomNumberGen);
            
            %Trajectory Generation
            if obj.nextTrajectoryTimer <= 0 || obj.targetIndex == -1 % if trajectory must be updated
                if obj.targetIndex == -1 || length(roombas) < obj.targetIndex % if the quad has been instructed to wait or roomba is gone
                    %run the neural network for new instruction
                    obj.targetIndex = obj.chooseTarget(roombas, obstacles);
                end
                
                if obj.targetIndex ~= -1 % if there is a target
                    %generate another trajectory
                    % if the quad will still be flying when this trajectory is
                    % to be started
                    if ~obj.touching % if touching has not begun
                        disp('GENERATING NEW TRAJECTORY');
                        [obj.Trajectory, obj.Waypoints, obj.trajectoryFlightTime] = generatePathV2([roombas(obj.targetIndex).pos(1:2), readParam('SimulationParams.txt', 'touchHeight')], roombas(obj.targetIndex).getVelocity(), obj, obstacles);
                        
                        %reset the trajectory timer
                        obj.trajectoryTimer = 0;
              
                    else
                        % the touching has begun. set mode one and update
                        % target position
                        obj.mode = 1;
                        % target position
                        obj.targetPosition(1:2) = roombas(obj.targetIndex).pos(1:2);
                        obj.targetPosition(3) = readParam('SimulationParams.txt', 'touchHeight');
                    end
                end
                
                %reset timer if it ran out
                if obj.nextTrajectoryTimer <= 0
                    obj.nextTrajectoryTimer = obj.trajectoryUpdateInterval;
                end
            else
                % decrease the trajectory timer
                obj.nextTrajectoryTimer = obj.nextTrajectoryTimer - dt;
            end
                
            %now perform quad updates
            [obj, usedRNG] = obj.updateState(dt, rng);
            %I must set the rng again now that it was used
            rng(usedRNG);
            
            %save rng in its state
            usedRNG = rng;
        end
        
        %% the state updater
        function [obj, usedRNG] = updateState(obj, dt, randomNumberGen)
            %set the random number generator for repeatablilty
            rng(randomNumberGen);
            %continue on as usual
            %Calculate total force and torques
            D = obj.D;
            C = obj.C;
            TorqueTransitionMatrix = [ 1,  1,  1,  1; % matrix that will calculate the 
                                       D, -D, -D,  D; % moment and motor forces necessary
                                       D,  D, -D, -D;
                                      -C,  C, -C,  C];
            Force_Torque = TorqueTransitionMatrix * obj.motorForces'; % calculate the torque and forces
            Torque_Body = Force_Torque(2:4); % split the torque into vec
            Total_Force = Force_Torque(1); % total force
            
            % the drive equations
            F_Grav = [0, 0, -obj.M*obj.G]; % the vector of force exterted on quad by gravity
            F_BodyFrame = [0, 0, Total_Force]; % vector of body frame force produced by 
            F_InertialFrame = quatrotate(obj.angleQuat, F_BodyFrame);
            % calculation of air drag - for now don't
            
            %calculate the F_net
            F_net = F_Grav + F_InertialFrame;
            
            %update the current linear velocity
            obj.velocity = obj.velocity + ((F_net * dt) / obj.M);
            %update the current position
            obj.pos = obj.pos + obj.velocity * dt;
            
            %update the current angular velocity
            %fix the torque for quat bug
            Torque_Body(1) = Torque_Body(1) * -1; % I don't know why the rotation is reversed
            obj.angularVelocity = obj.angularVelocity + (obj.I \ Torque_Body) * dt;
            
            %update the quaternion with omega
            deltaAng = eul2quat(wrev(obj.angularVelocity') * dt);
            %multiply the quaternions
            obj.angleQuat = quatmultiply(obj.angleQuat, deltaAng);
            
            %increase the Trajectory clock
            
            %save rng in its state
            usedRNG = rng;
        end
        
        %% sense position
        function [sensePos] = sensePosition(obj)
            sensePos = obj.pos;
        end
        
        %% sense velocity
        function [senseVel] = senseVelocity(obj)
            senseVel = obj.velocity;
        end
        
        %% sense angle quaternion
        function [senseQuat] = senseAngle(obj)
            senseQuat = obj.angleQuat;
        end
        
        %% sense angluar velocity
        function [senseOmega] = senseAngularVelocity(obj)
            senseOmega = obj.angularVelocity;
        end
        
        %% choose the next target
        function [targetIndex] = chooseTarget(obj, roombas, obstacles)
            targetIndex = 5;
        end
        
        %% find the closest time in trajectory to current pos
        function [time] = findIdealStartingPoint(obj)
            
            %resolution of search
            resolution = 0.1; %in seconds
            
            currentTime = 0;
            
            bestTime = 0;
            closestDist = norm(obj.pos - obj.getPosAtTime(currentTime)); % in meters
            
            [~, ~, depth] = size(obj.Trajectory);
            
            for depth_index = (1:1:depth)
                for t = (0:resolution:obj.Trajectory(1, 11, depth_index))
                    if norm(obj.pos - obj.getPosAtTime(currentTime + t)) < closestDist
                        bestTime = currentTime + t;
                        closestDist = norm(obj.pos - obj.getPosAtTime(currentTime + t));
                    end
                end
                
                currentTime = obj.Trajectory(1, 11, depth_index) + currentTime;
            end
            closestDist
            time = bestTime;
        end
        
        %% get position at time of Trajectory
        
        function [pos] = getPosAtTime(obj, time)
            [~, ~, depth] = size(obj.Trajectory);
            
            workingDepth = 1;
            currentAddedTime = 0;
            
            for depth_index = (1:1:depth)
                segmentTime = obj.Trajectory(1, 11, depth_index);
                
                if segmentTime + currentAddedTime >= time && currentAddedTime <= time
                    workingDepth = depth_index;
                    break;
                else
                    currentAddedTime = currentAddedTime + segmentTime;
                end
            end
            
            workingTime = time - currentAddedTime;
            
            pos = [polyval(obj.Trajectory(1, 1:10, workingDepth), workingTime), polyval(obj.Trajectory(2, 1:10, workingDepth), workingTime), polyval(obj.Trajectory(3, 1:10, workingDepth), workingTime)];
        end
        
  %% GET the depth of the current trajectory time
        
        function [z_index, segmentTime] = getDepthFromTime(obj, time)
            [~, ~, depth] = size(obj.Trajectory);
            
            workingDepth = 1;
            currentAddedTime = 0;
            segmentTime = 0;
            
            for depth_index = (1:1:depth)
                segmentTime = obj.Trajectory(1, 11, depth_index);
                
                if segmentTime + currentAddedTime >= time && currentAddedTime <= time
                    workingDepth = depth_index;
                    break;
                else
                    currentAddedTime = currentAddedTime + segmentTime;
                end
            end
            
            z_index = workingDepth;
            
        end
    end
    
    
end

