clear; clc

%% Create Known values

data = readtable("exam2_fitData.csv");

x = polyfit(data.speed, data.drag_force, 2);

% using different wind speeds

%dummy = input("Select a wind speed between 14ft/s - 144ft/s: ");
%windspeed = dummy;


modelfit = polyval(x, data.speed);

fig1 = figure(1); clf

hold on
plot(modelfit, data.speed, 'DisplayName', "Speed");
hold off

xlabel("Wind Speed");
ylabel("Generated Values");
legend();

