function [Error] = calculateActuatorFeasibility(Coefficients, Mass, Moment, MaxVel, tf)
%UNTITLED4 Summary of this function goes here
%   This function will test a given set of polynomials to see if they fit
%   within the actuator constraints specified
%   ESSENTIALLY
%   Coefficients: a 3X10 Matrix of coefficients
%   Mass
%   Moment
%   tf: the final time

% Tackle the x axis polynomial first
g = -9.81

% create the matrix for the velocity coefficients for use later
currentCoefficients = zeros(3, 9);
currentCoefficients(1, :) = polyder(Coefficients(1, :));
currentCoefficients(2, :) = polyder(Coefficients(2, :));
currentCoefficients(3, :) = polyder(Coefficients(3, :));

%calculate the roots of the acceleration for the max/min velocity
accelRootsX = roots(polyder(currentCoefficients(1, :)))';
accelRootsY = roots(polyder(currentCoefficients(2, :)))';
accelRootsZ = roots(polyder(currentCoefficients(3, :)))';

accelRoots = zeros(1, 5);
index = 1;

%this will check if any value in accelRoots doesnt match the X vec and adds
%it
for it = [1:1:length(accelRootsX)]
    if isreal(accelRootsX(it))
        if ~any(~(accelRootsX(it) - accelRoots))
            fprintf('ADDED ACCELERATION ROOT\n')
            accelRoots(index) = accelRootsX(it)
            index = index + 1;
        end
    end
end
%this will check if any value in accelRoots doesnt match the Y vec and adds
%it
for it = [1:1:length(accelRootsY)]
    if isreal(accelRootsY(it))
        if ~any(~(accelRootsY(it) - accelRoots))
            fprintf('ADDED ACCELERATION ROOT\n')
            accelRoots(index) = accelRootsY(it)
            index = index + 1;
        end
    end
end
%this will check if any value in accelRoots doesnt match the Z vec and adds
%it
for it = [1:1:length(accelRootsZ)]
    if isreal(accelRootsZ(it))
        if ~any(~(accelRootsZ(it) - accelRoots))
            fprintf('ADDED ACCELERATION ROOT\n')
            accelRoots(index) = accelRootsZ(it)
            index = index + 1;
        end
    end
end

% now that we know where the roots of the acceleration equation are, we can
% make sure that the requested accelerations are within feasible limits

for it = [1:1:length(accelRoots)]
    if(accelRoots(it) ~= 0)
        polyval(currentCoefficients(1, :), accelRoots(it))
        polyval(currentCoefficients(2, :), accelRoots(it))
        polyval(currentCoefficients(3, :), accelRoots(it))
    end
end


end

