clear; clc;

% Name: Isaac Abella
% Section: B(377)

%% Initialize Known Values

bounds = [1 10];
maxTries = 3;

isValid = true;
nTries = 1;
while isValid && nTries <= maxTries
    value = input(sprintf("Enter an integer that is between %d and %d: ", bounds()));

      
    inRange = value >= bounds(1) && value <= bounds(2);
    isInteger = round(value) == value;

    if ~inRange
        warning("The Number %d is not in valid range", value);
    end 
    isValid = inRange;
    nTries = nTries +1;
end

if ~inRange
    fprintf("The valid value %d was provided. \n", value);
end


if ~isInteger
    warning("The value %.2f is not an integer", value);
end

if (~isValid)
    error("Maximum number of tries was exceeded");
end

fprintf("The valid value %d was provided. \n", value);
