% Initialize Known Values

height = input("What height [m] is the object starting from:  \n");
velocity = input("What is the object's initial vertical velocity [m/s]: \n");
acceleration = 9.81; % [m/s^2]
acclerationHalf = acceleration / 2;

%% Calculation

% SOLVING FOR TIME

polyVal = [acclerationHalf velocity height];
Time = max(roots(polyVal));

fprintf("The object hit the ground in %.2f seconds \n", Time);