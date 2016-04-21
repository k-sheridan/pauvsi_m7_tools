function create3DQuad(quadcopter)
%This will create the 3D quadrotor using plot3

baseColor = 'k';
baseLineWidth = 1;
armColor = 'r';
armLineWidth = 2;

% create the base of the quad
%hold on
%BOTTOM SIDE
points = zeros(3, 2);
points(1:3, 1) = [-0.07, -0.07, -0.04]';
points(1:3, 2) = [0.07, -0.07, -0.04]';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = baseLineWidth;

%nextline
points = zeros(3, 2);
points(1:3, 1) = [-0.07, 0.07, -0.04]';
points(1:3, 2) = [0.07, 0.07, -0.04]';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = baseLineWidth;

%nextline
points = zeros(3, 2);
points(1:3, 1) = [-0.07, -0.07, -0.04]';
points(1:3, 2) = [-0.07, 0.07, -0.04]';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = baseLineWidth;

%nextline
points = zeros(3, 2);
points(1:3, 1) = [0.07, -0.07, -0.04]';
points(1:3, 2) = [0.07, 0.07, -0.04]';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = baseLineWidth;

%TOP SIDE
points = zeros(3, 2);
points(1:3, 1) = [-0.07, -0.07, 0.04]';
points(1:3, 2) = [0.07, -0.07, 0.04]';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = baseLineWidth;

%nextline
points = zeros(3, 2);
points(1:3, 1) = [-0.07, 0.07, 0.04]';
points(1:3, 2) = [0.07, 0.07, 0.04]';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = baseLineWidth;

%nextline
points = zeros(3, 2);
points(1:3, 1) = [-0.07, -0.07, 0.04]';
points(1:3, 2) = [-0.07, 0.07, 0.04]';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = baseLineWidth;

%nextline
points = zeros(3, 2);
points(1:3, 1) = [0.07, -0.07, 0.04]';
points(1:3, 2) = [0.07, 0.07, 0.04]';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = baseLineWidth;


%CREATE THE ARMS
drawArm([0.07, 0.07, 0], 0.31, 0.02, [1, 1, 0], quadcopter, quadcopter.motorForces(1), armColor, baseColor, armLineWidth, baseLineWidth);
drawArm([0.07, -0.07, 0], 0.31, 0.02, [1, -1, 0], quadcopter, quadcopter.motorForces(2), armColor, baseColor, armLineWidth, baseLineWidth);
drawArm([-0.07, -0.07, 0], 0.31, 0.02, [-1, -1, 0], quadcopter, quadcopter.motorForces(3), armColor, baseColor, armLineWidth, baseLineWidth);
drawArm([-0.07, 0.07, 0], 0.31, 0.02, [-1, 1, 0], quadcopter, quadcopter.motorForces(4), armColor, baseColor, armLineWidth, baseLineWidth);


end

function drawArm(base, length, thickness, dir, quadcopter, motorForce, armColor, baseColor, armLineWidth, baseLineWidth)
sqrt2 = sqrt(2); %sqrt(2)

points = zeros(3, 2);
points(1:3, 1) = [base(1) + (thickness * dir(1) * -1), base(2), base(3) + thickness]';
points(1:3, 2) = (points(1:3, 1) + [dir(1) * length / sqrt2; dir(2) * length / sqrt2; 0])';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), armColor);
p.LineWidth = armLineWidth;

points(1:3, 1) = [base(1), base(2) + (thickness * dir(2) * -1), base(3) + thickness]';
points(1:3, 2) = (points(1:3, 1) + [dir(1) * length / sqrt2; dir(2) * length / sqrt2; 0])';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), armColor);
p.LineWidth = armLineWidth;
points(1:3, 1) = [base(1) + (thickness * dir(1) * -1), base(2), base(3) - thickness]';
points(1:3, 2) = (points(1:3, 1) + [dir(1) * length / sqrt2; dir(2) * length / sqrt2; 0])';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), armColor);
p.LineWidth = armLineWidth;

points(1:3, 1) = [base(1), base(2) + (thickness * dir(2) * -1), base(3) - thickness]';
points(1:3, 2) = (points(1:3, 1) + [dir(1) * length / sqrt2; dir(2) * length / sqrt2; 0])';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), armColor);
p.LineWidth = armLineWidth;

%draw base connects
points(1:3, 1) = [base(1) + (thickness * dir(1) * -1), base(2), base(3) + 0.04]';
points(1:3, 2) = (points(1:3, 1) + [0; 0; -0.08])';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = armLineWidth;

points(1:3, 1) = [base(1), base(2) + (thickness * dir(2) * -1), base(3) + 0.04]';
points(1:3, 2) = (points(1:3, 1) + [0; 0; -0.08])';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = armLineWidth;

%draw end points
points(1:3, 1) = [base(1) + (thickness * dir(1) * -1), base(2), base(3) + thickness]';
points(1:3, 1) = (points(1:3, 1) + [dir(1) * length / sqrt2; dir(2) * length / sqrt2; 0])';
points(1:3, 2) = (points(1:3, 1) + [(thickness * dir(1)); (thickness * dir(2)) * -1; 0])';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = armLineWidth;

points(1:3, 1) = [base(1) + (thickness * dir(1) * -1), base(2), base(3) - thickness]';
points(1:3, 1) = (points(1:3, 1) + [dir(1) * length / sqrt2; dir(2) * length / sqrt2; 0])';
points(1:3, 2) = (points(1:3, 1) + [(thickness * dir(1)); (thickness * dir(2)) * -1; 0])';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = armLineWidth;

points(1:3, 1) = [base(1) + (thickness * dir(1) * -1), base(2), base(3) - thickness]';
points(1:3, 1) = (points(1:3, 1) + [dir(1) * length / sqrt2; dir(2) * length / sqrt2; 0])';
points(1:3, 2) = (points(1:3, 1) + [0; 0; thickness * 2])';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = armLineWidth;

points(1:3, 1) = [base(1), base(2) + (thickness * dir(2) * -1), base(3) - thickness]';
points(1:3, 1) = (points(1:3, 1) + [dir(1) * length / sqrt2; dir(2) * length / sqrt2; 0])';
points(1:3, 2) = (points(1:3, 1) + [0; 0; thickness * 2])';
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = armLineWidth;

%DRAW FORCE
points(1:3, 1) = [base(1), base(2), base(3) + thickness]';
points(1:3, 1) = (points(1:3, 1) + [dir(1) * length / sqrt2; dir(2) * length / sqrt2; 0])';
points(1:3, 2) = (points(1:3, 1) + [0; 0; -motorForce / 25])'; % divide by 25 to shrink
%rotate the points
points(1:3, 1) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 1)');
points(1:3, 2) = quadcopter.pos + quatrotate(quadcopter.angleQuat, points(1:3, 2)');
p = plot3(points(1, :), points(2, :), points(3, :), baseColor);
p.LineWidth = baseLineWidth;

end
