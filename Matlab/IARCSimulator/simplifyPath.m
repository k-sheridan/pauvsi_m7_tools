function [ Waypoints ] = simplifyPath( oldWaypoints, map, SEARCH_RES)
%H Summary of this function goes here
%   This will simplify a set of waypoints
%first setup the first waypoint
Waypoints(1, 1:3) = oldWaypoints(1, 1:3);

%start the simplification loop from the second waypoint

[m, ~] = size(oldWaypoints) % get the size of the waypoints

currentWaypoint = 2 % the current point

while currentWaypoint ~= m % while there are still more waypoints
    %pause(2);
    intersectionFlag = 0 % this flag is to check for an intersection
    
    checkingWaypoint = currentWaypoint + 1
    
    while ~intersectionFlag && checkingWaypoint ~= m % while there is no intersection
        
        %check the line of sight for an obstacle
        
        %distance between waypoints
        dist = norm(oldWaypoints(checkingWaypoint, 1:2) - oldWaypoints(currentWaypoint, 1:2))
        %slope of x axis
        unitVector = (oldWaypoints(checkingWaypoint, 1:2) - oldWaypoints(currentWaypoint, 1:2)) / dist;
        
        %check each point between the waypoints for obstacle at SEARCH_RES
        %resolution
        for it = (0:SEARCH_RES:dist)
            %check for occupancy
            if getOccupancy(map, oldWaypoints(currentWaypoint, 1:2) + (it * unitVector))
                
                intersectionFlag = 1 % set the flag high
                
                %update the Waypoints list if checkingWP - currentWP > 1
                if checkingWaypoint - currentWaypoint > 1 || currentWaypoint == 2
                    %added checkingWP - 1 to list and set it as the current point 
                    [rows, ~] = size(Waypoints);
                    Waypoints(rows + 1, 1:3) = oldWaypoints(checkingWaypoint - 1, 1:3);
                    checkingWaypoint - 1
                    
                    %set new current point
                    currentWaypoint = checkingWaypoint - 1
                    
                    break; % break it
                end
            end
        end
        
        %increment checking waypoint
        checkingWaypoint = checkingWaypoint + 1;
        
        if checkingWaypoint == m
            currentWaypoint = m;
        end
    end
end

%add the last waypoint
[rows, ~] = size(Waypoints);
Waypoints(rows + 1, 1:3) = oldWaypoints(m, 1:3);

end

