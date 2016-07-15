function [ paramVal ] = readParam( fileName, paramName )
%READPARAM Summary of this function goes here
%   This function will read a file for the requested parameter. This will
%   be useful when I forget how this code works and need to modify its
%   function
%   written by Kevin Sheridan, for use under GPLv3
t = readtable(fileName, 'Delimiter', '-', 'ReadVariableNames', false)
vals = table2array(t(:, 2))
vars = table2array(t(:, 1))

flag = 0;

for it = (1:1:length(vars))
    if strcmp(paramName, deblank(vars(it, 1)))
        paramVal = vals(it, 1);
        flag = 1;
    end
end

if ~flag
    error('no matching parameter for %s', paramName);
end

end

