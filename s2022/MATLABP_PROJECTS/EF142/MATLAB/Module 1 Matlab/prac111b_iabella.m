% Calculating Work from a loaded data file.
%% Initialzie the Given Table

clc; clear;

runner = readtable("prac111_runners.csv");
runnersName = string(runner.name);
runnerTime = [runner.time_1 runner.time_2 runner.time_3 runner.time_4 runner.time_5];
distance = 100; % [m]

%% Calculations

averageRunnerTime = mean(runnerTime,2);
runners.averageRunnerTime = averageRunnerTime; % [kg]
velocity = distance ./ averageRunnerTime; % [m]
Work = .5 .* runner.mass .* velocity.^2; % [m/s^2]

runner.averageTime = (mean(runnerTime,2));
runner.Work = (.5 .* runner.mass .* velocity.^2);
%solving for time


disp(runner)



