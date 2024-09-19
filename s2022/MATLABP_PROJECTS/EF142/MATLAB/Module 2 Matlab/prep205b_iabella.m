%% Start of Code

ThresholdForce = 1.5; % [N]
StartForce = 25; % [N]
pushDistance = 1:.1:10; %[d m]
distance = input("Enter a check in distance [m]: ");
d1 = distance;

%% Force Calculations

Status = ThresholdForce* d1;
pushForceStatus = StartForce ./pushDistance.^2;

AboveThreshold = pushForceStatus(pushDistance <= d1);
checkingForce = AboveThreshold(end);

if pushForceStatus(d1 == 1) > ThresholdForce
    fprintf("Still Going \n");
else 
    fprintf("She's doing something else\n");
end
stillgoing = pushDistance(pushForceStatus > ThresholdForce);
thresholdDistance = stillgoing(end);

fprintf("She got bored after %.1f meters ", thresholdDistance);

