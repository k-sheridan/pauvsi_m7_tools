classdef Roomba
    %Roomba Summary of this class goes here
    %   A roomba 
    
    properties
        pos;
        yaw;
        desiredYaw;
        rotating = 0;
        isObstacle = 0;
        turnTimer = 0;
        noiseTimer = 0;
        
        %CONSTANTS
        FORWARD_VELOCITY = 0.42;
        ANGULAR_VELOCITY = pi / 2;
        TURN_NOISE = pi / 8; %+/- pi/8
    end
    
    methods
        %constructor for the Roomba
        function obj = Roomba(pos, yaw, isObstacle)
            if isvector(pos)
                obj.pos = pos;
                if isscalar(yaw)
                    obj.yaw = yaw;
                    obj.desiredYaw = yaw;
                   if isscalar(isObstacle)
                       obj.isObstacle = isObstacle;
                   else
                      error('isObstacle must be 0 or 1') 
                   end
                else
                    error('yaw must be scalar')
                end
            else
                error('pos must be a 1X3 vector')
            end
        end
        
        % the run function
        function obj = run(obj, dt, randomNumberGen)
            %set the random number generator for repeatablilty
            rng(randomNumberGen);
            %check timers
            if ~(obj.isObstacle)
                if obj.noiseTimer >= 5
                    obj.desiredYaw = obj.desiredYaw + ((rand * 2) - 1) * obj.TURN_NOISE;
                    obj.rotating = 1; % set the object to rotate
                    obj.noiseTimer = dt; %reset timer
                end
                if obj.turnTimer >= 20
                    obj.desiredYaw = obj.desiredYaw + pi;
                    obj.rotating = 1; % set the object to rotate
                    obj.turnTimer = dt;
                end
            else
                %TODO do something for the obstacle robot like rotate or
                %stop
            end
            %run the roomba
            if obj.rotating
                obj = obj.rotate(dt);
            else
                obj = obj.drive(dt);
            end
            %update timers
            obj.noiseTimer = obj.noiseTimer + dt;
            obj.turnTimer = obj.turnTimer + dt;
        end
        
        %drive function
        function obj = drive(obj, dt)
            obj.pos(1) = obj.pos(1) + (obj.FORWARD_VELOCITY * cos(obj.yaw) * dt);
            obj.pos(2) = obj.pos(2) + (obj.FORWARD_VELOCITY * sin(obj.yaw) * dt);
        end
        
        %rotate function
        function obj = rotate(obj, dt)
            %normalize the angles
            obj.yaw = obj.normalizeAngle(obj.yaw);
            obj.desiredYaw = obj.normalizeAngle(obj.desiredYaw);
            %determine the direction of rotation first
            %POSITIVE Direction distance to travel
            if obj.desiredYaw < obj.yaw
                POS_dist = (2 * pi - obj.yaw) + obj.desiredYaw;
            else
                POS_dist = obj.desiredYaw - obj.yaw;
            end
            %NEGATIVE Distance to travel
            if obj.desiredYaw > obj.yaw
                NEG_dist = obj.yaw + (2 * pi - obj.desiredYaw);
            else
                NEG_dist = obj.yaw - obj.desiredYaw;
            end
            %use the distances to dtermine the best direction to travel
            %und rotate the roomba 
            if POS_dist <= NEG_dist
                if POS_dist < obj.ANGULAR_VELOCITY * dt;
                    obj.yaw = obj.desiredYaw;
                    obj.rotating = 0;
                else
                    obj.yaw = obj.yaw + obj.ANGULAR_VELOCITY * dt;
                    obj.rotating = 1;
                end
            else
                if NEG_dist < obj.ANGULAR_VELOCITY * dt
                    obj.yaw = obj.desiredYaw;
                    obj.rotating = 0;
                else
                    obj.yaw = obj.yaw - obj.ANGULAR_VELOCITY * dt;
                    obj.rotating = 1;
                end
            end
        end
        
        %the touch func
        function obj = touch(obj)
            obj.desiredYaw = obj.desiredYaw - pi / 2;
            obj.rotating = 1;
        end    
                
        %normailizes the angle to [0, 2PI)
        function angle = normalizeAngle(obj, angle)
            while angle >= 2 * pi || angle < 0
                if angle >= 2 * pi
                   angle = angle - 2 * pi;
                else
                   angle = angle + 2 * pi;
                end
            end
        end
    end
    
end

