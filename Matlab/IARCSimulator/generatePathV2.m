function [ Trajectory, Waypoints, TotalFlightTime, prm ] = generatePathV2( targetPos, targetVel, quad,  obstacles, prm )
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
map = robotics.BinaryOccupancyGrid(20, 20,  MAP_RES);
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
        
        fprintf('MOVING START TO [%f, %f]\n', startLocation(1), startLocation(2));
        
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
        
        fprintf('MOVING END TO [%f, %f]\n', endLocation(1), endLocation(2));
        
    end
end

%%GENERATING PATH

%inflate the map to the robot radius
inflate(map, MAP_RADIUS);

%setup prm
prm = robotics.PRM;
prm.Map = map;
prm.NumNodes = readParam('SimulationParams.txt', 'prmNodeCount');
prm.ConnectionDistance = readParam('SimulationParams.txt', 'prmNodeConnectionDist');

%update the prm map
update(prm);

%find the path and set it to Waypoints
PRMPath = findpath(prm, startLocation, endLocation);

%set up the X and Y portions of the Waypoints
if quad.pos(1:2) ~= startLocation % if the quad pos and start are not the same
    
    Waypoints(1, 1:2) = quad.pos(1:2);
    [m, ~] = size(PRMPath);
    Waypoints(2:(m+1), 1:2) = PRMPath;
    
    %attach the target position if it is not already
    if targetPos(1:2) ~= endLocation
        
        [m, ~] = size(Waypoints);
        Waypoints(m + 1, 1:2) = targetPos(1:2);
        
    end
else
    Waypoints = PRMPath;
    
    %attach the target position if it is not already
    if targetPos(1:2) ~= endLocation
        
        [m, ~] = size(Waypoints);
        Waypoints(m + 1, 1:2) = targetPos(1:2);
        
    end
end

%%CREATE Z COORDINATES FOR EACH WAYPOINT AND ITS VELOCITY

[m, ~] = size(Waypoints);
CRUISING_ALT = readParam('SimulationParams.txt', 'cruisingAltitude');
TOUCH_ALT = readParam('SimulationParams.txt', 'touchHeight');
% Assign a Z coordinate for each waypoint
for index = (1:1:m)
    % at first waypoint set z to current z
    if index == 1 
        
        Waypoints(index, 3) = quad.pos(3);
        
    % at second point if it is close to obstacle
    elseif index == 2 & quad.pos(1:2) ~= startLocation(1:2)
        if quad.pos(3) < TOUCH_ALT
            Waypoints(index, 3) = TOUCH_ALT;
        else
            Waypoints(index, 3) = quad.pos(3);
        end
    % last point must be Touching alt
    elseif index == m
        Waypoints(index, 3) = TOUCH_ALT;
    else % all other points should be cruising
        Waypoints(index, 3) = CRUISING_ALT;
    end
end

%now create the velocities for each waypoint

SPEED_UP_DIST = readParam('SimulationParams.txt', 'speedUpDistance');
SLOW_DOWN_DIST = readParam('SimulationParams.txt', 'slowDownDistance');
MAX_VELOCITY = readParam('SimulationParams.txt', 'maxWaypointVelocity');

[m, ~] = size(Waypoints);
WaypointVelocities = zeros(m, 3);

%first calculate the total path distance
pathDistance = 0;
for index = (2:1:m)
    pathDistance = pathDistance + norm(Waypoints(index, 1:3) - Waypoints(index - 1, 1:3));
end

%check to see if the path is too short to speed up all the way
if SPEED_UP_DIST + SLOW_DOWN_DIST < pathDistance % use (pathDistance / 2)
    % run through and set all velocties
    currentDist = 0;
    for index = (1:1:m)
        
        %if not index 1 add the distance
        if index ~= 1
            currentDist = currentDist + norm(Waypoints(index, 1:3) - Waypoints(index - 1, 1:3));
        end
        
        if index == 1
            WaypointVelocities(index, 1:3) = quad.velocity;
        elseif index == m
            WaypointVelocities(index, 1:3) = [0, 0, 0];
        else
            %calculate unit vector for velocity
            unitVec = (Waypoints(index + 1, 1:3) - Waypoints(index, 1:3)) / norm(Waypoints(index + 1, 1:3) - Waypoints(index, 1:3));
            
            if currentDist <= (pathDistance / 2)
                WaypointVelocities(index, 1:3) = ((currentDist / (pathDistance / 2)) * (MAX_VELOCITY - norm(quad.velocity)) + norm(quad.velocity)) * unitVec;
            elseif pathDistance - currentDist < (pathDistance / 2)
                WaypointVelocities(index, 1:3) = (((pathDistance - currentDist) / (pathDistance / 2)) * (MAX_VELOCITY)) * unitVec;
            else
                WaypointVelocities(index, 1:3) = MAX_VELOCITY * unitVec;
            end
        end
        
    end
else
    % run through and set all velocties
    currentDist = 0;
    for index = (1:1:m)
        
        %if not index 1 add the distance
        if index ~= 1
            currentDist = currentDist + norm(Waypoints(index, 1:3) - Waypoints(index - 1, 1:3));
        end
        
        if index == 1
            WaypointVelocities(index, 1:3) = quad.velocity;
        elseif index == m
            WaypointVelocities(index, 1:3) = [0, 0, 0];
        else
            %calculate unit vector for velocity
            unitVec = (Waypoints(index + 1, 1:3) - Waypoints(index, 1:3)) / norm(Waypoints(index + 1, 1:3) - Waypoints(index, 1:3));
            
            if currentDist < SPEED_UP_DIST
                WaypointVelocities(index, 1:3) = ((currentDist / SPEED_UP_DIST) * (MAX_VELOCITY - norm(quad.velocity)) + norm(quad.velocity)) * unitVec;
            elseif pathDistance - currentDist < SLOW_DOWN_DIST
                WaypointVelocities(index, 1:3) = (((pathDistance - currentDist) / SLOW_DOWN_DIST) * (MAX_VELOCITY)) * unitVec;
            else
                WaypointVelocities(index, 1:3) = MAX_VELOCITY * unitVec;
            end
        end
        
    end
end

%%NOW PLUG THE WAY POINT AND VELOCITIES INTO THE TRAJ GEN ALGORITHM

[m, ~] = size(Waypoints);%size of waypoints

%the start constraint of traj gen
startConstraint = [Waypoints(1, 1), WaypointVelocities(1, 1), 0, 0, 0;
                   Waypoints(1, 2), WaypointVelocities(1, 2), 0, 0, 0;
                   Waypoints(1, 3), WaypointVelocities(1, 3), 0, 0, 0;];
%the end constraint of traj gen           
endConstraint = [Waypoints(m, 1), WaypointVelocities(m, 1), 0, 0, 0;
                 Waypoints(m, 2), WaypointVelocities(m, 2), 0, 0, 0;
                 Waypoints(m, 3), WaypointVelocities(m, 3), 0, 0, 0;];
%the mid constraint of traj gen 
midConstraint = [];
if m > 2
    midConstraint = zeros(6, m - 2);
    for index = (1:1:(m - 2))
        midConstraint(1:6, index) = [Waypoints(index + 1, 1); 
                                     Waypoints(index + 1, 2);
                                     Waypoints(index + 1, 3);
                                     WaypointVelocities(index + 1, 1);
                                     WaypointVelocities(index + 1, 2);
                                     WaypointVelocities(index + 1, 3);];
    end
end

%startConstraint
%midConstraint
%endConstraint

QUAD_MASS = readParam('SimulationParams.txt', 'quadMass');
QUAD_MOMENT = [readParam('SimulationParams.txt', 'quadMomentX'), readParam('SimulationParams.txt', 'quadMomentY'), readParam('SimulationParams.txt', 'quadMomentZ')];
QUAD_MIN_Z_FORCE = readParam('SimulationParams.txt', 'quadMinZForce');
QUAD_MAX_FORCE = readParam('SimulationParams.txt', 'quadMaxForce');
QUAD_MAX_ANGLE = readParam('SimulationParams.txt', 'quadMaxAngle');
QUAD_MAX_VELOCITY = readParam('SimulationParams.txt', 'maxVelocity');

%%GENRATE THE TRAJECTORY FAM
[Trajectory, TotalFlightTime] = minimumTimeTrajectoryGenerator(startConstraint, midConstraint, endConstraint, 'VEL', QUAD_MASS, QUAD_MOMENT, QUAD_MAX_VELOCITY, QUAD_MIN_Z_FORCE, QUAD_MAX_FORCE, QUAD_MAX_ANGLE);

%%DRAWING

figure(2);
show(prm);
hold on
plot(targetPos(1), targetPos(2), '*b', 'MarkerSize',10);
plot(quad.pos(1), quad.pos(2), '*g', 'MarkerSize', 10);
plot(startLocation(1), startLocation(2), 'xg', 'MarkerSize', 10);
plot(endLocation(1), endLocation(2), 'xr', 'MarkerSize', 10);
plot3(Waypoints(:, 1), Waypoints(:, 2), Waypoints(:, 3), '-r', 'LineWidth', 2);

legend('PRM Path', 'PRM Node', 'PATH', 'OriginalTargetPos','OriginalQuadPos','Starting Pos', 'Ending Pos');
%hold off

%Plot the Trajectory
figure(2)
[p1, p2] = trajectoryPlotter(Trajectory);    
%daspect([20 20 5])
%axis([-1 11 -1 11 -10 10])
%hold on
arrow3(p1, p2, 'b', 0.4)
hold off
end

