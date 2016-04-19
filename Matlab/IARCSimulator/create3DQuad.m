function create3DQuad(quadcopter)
%This will create the 3D quadrotor using plot3

baseColor = 'b';
baseLineWidth = 3;
armColor = 'b';

hold on
% create the base of the quad
%BOTTOM SIDE
points = zeros(3, 2);
points(1:3, 1) = [-0.07, -0.07, -0.04]';
points(1:3, 2) = [0.07, -0.07, -0.04]';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)')
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(3, :), points(3, :), baseColor);
p.LineWidth = baseLineWidth;

%nextline
points = zeros(3, 2);
points(1:3, 1) = [-0.07, 0.07, -0.04]';
points(1:3, 2) = [0.07, 0.07, -0.04]';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)')
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(3, :), points(3, :), baseColor);
p.LineWidth = baseLineWidth;

%nextline
points = zeros(3, 2);
points(1:3, 1) = [-0.07, -0.07, -0.04]';
points(1:3, 2) = [-0.07, 0.07, -0.04]';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)')
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(3, :), points(3, :), baseColor);
p.LineWidth = baseLineWidth;

%nextline
points = zeros(3, 2);
points(1:3, 1) = [0.07, -0.07, -0.04]';
points(1:3, 2) = [0.07, 0.07, -0.04]';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)')
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(3, :), points(3, :), baseColor);
p.LineWidth = baseLineWidth;

end

