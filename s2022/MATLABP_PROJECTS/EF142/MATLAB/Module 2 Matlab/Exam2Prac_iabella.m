clear; clc

% Name: Isaac Abella
% Program Description: Determine velocity after impact, Determine whether
% or not 2 objects will land within a certain zone. Print the results


%% Declare your known values through arrays 
ObjectNames = ["Billiard Ball", "Shuffeboard Disc","Curling Stone"];

Objectmasses = [.15, .25, 19.1]; % [KG]

Restitution = [.9, .7, .65]; 
Friction = [.06, .31, .05];

DistanceAB = .25; % [m]
DistanceBLOI = .80; % [m]

ObjAVDir = 45; %[Deg]
ErrorMargin = .05; %[m]
g = 9.81;

%% Calculations Time
dummy1 = input("Enter an object index: ");
index = dummy1;

dummy2 = input("Enter a velocity value [m/s]: ");
Vinitial = dummy2;

Va1 = sqrt((Vinitial^2) - (2*g*Friction(index)*DistanceAB));
VaX = Va1*(cosd(-ObjAVDir));
VaY = Va1*(sind(-ObjAVDir));

matrix = [1, 1, VaY; -1, 1, (Restitution(index)*VaY)];

routput = rref(matrix);
d2 = (routput(2,end)^2)/(2*g*Friction(index));

%% Output time

fprintf("The %s B travels %.2f meters along the LOI before coming to a stop. \n", ObjectNames(index), d2)

%% Checking if your under or over.
if(d2 < DistanceBLOI)
    dRemain = DistanceBLOI - d2-ErrorMargin;
    fprintf("It did not reach the goal zone, stopping %.2f m from the minimum distance. \n", dRemain);
end
if (round(d2,2) ~= DistanceBLOI && d2 > DistanceBLOI)
    dOver = (d2-ErrorMargin) - DistanceBLOI;
    fprintf("It overshot the goalzone, stopping at %.2f m past the maximum goal distance. \n", dOver);
elseif(round(d2,2) == DistanceBLOI)
    fprintf("This distance places it in the goal zone. \n");
end


