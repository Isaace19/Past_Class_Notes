%%Clear and initialize known values into the polyfit function
clear; clc;

data = readtable('lab202_fitdata_B337(8).csv');

% just know that i called distance as distnace and don't wanna change it.
x = polyfit(data.DeltaX, data.Distnace, 2);


fprintf("Model Coefficients: %.3f\n", x);

%% ask for user input
pull_distance = input("How far back will you stretch the rubber band? [in]: \n");

pd = pull_distance;

%% Calculations
predictedDistance = polyval(x, pd);


%% Output

fprintf("The puck should stop at about %.3f in from the neutral position", predictedDistance);
