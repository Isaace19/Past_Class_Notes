%% Example Problem
% display the calculated properties of a cylinder from data provided by the user
 
clear % clears out workspace variables
clc % dry eraser of command window
 
%% Inputs
r = 4; % [cm], radius of cylinder
H = input('Enter the height [cm]: '); % prompt the user for a number
material = input('Enter the material: ', 's'); % prompt user for a name (text)
 
%% Calculations
V = pi*r^2*H; % calculate volume [cm^3]
 
%% Formatted Output
fprintf('A cylinder made of %s has a volume of %#.3g [cm^3]. \n', material, V)
fprintf('\tRadius = %0.2f [cm]\n', r)
fprintf('\tHeight = %d [cm]\n', H)