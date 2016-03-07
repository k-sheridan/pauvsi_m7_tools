function [ p1, p2 ] = armPositionViaAngles( a, b, c, d, r1, r2, r3 )
%UNTITLED3 Summary of this function goes here
%   returns the positions of each joint of the arm using the current angles
%   the positions are ready to be input to the arrow3 function
% create the vectors    
v0 = [0, 0, 0]
v1 = [r1*sin(b)*cos(a), r1*sin(b)*sin(a), r1*cos(b)]
v2 = [r2*sin(b+c)*cos(a), r2*sin(b+c)*sin(a), r2*cos(b+c)]
v3 = [r3*sin(b+c+d)*cos(a), r3*sin(b+c+d)*sin(a), r3*cos(b+c+d)]

p1 = [v0; v0 + v1; v0 + v1 + v2]
p2 = [v1; v1 + v2; v1 + v2 + v3]

end

