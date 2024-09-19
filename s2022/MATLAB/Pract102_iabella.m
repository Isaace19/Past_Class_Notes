% Process Template to Script Program %
% Converting the speed of a blade into % 
% miles per hour given rpm and radius %


% declaring the given values %
RPM = 3500;
Diameter = 8;
Radius = Diameter/2;
InchesToFeet = 12;


% Work %

RadianPerSec = (RPM * 2*pi)/60 
RadianFeet = (RadianPerSec * Diameter * pi)/(2*pi*12) 
RadianMPH = (RadianFeet * 60 * 60) / 5280




