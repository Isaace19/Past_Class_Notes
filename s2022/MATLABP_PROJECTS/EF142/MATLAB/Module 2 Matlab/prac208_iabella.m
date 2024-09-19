%% Practice 208
clear; clc;
%% DESCRIPTION
% NAME: ISAAC ABELLA
% PROGRAM DESCRIPTION: Visualize the data relationship from gathered data
% of a ball in freefall with recorded values

%% Initialize Known Values

ballData = readtable("prac208_data.csv", 'VariableNamingRule', 'preserve');

ballData.Properties.VariableNames = ["time", "weight", "F_d", "F_net", "v_y"];

%% Now we can create the tables for these data types 

x = ballData.time;
y1 = ballData.F_net;
y2 = ballData.v_y;
y3 = ballData.F_d;

fig1 = figure(1); clf
hold on
plot(x,y2, 'o');
hold off

ylabel("Velocity [m/s]");
xlabel("Time [s]");
sgtitle("Ball in Freefall")
legend()

fig2 = figure(2);

hold on
plot(x,y3, '+', 'DisplayName', "Drag");

plot(x,y1, '-', 'DisplayName', "Net");

plot(ballData.weight, 'DisplayName', "Weight");
hold off
sgtitle("Ball in Freefall");
ylabel("Force [N]");
xlabel("Time, [s]");
legend();
