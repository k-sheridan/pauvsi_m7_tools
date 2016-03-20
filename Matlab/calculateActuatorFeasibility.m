function [Error] = calculateActuatorFeasibility(Coefficients, Mass, Moment, MaxVel, MinZForce, MaxForce, MaxAngle, tf)
%UNTITLED4 Summary of this function goes here
%   This function will test a given set of polynomials to see if they fit
%   within the actuator constraints specified
%   ESSENTIALLY
%   Coefficients: a 3X10 Matrix of coefficients
%   Mass
%   Moment - moment vector
%   tf: the final time
%MinZForce = the minumum force in the z direction typlically gravity (-45)

%the simulated delta t which determines the extent of the Moment requested
% angular acceleration = the limit as dt -> 0 with respect to angular
% veocity
delta_t = 0.0001;
%this is the gain that is used to calculate the forces each motor must
%produce
Kd = 1;
%the distance of each motor from the center of mass
d = 0.4;
%coefficient of drag related to yaw drag
c = 0;
%gravity
g = 9.81;
%create the moment matrix
J = [Moment(1), 0,         0;
            0,          Moment(2), 0;
            0,          0,         Moment(3)];

% Find the maximum accelerations
[maxima, foundRoots] = calculateMaximums(Coefficients, 2, tf);

%create the fTot
[~, c] = size(foundRoots);
f_total = zeros(3, c);
%now test whether these maximums are within feasible limits
for it = (1:length(foundRoots))
    %calculate the magnitude of the acceleration gravity while taking into
    %account mass and gravity
    %mag is the [0, 0, 0, F_Total]' vector of the quadrotor. It must not
    %exceed the maximum possible acceleration
    f_total(1:3, it) = Mass * (maxima(:, it) + [0; 0; g]);
    if norm(f_total(:, it)) > MaxForce || f_total(3, it) <= MinZForce
        fprintf('FORCE TOO HIGH\n');
        Error = 1;
        return
    end
end

%now use a lot of physics and math to calculate the force each motor must
%be exerting at each point

%start by declaring the variables
%inertial frame force vector
Fi = zeros(3, length(foundRoots));
Fi(1, :) = Mass * (polyval(polyder(polyder(Coefficients(1, :))), foundRoots));
Fi(2, :) = Mass * (polyval(polyder(polyder(Coefficients(2, :))), foundRoots));
% add g to the 
Fi(3, :) = Mass * (polyval(polyder(polyder(Coefficients(3, :))), foundRoots) + (g * ones(1, length(foundRoots))));

% create the first derivative of force vector
Fi_prime = zeros(3, length(foundRoots));
Fi_prime(1, :) = Mass * (polyval(polyder(polyder(polyder(Coefficients(1, :)))), foundRoots));
Fi_prime(2, :) = Mass * (polyval(polyder(polyder(polyder(Coefficients(2, :)))), foundRoots));
Fi_prime(3, :) = Mass * (polyval(polyder(polyder(polyder(Coefficients(3, :)))), foundRoots));

%calculate the desired omega vector
Omega_desired = zeros(3, length(foundRoots));
%create the bar vector of Fi
Fi_bar = zeros(3, length(foundRoots));
for it = (1:1:length(foundRoots))
    mag = norm(Fi(:, it));
    Fi_bar(:, it) = Fi(:, it) / mag;
    
    %the omega desired calc
    Omega_desired(:, it) = cross(Fi_bar(:, it), Fi_prime(:, it));
    %set the z moment to zero
    Omega_desired(3, it) = 0;
end

% now we have to calculate the current omega based on the omega we should
% have been flying at delta_t seconds ago
lastT = foundRoots - (ones(1, length(foundRoots)) * delta_t);

Fi_last = zeros(3, length(foundRoots));
Fi_last(1, :) = Mass * (polyval(polyder(polyder(Coefficients(1, :))), lastT));
Fi_last(2, :) = Mass * (polyval(polyder(polyder(Coefficients(2, :))), lastT));
% add g to the 
Fi_last(3, :) = Mass * (polyval(polyder(polyder(Coefficients(3, :))), lastT) + (g * ones(1, length(foundRoots))));

% create the first derivative of force vector
Fi_prime_last = zeros(3, length(foundRoots));
Fi_prime_last(1, :) = Mass * (polyval(polyder(polyder(polyder(Coefficients(1, :)))), lastT));
Fi_prime_last(2, :) = Mass * (polyval(polyder(polyder(polyder(Coefficients(2, :)))), lastT));
Fi_prime_last(3, :) = Mass * (polyval(polyder(polyder(polyder(Coefficients(3, :)))), lastT));

%calculate the desired omega vector
Omega_current = zeros(3, length(foundRoots));
%create the bar vector of Fi
Fi_bar_last = zeros(3, length(foundRoots));
for it = (1:1:length(foundRoots))
    mag = norm(Fi_last(:, it));
    Fi_bar_last(:, it) = Fi_last(:, it) / mag;
    
    %the omega desired calc
    Omega_current(:, it) = cross(Fi_bar_last(:, it), Fi_prime_last(:, it));
    %set the z moment to zero
    Omega_current(3, it) = 0;
end

%FINALLY! now that we have the desired omega and the simulated current
%omega, we can calcuate the exact forces that each motor must produce at a
%given time(the maximum accelerations along a polynomial)

Mb = -Kd * (Omega_current - Omega_desired);

motorForces = zeros(4, length(Mb));

torqueMat = [1, 1,  1,  1;
             d, 0, -d,  0;
             0, d,  0, -d;
            -c, c, -c,  c];
        
for it = (1:1:length(foundRoots))
    motorForces(:, it) = torqueMat \ [norm(f_total(:, it)); Mb(1, it); Mb(2, it); Mb(3, it)];
    
    % while in the for loop check to see if the forces are within the
    % bounds
    
    if any(motorForces(:, it) <= 1) || any(motorForces(:, it) >= MaxForce / 4)
        fprintf('INDIVIDUAL MOTOR FORCE TOO HIGH\n');
        Error = 1;
        return;
    end    
end
motorForces

%IF YOU HAVE NOT RETURNED BY THIS POINT THE TRAJECTORY IS WITHIN FEASIBLE
%LIMITS
Error = -1;
return;

end

