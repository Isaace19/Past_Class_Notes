clear; clc;

%% Unknown Variables
%FinalVelocity
%SpringDistance

%% Known Variables

InitialVelocity = 0; % [m/s]
DeveiceHeight = 10; % [cm]
PuckHeightFinal = 0; % [cm]

uk = .1; % note that our friction could be so low that it's negligible (verified by Dr. Mackza)
% Measurement Procedure: 
deviceMass = 4.43; %[g]
EFpuck = 15; % [g]
m = 12; % [g]
k = 1000; % [spring constant N-m]

SpringConstant = 0; 
g = 9.81; % [m/s^2]

% Creating values of zones for each section of the table
Deadzone = 50;

% index of 1 is the x axis and the index of 2 is the y axis
Z1A = [12.5, 62.5];
Z1B = [37.5, 62.5];
Z1C = [62.5, 62.5];

Z2A = [12.5, 87.5];
Z2B = [37.5, 87.5];
Z2C = [62.5, 87.5];

Z3A = [12.5, 112.5];
Z3B = [37.5, 112.5];
Z3C = [62.5, 112.5];
    
EFpuck = [35.5,100];
%% User Input Variables

PosXY = [8.5, 12];
StartingPosXY = [8.5 12];
canGoStraight = 'y'; % [y/n]
PosXY = StartingPosXY;
xCordEnd = 12; % Enter in before launching to hang off the edge, set it to the x cordinate at the end of the table

%% Calculations

count = 0;

while true
    UserZone = input("Which zone do you want to puck to land in? ");
Zone = UserZone;

ChangeX = abs(PosXY(1) - Zone(1));
ChangeY = abs(PosXY(2) - Zone(2));

% checking the angle

if (ChangeX > 0)
    angle = atand(ChangeY/ abs(ChangeX));
else
    angle = 180 - atand(ChangeY / ChangeX);
end 
ChangeX = abs(ChangeX);
fprintf("The angle for the calculation is %.2f degrees\n", angle);

% Now we want to calculate our distance via pythag. Theorem
d = sqrt(ChangeX^2 + ChangeY^2);
%d = 44.45;
% Now we want to Calculate for Velocity Final

vf = sqrt(d*(uk * m * g)/ (.5 * m));
% Now we want to a collision calculation and then we can set that the VF
vSpring = ((m*vf) / (deviceMass));
% Calculating the Change in x for the spring

SpringCompression = sqrt((.5*m*vSpring^2)/(.5*k));
fprintf("The Spring Compresssion should be %.2f cm\n", SpringCompression);

count = count + 1;

if count >=4 
    operation = input("Do you want to do: EF Puck or Hang Off Edge: ", 's');

    if strcmp(operation, 'EF Puck')
        %% EF Puck Collision 
        Goal = input("What is the coordinates Needed for the Goalpost: ");
        % Distance Calcs for EF Puck
        ChangeXEF = abs(EFpuck - Goal(1));
        ChangeYEF = abs(EFpuck - Goal(2));
        dEF = sqrt(ChangeXEF.^2 + ChangeYEF.^2); 
        dTotal = d + dEF;

        % Angle Calcs for EF Puck
        if (ChangeXEF > 0)
            angleEF = atand(ChangeYEF / abs(ChangeXEF));
        else
             angleEF = 180 - atand(ChangeYEF / ChangeXEF);
        end
    
    % Velocity Calcs

    VfprimeEF = sqrt((d .* (uk .* EFpuck .* g)) / (.5 .* EFpuck));
    VfprimeEFx = cos(angleEF) * VfprimeEF;
    VfprimeEFy = sin(angleEF) * VfprimeEF;
    VpuckY = (EFpuck * VfprimeEFy) / m;
    VpuckX = VpuckY / tan(angleEF);
    vpuck = sqrt(VpuckX.^2 + VpuckY.^2);
    vpuckloss = sqrt((d .* (uk .* m .* g)) / (.5 .* m));
    vpuckneeded = vpuck + vpuckloss;
    vSpring = (m * vpuckneeded) / deviceMass;
    SpringCompression = sqrt((.5 * m * (vSpring.^2)) / (.5 * SpringConstant));

    fprintf("The Spring Compresssion should be %.2f cm, and the final velocity is %.2f cm^2 \n", SpringCompression , vSpring);
    break;
    end
    if strcmp(operation, 'Hang Off Edge')
        if (canGoStraight == 'y')
        endOfTable = [StartingPosXY(1), 152];
        ChangeY = abs(StartingPosXY(1) - endOfTable(1));
        dpuck = ChangeY;
        vf = sqrt((d * (uk * m * g)) / (.5 * m));
        vSpring = (m * vf) / (deviceMass);
        SpringCompression = sqrt((.5 * m * (vSpring^2)) / (.5 * SpringConstant));
        else 
        endOfTable = [xCordEnd, 152];
        ChangeY = abs(StartingPosXY(1) - endOfTable(1));
        ChangeX = abs(StartingPosXY(2) - endOfTable(2));
        dpuck = sqrt(ChangeX^2 + ChangeY^2);
        vf = sqrt((dpuck * (uk * m* g)) / (.5 * m));    
        vSpring = (mpuck * vf) / (DeviceMass);
        SpringCompression = sqrt((.5 * m * (vSpring^2)) / (.5 * SpringConstant));
        end
        fprintf("The Spring Compresssion should be %.2f cm, and the final velocity is %.2f cm^2 \n", SpringCompression , vSpring);
    end
    break;
end
end

