function [] = drawSimulation(roombas, obstacles, quadcopter)
%drawSim Summary of this function goes here
% The purpose of this function is too actually draw the field and GUI and
% report back vital GUI related information
%   roombas: 1X10 Vector of roombas
%begin drawing
cla
%create gorund markings
hold on
axis([-11 11 -11 11 0 10]); % setup axes
plot3([-10, 10], [-10, -10], [0, 0], 'r')
plot3([-10, 10], [10, 10], [0, 0], 'g')
plot3([-10, -10], [-10, 10], [0, 0], 'k')
plot3([10, 10], [-10, 10], [0, 0], 'k')
plot3([0, 0], [-10, 10], [0, 0], 'k')
plot3([-10, 10], [0, 0], [0, 0], 'k')

%draw the quad
create3DQuad(quadcopter);

%draw roombas
for index = (1:1:length(roombas))
    if mod(index, 2)
        create3DRoomba(roombas(index), 'r');
    else
        create3DRoomba(roombas(index), 'g');
    end
end
%draw obstacles
for index = (1:1:length(obstacles))
    create3DRoomba(obstacles(index), 'b');
    Cylinder(obstacles(index).pos + [0, 0, 0.1], obstacles(index).pos + [0, 0, 2.1], 0.05, 5,  'b', 1, 0);
end

hold off
drawnow;

end

