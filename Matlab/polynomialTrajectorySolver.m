function [C] = polynomialTrajectorySolver(X, tf)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
%   This will solve for the coefficients of a constrained 9 order
%   polynomial

%declare ti as zero
ti = 0;

%create the 10 x 10 matrix
A = [ti^9,        ti^8,         ti^7,         ti^6,         ti^5,       ti^4,     ti^3,   ti^2, ti, 1;
    9*ti^8,       8*ti^7,       7*ti^6,       6*ti^5,       5*ti^4,     4*ti^3,   3*ti^2, 2*ti, 1,  0;
    8*9*ti^7,     7*8*ti^6,     6*7*ti^5,     5*6*ti^4,     4*5*ti^3,   3*4*ti^2, 2*3*ti, 1,    0,  0;
    7*8*9*ti^6,   6*7*8*ti^5,   5*6*7*ti^4,   4*5*6*ti^3,   3*4*5*ti^2, 2*3*4*ti, 1,      0,    0,  0;
    6*7*8*9*ti^5, 5*6*7*8*ti^4, 4*5*6*7*ti^3, 3*4*5*6*ti^2, 2*3*4*5*ti, 1,        0,      0,    0,  0;
    tf^9,         tf^8,         tf^7,         tf^6,         tf^5,       tf^4,     tf^3,   tf^2, tf, 1;
    9*tf^8,       8*tf^7,       7*tf^6,       6*tf^5,       5*tf^4,     4*tf^3,   3*tf^2, 2*tf, 1,  0;
    8*9*tf^7,     7*8*tf^6,     6*7*tf^5,     5*6*tf^4,     4*5*tf^3,   3*4*tf^2, 2*3*tf, 1,    0,  0;
    7*8*9*tf^6,   6*7*8*tf^5,   5*6*7*tf^4,   4*5*6*tf^3,   3*4*5*tf^2, 2*3*4*tf, 1,      0,    0,  0;
    6*7*8*9*tf^5, 5*6*7*8*tf^4, 4*5*6*7*tf^3, 3*4*5*6*tf^2, 2*3*4*5*tf, 1,        0,      0,    0,  0;];

%create the row vector of for the answers to these equations
X = X';

%solve for the coefficient vector
C = inv(A)*X


end

