function [ results ] = simulation( seed )
%Simulation for training and testing
% Use this to train or test a neural network

GAME_TIME_LIMIT = 600; %600 seconds time limit
GAME_DT = 0.1; %time change for game
randomNumberGenerator = rng(seed); %create the random number generator

%Initialize game time variables
%create the roombas (1X10)
for index = (1:1:10)
    yaw = index * pi / 5;
    roombas(index) = Roomba([0.3 * cos(yaw), 0.3 * sin(yaw)], yaw, 0);
end
%start the game
for t = (0:GAME_DT:GAME_TIME_LIMIT)
    pause(0.01);
end
end

