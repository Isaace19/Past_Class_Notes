clear; clc;

x = linspace(0, pi);

y1 = cos(x);
y2 = cos(2*x);

figure(1); clf
subplot(2,1,2);
plot(x, y1);

subplot(3,1,2)
plot(x,y2)