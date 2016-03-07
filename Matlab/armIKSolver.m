function armIKSolver(x, y, z)
%armIKSolver Summary of this function goes here
%   solves for the angles of servos given a requested final tip position

%create the arm bone lengths in meters
r1 = .1;
r2 = .2;
r3 = .1;

%create the starting angles and give them default variables in radians +
%pos
a = pi/4;
b = pi/4;
c = pi/4;
d = pi/4;
%xCurr = 0;
%yCurr = 0;
%zCurr = r1+r2+r3;
[p1, p2] = armPositionViaAngles(a, b, c, d, r1, r2, r3);
xCurr = p2(3, 1);
yCurr = p2(3, 2);
zCurr = p2(3, 3);

%solve for angles
a = atan2(y, x);

%create the deltaP vec
deltaP = [x - xCurr, y - yCurr, z - zCurr];

%this is the relative x y position that we are tring to solve for
ik_x = sqrt(x^2+y^2)
ik_z = z

%calculate the ik_deltaP (relative change in x y we are solving for)
ik_deltaP = [deltaP(3), sqrt(deltaP(1)^2 + deltaP(2)^2)]
%ik_deltaP = [-0.2, -0.3]

%create the Jacobian matrix
J = [(r1*cos(b)+r2*cos(b+c)+r3*cos(b+c+d)), (r2*cos(b+c)+r3*cos(b+c+d)), (r3*cos(b+c+d));
    -(r1*sin(b)+r2*sin(b+c)+r3*sin(b+c+d)), -(r2*sin(b+c)+r3*sin(b+c+d)), -(r3*sin(b+c+d))];


%solve for deltaTheta using the singular value decomposed jacobian the pinv
%function does this
deltaTheta = pinv(J) * ik_deltaP'

% update the angles of the virtual arm
b = b + deltaTheta(1);
c = c + deltaTheta(2);
d = d + deltaTheta(3);

%compute positions and draw
[p1, p2] = armPositionViaAngles(a, b, c, d, r1, r2, r3);

daspect([0.25 0.25 0.25])
axis([-0.5 0.5 -0.5 0.5 -0.5 0.5])
hold on
arrow3(p1, p2, 'b', 0.9)
hold off


end

