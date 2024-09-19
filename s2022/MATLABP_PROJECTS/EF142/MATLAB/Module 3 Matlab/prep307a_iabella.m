clear; clc;

%% Initialize Known Values

N = 10; 
fib = [1,1];

n = 3;

while fib(n - 1 ) <=N
    fib(n) = fib(n-1) + fib(n-2);
    n = n + 1;
end

n = n - 1;
fprintf("The Value %d is the greatest still less than or equal to %d. \n", fib(n-1), N);
