function create3DRoomba(roomba, color )
%CREATE3DROOMBA Summary of this function goes here
%   This creates a a 3d roomba 
Cylinder(roomba.pos, roomba.pos + [0, 0, 0.10], 0.2, 20, color, 1, 0);
%Cylinder([cos(roomba.yaw) * 0.25, sin(roomba.yaw) * 0.25, 0] + roomba.pos, [cos(roomba.yaw) * 0.25, sin(roomba.yaw) * 0.25, 0.1] + roomba.pos, 0.05, 10, 'b', 1, 0)

end

