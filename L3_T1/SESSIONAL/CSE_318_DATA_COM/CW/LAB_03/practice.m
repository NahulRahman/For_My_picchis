clc;
clear all;
close all;

fs = 10000;
fm = 1000;
t = 0:1/fs:1000/fs; % Time Duration = 1000/10000 = 0.1 second
%Am = 5
x = 1*sin(2*pi*100*t); % Define Message Signal with peak voltage 5V and frequency 100Hz


y = [0]; % Output DM signal i.e. stream of 1 or 0
xr = 0; % Output of Integrator i.e. staircase approximation; initial value = 0
del = 0.1; % Stepsize

for i = 1:length(x)-1
    if xr(i) <= x(i) % If current sample greater than the previous values or output of the integrator, output of DM = 1
        d = 1;
        xr(i+1) = xr(i) + del; % Staircase approximated value
    else
        d = 0;
        xr(i+1) = xr(i) - del; % If current sample less than the previous values or output of the integrator, output of DM = 0
    end
    y = [y d];
end

stairs(t, xr); % Show the staircase approximated signal
title('Staircase Approximated Signal');
hold off

MSE = sum((x - xr).^2) / length(x); % Mean Squared Error (MSE)
disp(['Mean Squared Error (MSE): ', num2str(MSE)]);

subplot(2, 1, 1);
plot(t, x);
title('I/P Signal');


subplot(2, 1, 2);
plot(t,y); 
title('Delta Modulated Signal');


