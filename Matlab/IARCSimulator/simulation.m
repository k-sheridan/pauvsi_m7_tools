function [ results ] = simulation( seed )
%Simulation for training and testing
% Use this to train or test a neural network
% PROGRAMATIC RULES: coordinate system ([-10, 10], [-10, 10])
% When working with nerual net the inputs must be accounted for

GAME_TIME_LIMIT = 600; %600 seconds time limit
GAME_DT = 0.1; %time change for game
rng(seed); %set the rng
randomNumberGenerator = rng; %create the random number generator

%Initialize game time variables
%create the roombas (1X10)
for index = (1:1:10)
    yaw = index * pi / 5;
    roombas(index) = Roomba([1 * cos(yaw), 1 * sin(yaw), 0], yaw, 0);
end
%start the game
for t = (0:GAME_DT:GAME_TIME_LIMIT)
    %run roombas and pass back the rng
    for index = (1:1:length(roombas))
        [roombas(index), randomNumberGenerator] = roombas(index).run(GAME_DT, randomNumberGenerator);
    end
    if ~mod(t,1)
        drawSimulation(roombas)
    end
    %pause(0.1);
end
end

%%
%used to check if a roomba has collided with and other roombas or obstacles
%roombaIndex: the index of the roomba that is being checked
function [collided] = hasRoombaCollided(roombaIndex, roombas)
end
