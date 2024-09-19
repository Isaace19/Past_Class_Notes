 clear; clc;

 %% Initialize Known Values

d = 10; % [m] distance the object rolls 
g = 9.81; % [m/s^2] acceleration due to gravity

cShape = 1:4;
N = 4;

A = "Solid Cylinder";
B = "Thin Walled Cylinder";
C = "Solid Sphere";
D = "Hollow Sphere";

ShapeArr = [A, B, C, D];


prompt = 'Enter the height value [M], %s: ';

str = sprintf(prompt,ShapeArr{:});
v = 0;
t = 0;


for i = 1:4
    cShape(i) = input(sprintf(prompt,ShapeArr(i)));
    h = cShape(i);
    if cShape(i) <= 0 || cShape(i) > (.5 * d)
        warning("Invalid Ramp Height, setting to 5.00 M")
    end
    v(i) = sqrt((2*g*h)/(1 + cShape(i)));
    t(i) = (2*d)/v(i);
end


%% Calculations


[max_value, max_index] = max(cShape);
[max_name] = ShapeArr{max_index};

[max_time, max_index] = max(t); 

fprintf("The fastest object was the %s which start at a height of %.2f m and reached the bottom in %.2f seconds", max_name, max_value, max_time);


