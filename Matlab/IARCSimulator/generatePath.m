function [ trajectory, waypoints] = generatePath( targetPos, targetVel, quad,  obstacles)
%GENERATEPATH Summary of this function goes here
%   Generates a path from quad to roomba. It then will make an actuator constrained parmetric trajectory

ASTAR_DIM = readParam('SimulationParams.txt', 'aStarResolution');
ROOMBA_PREDICT = readParam('SimulationParams.txt', 'roombaPosPredictConst');
BUILD_OUT_LENGTH = readParam('SimulationParams.txt', 'aStarBuildOutLength');

%%first predict the position of roomba when arriving
dist = norm(targetPos - quad.pos)
timeToArrival = ROOMBA_PREDICT * dist % simple linear prediction
%used the time to arrival and target state to predict the final goal
%position
goalPos = targetPos + (targetVel * timeToArrival) %this is the goal pos

%now we must create the image 
aStarField = zeros(ASTAR_DIM, ASTAR_DIM);

%draw the trail that obstacles will make
for it = (1:1:length(obstacles))
    for t = (0:0.25:timeToArrival)
        obstacles(it).yaw = obstacles(it).yaw + ((2 * pi) / ((8 * pi / obstacles(it).FORWARD_VELOCITY) / 0.25));
        obstacles(it).pos = obstacles(it).pos + (obstacles(it).FORWARD_VELOCITY * [cos(obstacles(it).yaw), sin(obstacles(it).yaw), 0] * 0.25);
        arrayPos = realPos2AStarPos(obstacles(it).pos, ASTAR_DIM);
        aStarField(arrayPos(1), arrayPos(2)) = 255;
        
        %now we must build out this pixel by the specified amount
        for dist = (1:1:BUILD_OUT_LENGTH)
            %first top to bottom 
            for pos = (arrayPos(1) - dist:1:arrayPos(1) + dist)
                aStarField(pos, arrayPos(2) + dist) = 255;
                aStarField(pos, arrayPos(2) - dist) = 255;
            end
            %first left to right 
            for pos = (arrayPos(2) - dist:1:arrayPos(2) + dist)
                aStarField(arrayPos(1) + dist, pos) = 255;
                aStarField(arrayPos(1) - dist, pos) = 255;
            end
        end
    end
end

image(aStarField);

end

%%convert real position to a* position (ASTAR_DIM X ASTARDIM)
function [aStarPos] = realPos2AStarPos(realPos, aStarDim)
aStarPos = [round((realPos(2) + 10) * (aStarDim / 20)), round((realPos(1) + 10) * (aStarDim / 20))];
end
