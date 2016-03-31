classdef Roomba
    %Roomba Summary of this class goes here
    %   A roomba 
    
    properties
        pos;
        yaw;
        desiredYaw;
        rotating = 0;
        isObstacle = 0;
        
        %CONSTANTS
        FORWARD_VELOCITY = 0.42;
        ANGULAR_VELOCITY = pi / 2;
    end
    
    methods
        %constructor for the Roomba
        function obj = Roomba(pos, yaw, isObstacle)
            if isvector(pos)
                obj.pos = pos;
                if isscalar(yaw)
                    obj.yaw = yaw;
                    obj.yaw = yaw;
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
        function obj = run(obj, dt)  
            
        end
        
        %drive function
        function obj = drive(obj, dt)
            obj.pos(1) = obj.pos(1) + (obj.FORWARD_VELOCITY * cos(obj.yaw) * dt);
            obj.pos(2) = obj.pos(2) + (obj.FORWARD_VELOCITY * sin(obj.yaw) * dt);
        end
        
        %rotate function
        function obj = rotate(obj, dt)
            
        end
        
        %normailze angle to [0 , 2PI)
        function obj = normalizeYaw(obj)
            angle = [obj.yaw];
            
            while angle >= 2 * pi || angle < 0
                if angle >= 2 * pi
                   angle = angle - 2 * pi;
                else
                   angle = angle + 2 * pi;
                end
            end
            
            normalizedYaw = angle;
            
            [obj.yaw] = normalizedYaw;
        end
    end
    
end

