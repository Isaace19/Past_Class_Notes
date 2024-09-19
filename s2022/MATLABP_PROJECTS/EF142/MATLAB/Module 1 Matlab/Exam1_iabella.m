clc; clear;

%initialize known values

d = 9; % ft
h = 2.5; % ft
k = 2300; % lb/ft
m = 10; % slug
Ff = 14.4; % lb
g = 32.2;  % ft/s^2


% ask for user input
velocity = input("Enter the desired exit speed [ft/s]: ");
Velocity = velocity;

ug2 = (m*g) *g * h;
ke2 = (.5) * (m*g) * Velocity^2;
Eloss2 = Ff*g * d;

% Create A polynomial value

a = (.5)*k*g;
b = -Ff;
c = -(Eloss2 + ke2 + ug2);

p1 = [a b c];
SolX = max(roots(p1));

fprintf("A compression of %.2f ft is needed to launch the block at %.1f ft/s.", round(SolX,2), Velocity)

