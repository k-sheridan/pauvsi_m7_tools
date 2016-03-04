function polynomialTrajectorySolver(xi_0, xi_1, xi_2, xi_3, xi_4, xf_0, xf_1, xf_2, xf_3, xf_4, tf)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
%   This will solve for the coefficients of a constrained 9 order
%   polynomial

%declare ti as zero
ti = 0;

%create the 10 x 10 matrix
A = [ti^9, ti^8, ti^7, ti^6, ti^5, ti^4, ti^3, ti^2, ti, 1;
    9*ti^8, 8*ti^7, 7*ti^6, 6*ti^5, 5*ti^4, 4*ti^3, 3*ti^2, 2*ti, 1, 0]

end

