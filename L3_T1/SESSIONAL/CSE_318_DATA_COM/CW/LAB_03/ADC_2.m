clc;
clear all;
close all;

fs = 10000;
fm = 100;
t = 0:1/fs:1000/fs; % Time Duration = 1000/10000 = 0.1 second
%Am = 5
x = 5*sin(2*pi*100*t); % Define Message Signal with peak voltage 5V and frequency 100Hz

plot(t, x);
hold on   

y = [0]; % Output DM signal i.e. stream of 1 or 0
xr = 0; % Output of Integrator i.e. staircase approximation; initial value = 0
del = 0.4; % Stepsize

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

figure;

% Delta Modulation
subplot(3, 1, 1);
plot(t,y); % Show the staircase approximated signal
title('Delta Modulated Signal');

% Delta Demodulation
subplot(3, 1, 2);
y_demod = [0];
xr_demod = 0;

for i = 2:length(y)
if y(i) == 1
xr_demod = xr_demod + del;
else
xr_demod = xr_demod - del;
end
y_demod = [y_demod xr_demod];
end

plot(t, y_demod);
title('Delta Demodulated Signal (Before Filtering)');

% Apply Low-Pass Filter
filter_order = 20;
lowpass_filter = fir1(filter_order, fm/(fs/2), 'low');
filtered_demod_signal = filter(lowpass_filter, 1, y_demod);

% Plot the filtered demodulated signal
subplot(3, 1, 3);
plot(t, filtered_demod_signal);
title('Filtered Demodulated Signal');
















