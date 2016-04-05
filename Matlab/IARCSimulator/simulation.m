function [ results ] = simulation( seed )
%Simulation for training and testing
% Use this to train or test a neural network

GAME_TIME_LIMIT = 600; %600 seconds time limit
GAME_DT = 0.1; %time change for game

%start the game
for t = (0:GAME_DT:GAME_TIME_LIMIT)
    hold on
    plot((0:GAME_DT:t), (0:GAME_DT:t));
    hold off
    pause(0.01);
end
end

