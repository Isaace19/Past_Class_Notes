clear; clc;

% Name: Isaac Abella
% Program that will display graph data based on data collected from cart
% lab.


%% Load the Data
data = readtable("cart_incline_energy.csv");

%% Create the actual display graphs

EnergyFigure = figure(1); clf
hold on
plot(data.time, data.kinetic_energy, '+' , 'DisplayName', "Kinetic Energy")
plot(data.time, data.gravitational_potential_energy, '.' , 'DisplayName', "Grav. Potential")
plot(data.time, data.total_mechanic_energy, "o", 'DisplayName', "Total Mechanic.")
hold off

xlabel("Time [s]")
ylabel("Energy [J]")
title("Energy Comparison")
legend()

%% Create Subplots for each data measured.

MotionFigure = figure(2); clf
sgtitle("Motion Comparison");

subplot(3,1,1);
plot(data.time, data.position, '.');
ylabel("Position, [m]");

subplot(3,1,2);
plot(data.time, data.velocity);
ylabel("Velocity, [m/s]");

subplot(3,1,3);
plot(data.time, data.acceleration);
ylabel("Acceleartion, [m/s^2]");
xlabel("Time [s]");

saveas(MotionFigure, 'motion_comparison_fig.png');
