% Calculating the work done on objects with a known mass on a surface 

%Name = Isaac Abella
%Section = B377
clear; clc;
load prac108_data.mat


%Initialize our known variables
disp(name)
disp(mass)

time = input("Provide a time in seconds to move each object above in array form\n");

g = 9.81; % gravity in m/s^2
displacement = 1.75;

% Calculations
force = mass .* g;
work = force .*( displacement);
velocity = displacement ./ time;
power = force .* velocity;

[powerMax, indexPos] = max(power);

%%Output%%
maxName = name(indexPos);
timeMax = time(indexPos);


fprintf("The most power of %.3g was needed to lift the %s %.2f meters in %.2f seconds\n", powerMax, maxName, displacement, timeMax);



