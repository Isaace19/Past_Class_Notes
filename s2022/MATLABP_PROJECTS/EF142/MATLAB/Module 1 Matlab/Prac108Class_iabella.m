% This program is made to calculate the poower required to lift several
% objects up a known distance in a known amount of time assuming constant
% acceleration

% Isaac Abella
% B377

%% 

% Initialize our known values

clear; clc;

load prac108_data.mat

g = 9.81; % in [m/s^2]
distance = 1.5; % in [m]
%% 

% Here be calculations
time = input("Enter the times for all objects: ");

weight = mass * g; % in [N]
tension = weight; % [N]

work = tension * distance; % [n]

% any value from the data folder can be called by indexing the array
power = work ./ time; % in [W]


%% 

% Final Output

max(power)
power(end -1)

