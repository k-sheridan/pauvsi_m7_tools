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
        trajectoryTimer = 0; % this variable will tell the quad how to fly
        
        touching = 0; % bool for whether the quad is touching a roomba or not
        touchTimer = 0; % timer for touch maneuver
        
        %Constants
        I = [0.5, 0, 0;
             0, 0.5, 0;
             0, 0, 0.4]; %moment of inertia for vehicle
        M = 5; %mass of quad in kg
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
        function [obj, usedRNG] = run(obj, dt, randomNumberGen)
            %set the random number generator for repeatablilty
            rng(randomNumberGen);
            
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
            
            %save rng in its state
            usedRNG = rng;
        end
    end
    
end

