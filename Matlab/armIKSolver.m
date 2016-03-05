function armIKSolver(x, y, z)
%armIKSolver Summary of this function goes here
%   solves for the angles of servos given a requested final tip position

%create the arm bone lengths in meters
r1 = .1;
r2 = .2;
r3 = .1;

%create the angles and give them default variables in radians
a = 0;
b = 0;
c = 0;
d = 0;

%solve for angles
a = asin(x / sqrt(x^2 + y^2))
T = [asin(r1*cos(a)), asin(r2*cos(a)), asin(r3*cos(a));
     asin(r1*sin(a)), asin(r2*sin(a)), asin(r3*sin(a));
     acos(r1),        acos(r2),        acos(r3)];
P = [asin(x), asin(y), asin(z)]';

ANG = inv(T)*P

% create the vectors    
v0 = [0, 0, 0]
v1 = [r1*sin(b)*cos(a), r1*sin(b)*sin(a), r1*cos(b)]
v2 = [r2*sin(b+c)*cos(a), r2*sin(b+c)*sin(a), r2*cos(b+c)]
v3 = [r3*sin(b+c+d)*cos(a), r3*sin(b+c+d)*sin(a), r3*cos(b+c+d)]

p1 = [v0; v0 + v1; v0 + v1 + v2]
p2 = [v1; v1 + v2; v1 + v2 + v3]

%p1 = [v0; v0; v0]
%p2 = [v1; v2; v3]

daspect([0.25 0.25 0.25])
axis([-0.5 0.5 -0.5 0.5 -0.5 0.5])
hold on
arrow3(p1, p2, 'b', 0.9)
hold off


end

