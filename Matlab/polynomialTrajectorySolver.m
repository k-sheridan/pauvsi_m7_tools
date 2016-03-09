function [C, tf] = polynomialTrajectorySolver(X, Y, Z)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
%   This will solve for the coefficients of a constrained 9 order
%   polynomial
%the number of iterations
ITERATIONS = 15;

%declare ti as zero
ti = 0;
%this is a ball park estimate of tf for starting
%in the future it should take into account the distance
tf = 10;

%create variables for newton's method
t_start = ti;
t_end = tf * 2;
t_mid = tf;
Error = 0;

for it = (1:1:ITERATIONS)
    A = get9DegPolyMatrix(ti, t_mid);
    
    %solve for the coefficient matrix
    C = zeros(3, 10);
    C(1, :) = inv(A)*X';
    C(2, :) = inv(A)*Y';
    C(3, :) = inv(A)*Z';
    
    %now that we have the Coefficient matrix run the calculate Actuator
    %feasibility function
    Error = calculateActuatorFeasibility(C, 5, [1, 1, 1]', 10, 100, pi/6, t_mid);
    
    % reasses the bounding points of the newton's method variables
    if Error == 1
        t_start = t_mid;
        t_mid = (t_mid + t_end) / 2;
    else
        t_end = t_mid;
        t_mid = (t_mid + t_start) / 2;
    end
end
%set the tf to the answer
if Error == 1
    tf = t_end
else
    tf = t_mid
end

%recalculate the Coefficient matrix one last time
A = get9DegPolyMatrix(ti, tf);
%solve for the coefficient matrix
C = zeros(3, 10);
C(1, :) = inv(A)*X';
C(2, :) = inv(A)*Y';
C(3, :) = inv(A)*Z';

end

