function [ targetIndex, numTaps ] = chooseTarget( roombas )
%CHOOSETARGET Summary of this function goes here
%   targetIndex: this is the index of the roomba vector. -1 = hover
%   This will choose a target using a deep net

%%TEMP
targetIndex = rand(1, 9);
numTaps = rand(0, 7);

end

