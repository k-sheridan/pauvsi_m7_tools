classdef aStarNode
    %ASTARNODE Summary of this class goes here
    %   this is a node for the A* pathfinding algorithm
    
    properties
        parentPos
        pos
        f
        g
        h
    end
    
    methods
        function obj = aStarNode(pos, parentPos)
            if nargin == 1
                obj.pos = pos;
            elseif nargin == 2
                obj.pos = pos;
                obj.parentPos = parentPos;
            end
        end
    end
    
end

