% Making a MATLAB program that calculates the time and power input of
% an array of numbers to 3 significant figure
clear
clc

load runners_short.mat;

% Initialize Known Values 

gravity = 9.81; % in m/s^2

distance = input("Enter the Distance (m) of the race: ");
time = input("Enter the finish time (s) for each runner as a single array: ");

velocity = distance ./ time;
work = (.5) .* mass .* (velocity.^2);

power = work./time;

% Output section

[powerMax, indexPos] = max(power);

maxName = name(indexPos);
timeMax = time(indexPos);   

fprintf("%s produced the most power of %#.1f W and finished the race in  %.3f seconds. \n", maxName, powerMax, timeMax);