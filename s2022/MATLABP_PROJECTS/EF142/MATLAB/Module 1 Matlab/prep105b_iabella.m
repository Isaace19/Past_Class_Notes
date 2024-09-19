% Calculating the work done on objects with a known mass on a surface 

%Name = Isaac Abella
%Section = B377

clear; clc;
%% 

%Initialize our known variables

load prep108_data.mat

%mass = 100; % Mass in KG 
%mu_k = 0.3; % Coefficient of Kinetic Friction


pushForce = input("What is the force [n] on each object? ");
distance = input("What is the distance [m] on each object? ");
%pushForce = 1500; % Force in Newtons
%distance = 5; % meters pushed
%% 

g = 9.81; % gravity in m/s^2

% Calculations

weight = mass * g; % In Newtons

forceOfFriction = weight.*mu_k; % In Newtons

netForce = pushForce - forceOfFriction; % In Newtons

work = netForce*distance; % Newton-meters or Joules

%%Output%%
[nRows, nCols] = size(name);
nObjects = length(name);
fprintf("%d objects were analyzed.\n ", nCols);

[maxWork, imaxWork] = max(work);
objectName = name(imaxWork);

fprintf("%s had the most worked performed with %.2f n-m \n", objectName, maxWork);


