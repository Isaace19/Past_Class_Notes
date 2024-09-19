%% Initialize the Table and clear the workspace

% Isaac Abella
% B377

clear; clc;


data = readtable('prep202_data.csv');

%% Initialize Known values
A = 0.8; % [m^2] cross sectional area 
rho = 1.204; % [kg/m^3] mass-density of object

polymodel = polyfit(data.wind_speed, data.drag_force, 2);

p1 = polymodel(1);
Cd = 2*p1/(A * rho);

fprintf("The estimated drag coeffictient is: C_d = %.3f\n", Cd);


inputVelocity = input("Enter a velocity in [m/s]: ");

%% now generate a model given this input for the polynomial

Fdhat = polyval(polymodel, inputVelocity, 2);

fprintf("For velocity of %.1f m/s, the drag force is: %.3g N", inputVelocity, Fdhat);