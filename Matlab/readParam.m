function [ paramVal ] = readParam( fileName, paramName )
%READPARAM Summary of this function goes here
%   This function will read a file for the requested parameter. This will
%   be useful when you forget how your code works and need to tune it
%   written by Kevin Sheridan, for use under GPLv3
%   INSTRUCTIONS:
%   use: value = readParam('fileName.txt', 'parameterName')
%   A PARAMETER FILE EXAMPLE:
%       param1    #1.3567#    unit/explanation
%       param2    #-2.7896#   m/s (the speed of object X)
%       ...

%parse the data from txt file
t = readtable(fileName, 'Delimiter', '#', 'ReadVariableNames', false)
vals = table2array(t(:, 2));
vars = table2array(t(:, 1));

flag = 0;

for it = (1:1:length(vars))
    if strcmp(paramName, deblank(vars(it, 1)))
        paramVal = (vals(it, 1));
        flag = 1;
    end
end

if ~flag
    error('no matching parameter for parameter: %s', paramName);
end

end

