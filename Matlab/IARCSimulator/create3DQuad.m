function create3DQuad(quad)
%This will create the 3D quadrotor using plot3

quadX = quad.pos(1);
quadY = quad.pos(2);
quadZ = quad.pos(3);

X = [quadX - 0.03, quadX + 0.03];
Y = [quadY - 0.03, quadY - 0.03];
Z = [quadZ - 0.05, quadZ - 0.05];

plot3(X, Y, Z);
end

