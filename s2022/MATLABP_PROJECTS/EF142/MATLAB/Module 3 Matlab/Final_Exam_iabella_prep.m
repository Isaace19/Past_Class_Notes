clear; clc;
 
myData = [2 3 4;
          4 2 1;
          2 3 1;
          3 4 1;
          1 4 2;
          4 2 1];
 
for idx = 1:height(myData)/2
    startIdx=2*idx-1;
    endIdx = startIdx+1;
    sys = myData(startIdx:endIdx :);
    if all(sys(1,:) < 4)
        sys(2,1:2) = sys(2,1:2)*5;
    end
    solSys = rref(sys);
    x = solSys(:,3);
    fprintf("Solution #%d is x=%.2f, y=%.2f\n", idx, x(1), x(2))
end