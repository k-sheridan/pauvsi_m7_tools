function [ Trajectory, Waypoints, prm ] = generatePathV2( targetPos, targetVel, quad,  obstacles, prm )
%GENERATEPATHV2 Summary 
%   This function will create a set of waypoints and trajectory which will
%   fly the aircraft to its goal.

ROOMBA_PREDICT = readParam('SimulationParams.txt', 'roombaPosPredictConst');
MAP_RADIUS = readParam('SimulationParams.txt', 'mapRadius');
MAP_RES = readParam('SimulationParams.txt', 'mapRes');

%%PREDICTING THE FUTURE POSITION OF TARGET

%%first predict the position of roomba when arriving
dist = norm(targetPos - quad.pos);
timeToArrival = ROOMBA_PREDICT * dist; % simple linear prediction
%used the time to arrival and target state to predict the final goal
%position
targetPos = targetPos + (targetVel * timeToArrival); %this is the goal pos

%%FIGURE OUT ALL POSITIONS OF OBSTACLES OVER THE FLIGHT TIME AND PLACE IN
%%MAP

obsDT = 0.25; %Timestep of Obstacles
closeThresholdCoeff = 1.2; % multiplier for whether a target or quad is too close to obstacle

%Instantiate the map
map = robotics.BinaryOccupancyGrid(20, 20,  MAP_RES)
map.GridLocationInWorld = [-10, -10];

%Instantiate the start and end positions
startLocation = quad.pos(1:2);
endLocation = targetPos(1:2);

% setup flags
quadMoveFlag = 0; % flag indicating if quad must be moved
targetMoveFlag = 0; % flag indicating if target must be moved

%draw all obstacle paths and move the goal and starts if necessary
for it = (1:1:length(obstacles))
    
    %reset Flags
    quadMoveFlag = 0; 
    targetMoveFlag = 0;
    
    obstaclePath = zeros(floor(timeToArrival * (1 / obsDT)), 3); % the matrix for storing the obstacle path
    
    for t = (0:obsDT:timeToArrival)
        %Find the yaw and pos of obstacle
        obstacles(it).yaw = obstacles(it).yaw + ((2 * pi) / ((8 * pi / obstacles(it).FORWARD_VELOCITY) / obsDT));
        obstacles(it).pos = obstacles(it).pos + (obstacles(it).FORWARD_VELOCITY * [cos(obstacles(it).yaw), sin(obstacles(it).yaw), 0] * obsDT);
        
        %insert obstacle pos into path
        obstaclePath(round(t * (1 / obsDT) + 1), :) = obstacles(it).pos();
        
        %set the current pos of obstacle as occupancy on map
        setOccupancy(map, obstacles(it).pos(1:2), 1);
        
        %check if quad is too close to obstacle pos
        if ~quadMoveFlag && norm(quad.pos(1:2) - obstacles(it).pos(1:2)) < MAP_RADIUS * closeThresholdCoeff
        
            quadMoveFlag = 1;
        
        end
        
        %check if target is too close to obstacle pos
        if ~targetMoveFlag && norm(targetPos(1:2) - obstacles(it).pos(1:2)) < MAP_RADIUS * closeThresholdCoeff
            
            targetMoveFlag = 1;
        
        end
        
    end
    
    %if the quad is too close find the closest obstacle and move it 
    if quadMoveFlag
        closestObsPosIndex = 1;
        [m, ~] = size(obstaclePath);
        %find the closest obs pos
        for index = (1:1:m)
            if norm(quad.pos(1:2) - obstaclePath(index, 1:2)) < norm(quad.pos(1:2) - obstaclePath(closestObsPosIndex, 1:2))
                closestObsPosIndex = index;
            end
        end
        
        %now create the start location from this distance
        unitVec = (quad.pos(1:2) - obstaclePath(closestObsPosIndex, 1:2)) / norm((quad.pos(1:2) - obstaclePath(closestObsPosIndex, 1:2)));
        startLocation = (unitVec * MAP_RADIUS * closeThresholdCoeff) + quad.pos(1:2);
        
        sprintf('MOVING START TO [%f, %f]\n', startLocation(1), startLocation(2))
        
    end
    
    %if the target is too close find the closest obstacle and move it 
    if targetMoveFlag
        closestObsPosIndex = 1;
        [m, ~] = size(obstaclePath);
        %find the closest obs pos
        for index = (1:1:m)
            if norm(targetPos(1:2) - obstaclePath(index, 1:2)) < norm(targetPos(1:2) - obstaclePath(closestObsPosIndex, 1:2))
                closestObsPosIndex = index;
            end
        end
        
        %now create the end location from this distance
        unitVec = (targetPos(1:2) - obstaclePath(closestObsPosIndex, 1:2)) / norm((targetPos(1:2) - obstaclePath(closestObsPosIndex, 1:2)));
        endLocation = (unitVec * MAP_RADIUS * closeThresholdCoeff) + targetPos(1:2);
        
        sprintf('MOVING END TO [%f, %f]\n', endLocation(1), endLocation(2))
        
    end
end

%%GENERATING PATH

%inflate the map to the robot radius
inflate(map, MAP_RADIUS);

%setup prm
prm = robotics.PRM;
prm.Map = map;
prm.NumNodes = 200;
prm.ConnectionDistance = 5;

%update the prm map
update(prm)

%find the path and set it to Waypoints
PRMPath = findpath(prm, startLocation, endLocation)

%%DRAWING

figure(2);
show(prm);
hold on
plot(targetPos(1), targetPos(2), '*b', 'MarkerSize',10);
plot(quad.pos(1), quad.pos(2), '*g', 'MarkerSize', 10);
plot(startLocation(1), startLocation(2), 'xg', 'MarkerSize', 10);
plot(endLocation(1), endLocation(2), 'xr', 'MarkerSize', 10);

legend('PRM Path', 'PRM Node', 'PATH', 'OriginalTargetPos','OriginalQuadPos','Starting Pos', 'Ending Pos');
hold off
end

