clc; clear;

% Initialize Known Values
vi = 5; % m/s
hi = 35; % m
hf = 24; % m
k = 4000; % N/m
g = 9.81; % m/s^2

%% User Input

mass = input("What is the mass [kg] of the car? " );
Spring = input("what is the final spring compression [m]? ");

Mass = mass;
spring = Spring;

ke = .5 * Mass * vi^2;
ugi = Mass * g * (hi - hf);
uef = .5 * (k *(spring)^2);

Eloss = ke + (ugi - uef);

%% Output

fprintf('\nWith a spring compression of %.2f m and car mass of %.2f kg %.3g J of energy left the system.\n', spring, Mass, Eloss);


    


