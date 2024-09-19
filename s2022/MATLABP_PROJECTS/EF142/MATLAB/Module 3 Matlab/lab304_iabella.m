clear; clc

% Name: Isaac Abella
% Program Description: This program will calculate the acceleration and
% velocity at each value of a time. 

%% Initialize Known Values

data = load("lab304_data.mat");

% set the nominal values from the lab
uk = .33; 
us = .78;
theta = 11; % deg
weight = 250; % N
gravity = 9.81; % m/s^2

% Declare known from data table
pullForce = data.pullForce();
time = data.time();

% Calculations
m = weight/gravity;
Py = pullForce*sind(theta); %Remember to use the cosd and sind to convert from radians
Px = pullForce*cosd(theta);
Fn = weight - Py; % Force normal
Fmax = us * Fn; % Force Max

vn = NaN(1, length(time)); % we want to declare our vn and ax as empty but the same array size as time so the calculations will work in matlab
ax = NaN(1, length(time));

vn(1) = 0;
ax(1) = 0;

% Loop calculations
for idx = 2:length(time) % For loops want us to index into a proper array,
    %but we can't start at 1 because our velocity is set to NaN/0
    if (Px(idx) > Fmax(idx) || vn(idx-1) > 0)
        ForceFriction = uk * Fn(idx);
    else 
        ForceFriction = Px(idx);
    end
       ax(idx) = (Px(idx) - ForceFriction)/(m); % since the only changing variable in this is ForceFriction, we can just do the calculations outside of our logical if statement.
       t  = time(idx) - time(idx - 1);  
       vn(idx) = vn(idx - 1) + ax(idx) * t;
end

% Plotting - pull vs time, force vs time, acceleration vs time,
% velocity vs. time graph

fig1 = figure(1); clf

subplot(3,1,1);
hold on % we want to use hold on because we want to plot similar data series onto the same plot.
plot(time, Px, 'DisplayName', "Force in X");
plot(time, Fmax, 'DisplayName', "Force Max");
ylabel("Force [N]");
xlabel("Time");
legend();
hold off

subplot(3,1,2);
plot(time, ax);
xlabel("Time");
ylabel("Accel. [m/s^2]")
legend();

subplot(3,1,3);
plot(time, vn, 'DisplayName', "Velocity - Time");
xlabel("Time [S]")
ylabel("V [m/s]")
legend();
sgtitle("Time Graph Comparison ")

% Give the plots some names 
% end

%% Extra Credit


