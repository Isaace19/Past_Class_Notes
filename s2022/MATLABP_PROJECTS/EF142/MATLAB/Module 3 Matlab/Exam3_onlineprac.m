clear; clc;

%% Initialize Known Values

disp("For each prompt, enter a number between 1 and 5")


input1 = input("I have overcome setbacks to conquer an important challenge: ");
input2 = input("Setbacks don't discourage me: ");
input3 = input("I am a hard worker: ");
input4 = input("I finish whatever I begin: ");
input5 = input("I have achieved a goal that took years of work: ");

input  = [input1, input2, input3, input4, input5];
for i = 1:5
    if input(i) > 5 || input(i) < 1
        warning("You entered an invalid value. Using a default response of 3");
        input(i) = 3;
    end

end

average = floor(20*mean(input));

fprintf("Your grit score is %d/100", average);