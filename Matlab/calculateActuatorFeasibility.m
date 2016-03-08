function [Error] = calculateActuatorFeasibility(Coefficients, Mass, Moment, MaxVel, tf)
%UNTITLED4 Summary of this function goes here
%   This function will test a given set of polynomials to see if they fit
%   within the actuator constraints specified
%   ESSENTIALLY
%   Coefficients: a 3X10 Matrix of coefficients
%   Mass
%   Moment - vector
%   tf: the final time

% Tackle the x axis polynomial first
g = -9.81

% Find the maximum accelerations
maximums = calculateMaximums(Coefficients, 2, tf)
%now test whether these maximums are within feasible limits


end

