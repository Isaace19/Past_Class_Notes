clear;
clc;

% Team: B377 (4)

% Program Description: Program that calculations distance given an object
% in the data file that must be pushed to a desired height.

%% initialize known values and CSV FILE
table = readtable("lab111_data.csv");
userInput = input("enter the index number of the object to print results for: (1-5)");

%% Known values 


h = 5; % [m]
theta = 15; % [deg]
P = 1500; % [N]
g = 9.81;

obj = table.name(userInput); % [string of the table]
m = table.mass(userInput); % [kg]
mu_k = table.mu_k(userInput); % [coefficient of friction kinetic]
w = m * g;

%% First Calculations
N = w*cosd(theta);

FrictionFlat = w * mu_k;
FrictionIncline = N .* mu_k;

UGF = m.*(g*h);
NetForce = P - (w.*mu_k);


%% Second Calculations

DistanceIncline = h/sind(theta);
Eloss = DistanceIncline*FrictionIncline;
distance = (UGF + Eloss)./NetForce;

%% Output

fprintf("With an applied force of 1500.00 N, the %s will have to be pushed for %.1f meters", obj{:}, distance);
