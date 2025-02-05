clear; clc;

% Initialize the Table Data

data = readtable('prac202_data.csv');
%% Print out the poly fit data of distance 1 & 2
polymodel = polyfit(data.deltaX, data.d1, 2);
fprintf("Model 1: %.3f, %.3f, %.3f\n", polymodel);

polymodel2 = polyfit(data.deltaX, data.d2, 2);
fprintf("Model 2: %.3f, %.3f, %.3f\n", polymodel2);

%% Ask for user input for a compression distance

cd = input("Enter a spring compression distance [m]: ");
compressionDistance = cd;

%% Calculations

PolyCalc1 = polyval(polymodel, compressionDistance);

uncompressed1 = PolyCalc1 - data.d1;

PolyCalc2 = polyval(polymodel2, compressionDistance);

uncompressed2 = PolyCalc2 - data.d2;



fprintf("Model 1 predicts that the puck will stop %.3f from the compressed position and %.3f from the uncompressed position\n", PolyCalc1, uncompressed1(1));
%fprintf("Model 2 predicts that the puck will stop %.3f from the compressed position and %.3f from the uncompressed position\n", PolyCalc2, uncompressed2(1));
