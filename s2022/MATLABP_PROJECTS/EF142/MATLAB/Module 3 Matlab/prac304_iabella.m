clear clc;

% Name: Isaac Abella
% Program Description: This program will calculate the simulated
% acceleration, velocity, and the position of the rocket as it performs a
% burn and switch in zero gravity situations.

%% Initialize Values

thrust = 1500; % N
mass = 100; % KG
gravity = 9.81; % [M/S^2]

x1 = 0:99;
f1 = ones(size(x1))*thrust;
f2 = ones(size(x1))*-thrust;

thrust = [f1 f2];
time = linspace(0, 365, length(thrust));

% Instructions: use 100 points of maximum thrust and 100 points of minimum
% thrust; Generate a time array from 0 seconds and 1 year with the same
% data points for the thrust array.

acc = thrust/mass;
acc(1) = 0;

acc = zeros(1, length(time));
vel = zeros(1, length(time));
vel(1) = 0;
pos = zeros(1, length(time));
pos(1) = 0;

% Thrust dat
for i = 2:length(thrust)
    % Calculate acceleration
    acc(i) = (thrust(i)/mass);
    deltaT = time(i) - time(i -1);
    % Calculate velocity
    vel(i) = vel(i-1) + acc(i)*100*deltaT;
    % Calculate position
    pos(i) = pos(i-1) + vel(i-1)*deltaT*100000 + .5*(acc(i)*1000*deltaT^2);
end


% Graphing

fig = figure(1); clf

% Plot the results
subplot(3,1,1)
plot(time, pos)
ylabel('Position (m)')

subplot(3,1,2)
plot(time, vel)
ylabel('Velocity (m/s)')

subplot(3,1,3)
plot(time, acc)
ylabel('Acceleration (m/s^2)')

xlabel('time [days]');

sgtitle('Spaceship Kinematics');

