function [ trajectory, waypoints] = generatePath( targetPos, targetVel, quad,  obstacles)
%GENERATEPATH Summary of this function goes here
%   USES -10, 10 coordinates NOT -1, 1
%   Generates a path from quad to roomba. It then will make an actuator constrained parmetric trajectory

ASTAR_DIM = readParam('SimulationParams.txt', 'aStarResolution');
ROOMBA_PREDICT = readParam('SimulationParams.txt', 'roombaPosPredictConst');
BUILD_OUT_LENGTH = readParam('SimulationParams.txt', 'aStarBuildOutLength'); % JUST FOR THE MAP GENERATION!

%%first predict the position of roomba when arriving
dist = norm(targetPos - quad.pos)
timeToArrival = ROOMBA_PREDICT * dist % simple linear prediction
%used the time to arrival and target state to predict the final goal
%position
targetPos = targetPos + (targetVel * timeToArrival) %this is the goal pos

%now we must create the image
aStarField = zeros(ASTAR_DIM, ASTAR_DIM);

obstaclePath = [0, 0, 0];
targetAStarPos = realPos2AStarPos(targetPos, ASTAR_DIM);
oldTargetPos = targetAStarPos;

%where is the quad in astar space
quadAStarPos = realPos2AStarPos(quad.pos, ASTAR_DIM);

%these are for if the quad is in the obstacle field
quadObsFlag = 0;
firstWaypoint = [0, 0];

realFirstWaypoint = [0, 0];
realNewTarget = [0, 0];

%functional variables for this section.
extrapolatedTarget = 0;
extrapolatedQuad = 0;

%draw the trail that obstacles will make
for it = (1:1:length(obstacles))
    for t = (0:0.25:timeToArrival)
        obstacles(it).yaw = obstacles(it).yaw + ((2 * pi) / ((8 * pi / obstacles(it).FORWARD_VELOCITY) / 0.25));
        obstacles(it).pos = obstacles(it).pos + (obstacles(it).FORWARD_VELOCITY * [cos(obstacles(it).yaw), sin(obstacles(it).yaw), 0] * 0.25);
        arrayPos = realPos2AStarPos(obstacles(it).pos, ASTAR_DIM);
        aStarField(arrayPos(1), arrayPos(2)) = 1;
        obstaclePath(t * 4 + 1, :) = obstacles(it).pos();
        
        %now we must build out this pixel by the specified amount
        for dist = (1:1:BUILD_OUT_LENGTH)
            %first top to bottom
            for pos = (arrayPos(1) - dist:1:arrayPos(1) + dist)
                aStarField(pos, arrayPos(2) + dist) = 1;
                aStarField(pos, arrayPos(2) - dist) = 1;
            end
            %first left to right
            for pos = (arrayPos(2) - dist:1:arrayPos(2) + dist)
                aStarField(arrayPos(1) + dist, pos) = 1;
                aStarField(arrayPos(1) - dist, pos) = 1;
            end
        end
    end
    
    %now check if thw target position is inside
    if aStarField(targetAStarPos(1), targetAStarPos(2)) == 1 && ~extrapolatedTarget
        %we must move it away from the obstacle
        %first find the closest point
        [m, ~] = size(obstaclePath);
        closestPointIndex = 1;
        for it2 = (1:1:m)
            if norm(obstaclePath(it2, :) - targetPos) < norm(obstaclePath(closestPointIndex, :) - targetPos)
                closestPointIndex = it2;
            end    
        end
        %find the best point for the goal pos
        unitVec = (targetPos(1:2) - obstaclePath(closestPointIndex, 1:2)) / norm((targetPos(1:2) - obstaclePath(closestPointIndex, 1:2)));
        newTargetPos = (((BUILD_OUT_LENGTH + 3) / ASTAR_DIM * 20) * unitVec) + obstaclePath(closestPointIndex, 1:2);
        realNewTarget = newTargetPos
        targetAStarPos = realPos2AStarPos(newTargetPos, ASTAR_DIM);
        
        extrapolatedTarget = 1;
    end
    
    %now check the quads pos
    if aStarField(quadAStarPos(1), quadAStarPos(2)) == 1 && ~extrapolatedQuad
         %we must move it away from the obstacle
        %first find the closest point
        [m, ~] = size(obstaclePath);
        closestPointIndex = 1;
        for it2 = (1:1:m)
            if norm(obstaclePath(it2, :) - quad.pos) < norm(obstaclePath(closestPointIndex, :) - quad.pos)
                closestPointIndex = it2;
            end    
        end
        %find the best point for the first waypoint
        unitVec = (quad.pos(1:2) - obstaclePath(closestPointIndex, 1:2)) / norm((quad.pos(1:2) - obstaclePath(closestPointIndex, 1:2)));
        waypointPos = (((BUILD_OUT_LENGTH + 3) / ASTAR_DIM * 20) * unitVec) + obstaclePath(closestPointIndex, 1:2);
        realFirstWaypoint = waypointPos
        firstWaypoint = realPos2AStarPos(waypointPos, ASTAR_DIM);
        
        quadObsFlag = 1;
        extrapolatedQuad = 1;
    end
end

%aStarField(oldTargetPos(1), oldTargetPos(2)) = 20;
%aStarField(targetAStarPos(1), targetAStarPos(2)) = 40;
%aStarField(quadAStarPos(1), quadAStarPos(2)) = 10;
%aStarField(firstWaypoint(1), firstWaypoint(2)) = 40;

aStarField(targetAStarPos(1), targetAStarPos(2)) = 0;
if quadObsFlag
    aStarField(firstWaypoint(1), firstWaypoint(2)) = 0;
end

%IF YOU WANT TO ADD "FENCE" DO IT HERE!

%%THIS IS NOW USING ROBOTICS TOOL KIT
map = robotics.BinaryOccupancyGrid(aStarField, ASTAR_DIM / 20); % this is a map
map.GridLocationInWorld = [-10, -10];

mapInflated = copy(map);
%inflate(mapInflated, readParam('SimulationParams.txt', 'robotRadius'));

prm = robotics.PRM;
prm.Map = mapInflated;
prm.NumNodes = 200;
prm.ConnectionDistance = 5;

%% RUNNUNG THE PRM ALGORITHM
%check if an additional waypoint must be added
if quadObsFlag % yes there is another waypoint
    if extrapolatedQuad
        startLocation = realFirstWaypoint(1:2)
    else
        startLocation = quad.pos(1:2)
    end
    
    if extrapolatedTarget
        endLocation = realNewTarget(1:2)
    else
        endLocation = targetPos(1:2)
    end
    
    PRMPath = findpath(prm, startLocation, endLocation)
else
    startLocation = aStarPos2RealPos(quadAStarPos, ASTAR_DIM)
    endLocation = aStarPos2RealPos(targetAStarPos, ASTAR_DIM)
    
    waypoints = findpath(prm, startLocation, endLocation)
end

%%SIMPLIFY THE CURRENT PATH FOR EASE OF COMPUTATION
%this is for viewing
%[m, ~] = size(waypoints);
%for index = (1:1:m)
    %aStarField(waypoints(index, 1), waypoints(index, 2)) = 40;
%end

%aStarField = aStarField * 60;

%aStarField(oldTargetPos(1), oldTargetPos(2)) = 20;
%aStarField(targetAStarPos(1), targetAStarPos(2)) = 40;
%aStarField(quadAStarPos(1), quadAStarPos(2)) = 10;
%aStarField(firstWaypoint(1), firstWaypoint(2)) = 40;

%image(aStarField);
%colorbar;
%pause(1);
show(prm);


end

%%convert real position to a* position (ASTAR_DIM X ASTARDIM)
function [aStarPos] = realPos2AStarPos(realPos, aStarDim)
aStarPos = [round((-realPos(2) + 10) * (aStarDim / 20)), round((realPos(1) + 10) * (aStarDim / 20))];
end

function [realPos] = aStarPos2RealPos(aStarPos, aStarDim)
realPos = [((aStarPos(2) / (aStarDim / 20)) - 10), -1 * ((aStarPos(1) / (aStarDim / 20)) - 10)];
end
