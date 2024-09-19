clear; clc;

%% Unknown Variables
%FinalVelocity
%SpringDistance

%% Known Variables

InitialVelocity = 0; % [m/s]
DeveiceHeight = 10; % [cm]
PuckHeightFinal = 0; % [cm]

uk = .1; % note that our friction could be so low that it's negligible (verified by Dr. Mackza)
% Measurement Procedure: 
deviceMass = 50; %[g]
mEF = 15; % [g]
m = 12; % [g]
k = 4; % [spring constant N-m]

SpringConstant = 0; 
g = 9.81; % [m/s^2]

% Creating values of zones for each section of the table
Deadzone = 50;

% index of 1 is the x axis and the index of 2 is the y axis
Z1A = [12.5, 62.5];
Z1B = [37.5, 62.5];
Z1C = [62.5, 62.5];

Z2A = [12.5, 87.5];
Z2B = [37.5, 87.5];
Z2C = [62.5, 87.5];

Z3A = [12.5, 112.5];
Z3B = [37.5, 112.5];
Z3C = [62.5, 112.5];
    
%% User Input Variables

PosXY = [8.5, 12];

%% Calculations

count = 0;

while count < 4
    UserZone = input("Which zone do you want to puck to land in? ");
Zone = UserZone;

ChangeX = abs(PosXY(1) - Zone(1));
ChangeY = abs(PosXY(2) - Zone(2));

% checking the angle

if (ChangeX > 0)
    angle = atand(ChangeY/ abs(ChangeX));
else
    angle = 180 - atand(ChangeY / ChangeX);
end 
ChangeX = abs(ChangeX);
fprintf("The angle for the calculation is %.2f degrees\n", angle);

% Now we want to calculate our distance via pythag. Theorem
d = sqrt(ChangeX^2 + ChangeY^2);

% Now we want to Calculate for Velocity Final

vf = sqrt(d*(uk * m * g)/ (.5 * m));
% Now we want to a collision calculation and then we can set that the VF
vSpring = ((m*vf) / (deviceMass));
% Calculating the Change in x for the spring

SpringCompression = sqrt((.5*m*vSpring^2)/(.5*k));
fprintf("The Spring Compresssion should be %.2f cm\n", SpringCompression);

count = count + 1;
end 



