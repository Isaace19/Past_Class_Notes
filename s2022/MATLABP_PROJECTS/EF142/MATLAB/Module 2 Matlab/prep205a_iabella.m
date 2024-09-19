% Calculate the power needed to hoist several objects a known height
% from the ground. All masses are known. User provides the time it takes
% to hoist each object

% Name: Reference
% Section ID: All

clear; clc;

%% Initialize Knowns

% load data
% load `mass` containing mass of each box
% and `name` containing the name of each box
load("prac108_data.mat")
nObjects = length(mass);

liftHeight = 1.5; % [m] that all objects are hoisted to
g = 9.81;          % [m/s^2] acceleration due to gravity


%% User Input

time = input("Enter the times for all objects as an array: ");
if any(time < 0) 
    error("Error, invalid time");
end
% valid: [3 5 15 10 2.5]
% too few:  [3 5 15 10]
% too many: [3 5 15 10 2.5 6]
% negative values [3 5 15 -10 2.5]

%% Calculations

weight = mass*g; % [N] of all objects
tension = weight; % [N] 
work = liftHeight*tension; % [N-m]

power = work./time; % [W]


%% Output

[maxPower, idxMaxPower] = max(power);
objectName = name(idxMaxPower);

fprintf("The most power of %.0f Watts was needed to lift the %s %.2f meters in 5.00 seconds\n", maxPower, objectName, liftHeight);

