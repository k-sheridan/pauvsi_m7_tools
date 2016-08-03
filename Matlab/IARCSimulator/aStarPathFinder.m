function [ waypoints ] = aStarPathFinder( field, startPos, goalPos )
%ASTARPATHFINDER Summary of this function goes here
%   calculates the waypoints to get to a goal position

%initialize vecs for a*
openList = aStarNode(startPos);
closedList = aStarNode(startPos);
goalFound = 0;

openList(length(openList)).f = 0;

%the a* loop
while ~isempty(openList) && ~goalFound
    %find the node with the least f on the open list, call it "q"
    candidateIndex = 1;
    for index = (1:1:length(openList))
        if openList(index).f < openList(candidateIndex).f
            candidateIndex = index;
        end
    end
    q = openList(candidateIndex);
    %pop q off the open list
    openList(candidateIndex) = [];
    %generate q's 8 successors and set their parents to q
    successors(1) = aStarNode([q.pos(1) + 1, q.pos(2) + 0], q.pos);
    successors(2) = aStarNode([q.pos(1) + -1, q.pos(2) + 0], q.pos);
    successors(3) = aStarNode([q.pos(1) + 0, q.pos(2) + 1], q.pos);
    successors(4) = aStarNode([q.pos(1) + 0, q.pos(2) + -1], q.pos);
    successors(5) = aStarNode([q.pos(1) + 1, q.pos(2) + 1], q.pos);
    successors(6) = aStarNode([q.pos(1) + 1, q.pos(2) + -1], q.pos);
    successors(7) = aStarNode([q.pos(1) + -1, q.pos(2) + -1], q.pos);
    successors(8) = aStarNode([q.pos(1) + -1, q.pos(2) + 1], q.pos);
    %for each successor
    for it = (1:1:8)
    	%if successor is the goal, stop the search
        if successors(it).pos == goalPos
            goalFound = 1;
            break;
        end
        %successor.g = q.g + distance between successor and q
        successors(it).g = q.g + 1;
        %successor.h = distance from goal to successor
        successors(it).h = abs(goalPos(1) - successors(it).pos(1)) + abs(goalPos(2) - successors(it).pos(2));
        successors(it).f = successors(it).g + successors(it).h;

        %if a node with the same position as successor is in the OPEN list \
            %which has a lower f than successor, skip this successor
        listFlag = 0;
        for it2 = (1:1:length(openList))
            if successors(it).pos == openList(it2).pos
                listFlag = 1;
                break;
            end
        end
        %if a node with the same position as successor is in the CLOSED list \ 
            %which has a lower f than successor, skip this successor
        if ~listFlag
            for it2 = (1:1:length(closedList))
                if successors(it).pos == closedList(it2).pos
                    listFlag = 1;
                break;
                end
            end
        end
        %otherwise, add the node to the open list
        if ~listFlag
            openList(length(openList) + 1) = successors(it);
        end
    end
    
    closedList(length(closedList) + 1) = q;
end
size(closedList)
waypoints = closedList.pos;

end

