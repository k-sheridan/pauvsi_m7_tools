function armIKSolver(x, y, z)
%armIKSolver Summary of this function goes here
%   solves for the angles of servos given a requested final tip position

%create the arm bone lengths in meters
r1 = .1;
r2 = .2;
r3 = .1;

%create the starting angles and give them default variables in radians +
%pos
a = 0;
b = 0;
c = 0;
d = 0;
xCurr = 0
yCurr = 0
zCurr = r1+r2+r3

%solve for angles
a = asin(x / sqrt(x^2 + y^2));

%create the deltaP vec
deltaP = [x - xCurr, y - yCurr, z - zCurr];

%this is the relative x y position that we are tring to solve for
ik_x = sqrt(x^2+y^2);
ik_z = z;

%calculate the ik_deltaP (relative change in x y we are solving for)
ik_deltaP = [sqrt(deltaP(1)^2 + deltaP(2)^2), deltaP(3)];

%create the Jacobian matrix
J = [(r1*cos(b)+r2*cos(b+c)+r3*cos(b+c+d)), (r2*cos(b+c)+r3*cos(b+c+d)), (r3*cos(b+c+d));
    -(r1*sin(b)+r2*sin(b+c)+r3*sin(b+c+d)), -(r2*sin(b+c)+r3*sin(b+c+d)), -(r3*sin(b+c+d))]

%solve for deltaTheta
%deltaTheta = svd(J) * ik_deltaP;

%compute positions and draw
[p1, p2] = armPositionViaAngles(a, b, c, d, r1, r2, r3);

daspect([0.25 0.25 0.25])
axis([-0.5 0.5 -0.5 0.5 -0.5 0.5])
hold on
arrow3(p1, p2, 'b', 0.9)
hold off


end

