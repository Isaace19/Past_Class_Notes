clear; clc;

% Name: Isaac Abella
% Program Description: Takes distance from the rubber band lab and
% organizes them in readable graphs

%% LAB 2-8 Plotting and Saving Graphs

FitData = readtable("lab202_fitdata_B337(8).csv",'PreserveVariableNames',true);
EvalData = readtable("lab202_evaldata_377_8.csv",'PreserveVariableNames',true);

%% Start Working with known values

FitmyData = FitData.Distnace;
FittingTheData = FitData.DeltaX;

PredictedShot = EvalData.("predicted distance (d1) [in]");
MeasuredShot = EvalData.("measured distance (d1) [in]");
StretchBack = EvalData.("stretch distance (deltaX) [in]");

%% Confidence Interval

x = StretchBack;
y = PredictedShot;

[p,S] = polyfit(x,y,1);
[y_fit, delta] = polyval(p,x,S);

%% Creating Graph

fig1 = figure(1); clf
hold on

x = StretchBack;
y1 = PredictedShot;
y2 = MeasuredShot;
y3 = FittingTheData;

%Predicted Data
plot(x,y1, "-o", 'DisplayName', "Distance Predictions");

%Measured Data
plot(x,y2, "*", 'DisplayName', "Distance Measured");

%Fitted Data
plot(x,y3, "-", 'DisplayName', "Distance Fitted")

plot(x,y_fit, 'r');
plot(x,y_fit+2*delta, 'm--', x,y_fit-2*delta, 'm--');
title("Linear Fit Calculations");
legend('Data','Linear Fit', '95% interval');

hold off


xlabel("Distance Stretched[in]");
ylabel("Distance Traveled [in]")    
title("Distance Estimations");
legend();

saveas(fig1, 'Rubber_Band_Lab.png')