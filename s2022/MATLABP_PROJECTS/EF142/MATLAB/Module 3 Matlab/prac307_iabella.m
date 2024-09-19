clear; clc;

% Name: Isaac Abella
% Program Description: Writing a script to see the amount of collision that
% a bill will go through until stopping, and I guess we check the amount of
% time they collided via while loop and then outputing the amount of
% iterations.

%Notes about program: we have two balls that we have to put through the 
%body of a loop that will calcualte the resulting velocity of each ball

%% Initialize known values
gravity = 9.81; % [m/s^2]
height = 1; % [m]
mass = 1; % [kg]
DBB = 1; % Distance between both balls [m]
uk = 0.1; % kinetic friction coefficient
e = 0.1; % Coefficient of Restitution

% Calculate the initial velocity of the first ball
VA = sqrt(2*gravity*height);

% Initialize collision counter
collisions = 0;
while VA > 0
    collisions = collisions + 1;
    
    % Calculate velocities after collision
    VBPrime = VA * (1 + e) / 2;
    VA = sqrt(VBPrime^2 - 2 * gravity * uk * DBB);
    disp(['Velocity after collision ' num2str(collisions) ':' num2str(VA)]);

end

% Display the number of collisions
disp(['Number of collisions: ' num2str(collisions)]);
