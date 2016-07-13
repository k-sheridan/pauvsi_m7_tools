function [ results ] = simulation( seed )
%Simulation for training and testing
% Use this to train or test a neural network
% PROGRAMATIC RULES: coordinate system ([-10, 10], [-10, 10])
% When working with nerual net the inputs must be accounted for

GAME_TIME_LIMIT = 600; %600 seconds time limit
GAME_DT = 0.02; %time change for game
ROOMBA_DT = 0.1;
rng(seed); %set the rng
randomNumberGenerator = rng; %create the random number generator

%Initialize game time variables
%create the quad
quadcopter = Quadcopter([0, 0, 2.5]);
%quadcopter.motorForces = [12.5, 12.5, 12.5, 12.5];
%create the roombas (1X10)
for index = (1:1:10)
    yaw = index * pi / 5;
    roombas(index) = Roomba([1 * cos(yaw), 1 * sin(yaw), 0], yaw, 0);
end
%create the obstacle robots
for index = (1:1:4)
    yaw = index * (pi / 2);
    obstacles(index) = Roomba([4 * cos(yaw), 4 * sin(yaw), 0], yaw + (pi / 2), 1); % set them to obstacles
end
%start the game
for t = (0:GAME_DT:GAME_TIME_LIMIT)
    %run the quad and pass rng
    [quadcopter, randomNumberGenerator] = quadcopter.run(GAME_DT, randomNumberGenerator);
    
    if ~mod(t, ROOMBA_DT)
        %collide all robots
        [roombas, obstacles] = collideGroundRobots(roombas, obstacles);
        %run roombas and pass back the rng
        for index = (1:1:length(roombas))
            [roombas(index), randomNumberGenerator] = roombas(index).run(GAME_DT, randomNumberGenerator);
        end
        %run the obstacles
        for index = (1:1:length(obstacles))
            [obstacles(index), randomNumberGenerator] = obstacles(index).run(GAME_DT, randomNumberGenerator);
        end
    end
    if ~mod(t,0.1)
        drawSimulation(roombas, obstacles, quadcopter)
        %fprintf('Time: %f\n', t);
    end
    %pause(0.1);
end
end

%%COLLISION DETECTION
%used to check if a roomba has collided with and other roombas or obstacles
%roombaIndex: the index of the roomba that is being checked
%roombas a list of all roombas to check if are collided
%the roomba in roombaIndex must be in the list
function [collided] = hasRoombaCollided(roombaIndex, roombas)
collided = 0;
for index = (1:1:length(roombas))
    if index ~= roombaIndex % make sure we are not checking the same one
        if(norm(roombas(index).pos - roombas(roombaIndex).pos) <= roombas(index).RADIUS * 2) % check if they are in range for collision
            %angle between the roombas
            angle = atan2(roombas(index).pos(2) - roombas(roombaIndex).pos(2), roombas(index).pos(1) - roombas(roombaIndex).pos(1));
            diff1 = abs((roombas(roombaIndex).yaw - 2 * pi) - angle);
            diff2 = abs((roombas(roombaIndex).yaw) - angle);
            if diff2 <= pi / 3 || diff1 <= pi / 3
                collided = 1; % the roomba has collided
                break;
            end
        end
    end
end
end

%%COLLIDE ROOMBAS AND OBSTACLES
%
%This will collide the roombas and obstacles accordingly
function [roombas, obstacles] = collideGroundRobots(roombas, obstacles)
    allGroundRobots = roombas;
    allGroundRobots(1, length(roombas) + 1:1:length(obstacles) + length(roombas)) = obstacles;
    for index = (1:1:length(allGroundRobots))
        test = hasRoombaCollided(index, allGroundRobots);
        if test == 1
            if allGroundRobots(index).isObstacle == 0
                allGroundRobots(index).desiredYaw = allGroundRobots(index).desiredYaw - (pi);
                allGroundRobots(index).rotating = 1;
                allGroundRobots(index).driving = 0;
            else
                allGroundRobots(index).obstacleStopTimer = 1;
            end
        end
    end
    
    %set the roombas back
    roombas = allGroundRobots(1, 1:1:length(roombas));
    obstacles = allGroundRobots(1, length(roombas) + 1:1:length(roombas) + length(obstacles));
end

