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
        function obj = aStarNode(pos)
            obj.pos = pos;
        end
    end
    
end

