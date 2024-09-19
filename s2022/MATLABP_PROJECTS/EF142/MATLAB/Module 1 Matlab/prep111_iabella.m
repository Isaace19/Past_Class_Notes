clear;
clc;

%Calculate the Minimum distance the spring needs to be compressed needed to launch the car
%so that it will launch the car over the loop without falling off.
%Isaac Abella
cars = readtable('prep111_data.csv');

loopRadius = .96; % [m]
flatDistance = .62; % [m]
springStiffness = 1560; % [N/m]
g = 9.81; % [m/s^2]

%mass = .3; % [kg]
%friction = .84; % [N]


nCars = height(cars);   
prompt = sprintf("Which car do you want the solution for? (1-%d)", nCars);
idxCar = input(prompt);

cars.color = string(cars.color);
carColor = cars.color(idxCar);

%% First Calculations for Eloss, velocity, and height

loopHeight = 2*loopRadius;
peakLoopVelocity = sqrt(g*loopRadius);
Eloss = cars.friction*(flatDistance + pi*loopRadius);

%% Second Calculations for Kinetic Energy, Gravitational Potential Energy, 

kineticEnergy = 0.5*cars.mass*peakLoopVelocity^2;
ug2 = cars.mass * g * loopHeight;

%% Solution  

a =  0.5 * springStiffness;
b = -cars.friction;
c = -(kineticEnergy + ug2 + Eloss);

polySolution = [a b(idxCar) c(idxCar)];
deltaX = max(roots(polySolution));

%% Formatted Output

fprintf("The %s car needs to be pulled back %.1f cm", carColor, deltaX*100)


