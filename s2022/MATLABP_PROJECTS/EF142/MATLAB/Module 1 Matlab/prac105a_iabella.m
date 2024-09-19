%Calculate the tension in two strings 
%suspending an object of new weight

%name: Isaac Abella
%section: B377

%initialization

theta = [35 42]; %angle of the two strings

weight = 54; %weight of the object in lbs

%Calculations of the matrix 

%create the matrix of the system

sys = [cosd(theta(1)) -cosd(theta(2)) 0;
       sind(theta(1))  sind(theta(2)) weight];

% use the rref function to solve the matrix

solution = rref(sys);

%indexing the tension of the last column of the matrix

tension = solution(:,end);

%final output 
tension
