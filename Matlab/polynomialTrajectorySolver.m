function [C] = polynomialTrajectorySolver(X, Y, Z, tf)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
%   This will solve for the coefficients of a constrained 9 order
%   polynomial

%declare ti as zero
ti = 0;

A = get9DegPolyMatrix(ti, tf);

%solve for the coefficient matrix
C = zeros(3, 10);
C(1, :) = inv(A)*X';
C(2, :) = inv(A)*Y';
C(3, :) = inv(A)*Z';

%now that we have the Coefficient matrix run the calculate Actuator
%feasibility function
calculateActuatorFeasibility(C, 5, [1, 1, 1]', 10, 100, tf)


end

