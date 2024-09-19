% Calculate the work done on several objects pushed across a surface for a
% known distance. Mass of each object and coefficients of friction between
% each object and the surface are known. The user-provided push force is
% applied to each object.

% Name:
% Section:

clear; clc;

objects = readtable('lab111_data.csv');
nObjects = height(objects); % the number of rows is the number of objects
objects.name = string(objects.name);

%% Initialize known and given variables
g = 9.81;   % [m/s^2] acceleration due to gravity
h = 5;      % height of ramp
theta = 15; % ramp angle in degrees, use cosd() and sind()

%% User Input
pushForce = input("Enter the push force [N]: ");  % push force

%% Calculations
% Calculations derived by applying conservation of
% energy and solving for the distance d1

% save some typing by assigning column names to shorter 
% variables
m = objects.mass;
mu = objects.mu_k;

% E_loss
% we need weight and d2 (distance along ramp) to compute
d2 = h/sind(theta);
weight = m .* g;
E_loss = mu .* weight .* (cosd(theta)*d2);

% Gravitational potential energy at the top of the ramp
Ugf = m.*(g*h);

% because object is moving on horizontal surface
% normal force is equal to weight from FBD=KD
frictionForce = weight .* mu;

% Net horizonal force acting on the object
Fnet = pushForce - frictionForce;

% The distance [m] needed to push the object
d1 = (Ugf + E_loss)./Fnet;
objects.d1 = d1;

%% Output

fprintf("For a push force of %.3g N:\n", pushForce);
objectsThatMoved(objects.d1 > 0, :);

objectsThatDidNotMove = objects(objects.d1 <= 0, :);