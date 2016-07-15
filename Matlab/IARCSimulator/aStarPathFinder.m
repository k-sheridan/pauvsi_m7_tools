function [ waypoints ] = aStarPathFinder( field, startPos, goalPos )
%ASTARPATHFINDER Summary of this function goes here
%   calculates the waypoints to get to a goal position

%initialize vecs for a*
openList = aStarNode(startPos);
closedList;

openList(length(openList)).f = 0;

%the a* loop
while length(openList) ~= 0
    %find the node with the least f on the open list, call it "q"
    candidateIndex = 1;
    for index = (1:1:length(openList))
        
    end
    %pop q off the open list
    %generate q's 8 successors and set their parents to q
    %for each successor
    	%if successor is the goal, stop the search
        %successor.g = q.g + distance between successor and q
        %successor.h = distance from goal to successor
        %successor.f = successor.g + successor.h

        %if a node with the same position as successor is in the OPEN list \
            %which has a lower f than successor, skip this successor
        %if a node with the same position as successor is in the CLOSED list \ 
            %which has a lower f than successor, skip this successor
        %otherwise, add the node to the open list
end
end

