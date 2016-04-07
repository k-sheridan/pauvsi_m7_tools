function [ X, Y, Z, C ] = create3DRoomba(roomba, color )
%CREATE3DROOMBA Summary of this function goes here
%   This creates a a 3d roomba 
Cylinder(roomba.pos, roomba.pos + [0, 0, 0.10], 0.2, 20, color, 1, 0);

end

