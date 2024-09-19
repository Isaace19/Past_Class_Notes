clear; clc;

%name: Isaac Abella
% Section B377

%% Generate Data
x1 = 0:10;
f1 = exp(0.5 * x1);
x2 = 0:19;
f2 = ones(size(x2)) *f1(end);
x3 = 0:29;
f3 = f2(end) + -10*x3;

%% plotting

% ones takes the size of an array or the rows or columns of a row vector
% multiplied by the last value of f1
% prints out a 1 by 10 array 

pushForce = [f1 f2 f3];
time = linspace(0, 30, length(pushForce));

%% Obtain a new velocity 

mass = 100; % kg
acc = pushForce/mass;

%acc(1) = 0;
vel = nan(size(time));
vel(1) = 0;

for idx = 2:length(time)
    deltaT = time(idx) - time(idx-1);
    vel(idx) = vel(idx-1) + acc(idx)*deltaT;
end 
 
%% Creating a time array that will create the graph as it goes through data



fig = figure(1); clf
subplot(3,1,1);
plot(time, vel)
ylabel('velocity [m/s]')

subplot(3,1,2);
plot(time, acc);
ylabel('Acceleration [m/s^2]')

subplot(3,1,3);
plot(time, pushForce);
ylabel('PushForce [N]')
xlabel('time [s]');

sgtitle('Object Kinematics');


% The above is array concatatonation that combines the arrays manually