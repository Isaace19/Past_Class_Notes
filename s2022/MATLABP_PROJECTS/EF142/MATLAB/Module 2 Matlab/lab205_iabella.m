%% Initialize Known values

data = readtable("lab205_data.csv");

%% Ask User for E and Final Index of car 1 and car 2

restitution = input("Enter a coefficient of resitution [0 or 1]: ");
e = restitution;

rowInfo1 = input("Input the row that you want to use for car 1? ");
mass1 = data.mass(rowInfo1);
velocity1 = data.velocity(rowInfo1);

rowInfo2 = input("Input the row that you want to use for car 2? ");
mass2 = data.mass(rowInfo2);
velocity2 = data.velocity(rowInfo2);

% Depending on which one they input, execute the proper equation


if e == 1
    % here we are going to do a rref of the elastic calculation
    Matrix = [mass1 mass2 ((mass1 * velocity1)+(mass2 * velocity2)); -1 1 (e*(velocity1) - (e*(velocity2)))];
    A = rref(Matrix);
    output1 = A(1,3);
    output2 = A(2,3);
    fprintf("The velocity of the car will be: %.2f m/s and the velocity of car 2 will be: %.2f m/s", output1, output2);
else 
    % here we are going to do a calculation of the inelastic calculation
    vprime = ((mass1*velocity1) + (mass2*velocity2) / (mass1 + mass2));
    fprintf("The finally velocity of the car will be: %.2f", vprime);
end

