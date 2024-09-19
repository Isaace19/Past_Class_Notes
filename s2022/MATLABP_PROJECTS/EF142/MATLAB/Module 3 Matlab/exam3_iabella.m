clear; clc;

%% Initialize Known Values

a = 1;
b = 10;

maxCycleCount = 0;

for n = a:b % leads to 10 cycles of a through b 
    allCycleCounts = 0;
    while n > 1
        if mod(n,2) == 0
            n = n/2;
        else
            n = 3*n+1;
        end
        allCycleCounts = allCycleCounts + 1;
    end
    maxCycleCount = max(maxCycleCount, allCycleCounts);
end

fprintf("The Maximum cycle amount for a start values %d through %d is %d \n", a, b, maxCycleCount);

