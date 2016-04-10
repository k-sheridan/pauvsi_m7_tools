function [] = drawSimulation(roombas)
%drawSim Summary of this function goes here
% The purpose of this function is too actually draw the field and GUI and
% report back vital GUI related information
%   roombas: 1X10 Vector of roombas
%begin drawing
cla
%create gorund markings
hold on
plot3([-10, 10], [-10, -10], [0, 0], 'r')
plot3([-10, 10], [10, 10], [0, 0], 'g')
plot3([-10, -10], [-10, 10], [0, 0], 'k')
plot3([10, 10], [-10, 10], [0, 0], 'k')
plot3([0, 0], [-10, 10], [0, 0], 'k')
plot3([-10, 10], [0, 0], [0, 0], 'k')
%draw roombas
for index = (1:1:length(roombas))
    if index > 5
        create3DRoomba(roombas(index), 'r');
    else
        create3DRoomba(roombas(index), 'g');
    end
end

axis([-11 11 -11 11 0 5]); % setup axes
hold off
drawnow;

end

