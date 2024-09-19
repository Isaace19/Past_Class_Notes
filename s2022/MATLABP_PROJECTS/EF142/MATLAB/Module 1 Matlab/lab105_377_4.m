% This Program will calculate the work and power output of all runners that all 
% start from rest run the same distance, and all have a known 
% mass and finish time.

% Name - Isaac Abella
% Section - 377(4)
%% 

% Initialize Values

clear; clc;

load runners.mat
%% Creating Variables
G = 9.81; % m/s^2
Distance = 100; % meters
%% Calculations

Force = mass * G;

Work = (0.5.*mass).*(Distance./time).^2;

Power = Work./time;
%% Final Output

Power

Power(end -1)