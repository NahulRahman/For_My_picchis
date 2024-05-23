clc;
clear all;
close all;

fs = 20000;
fm = 1000;
t = 0:1/fs:3600/fs; % Time Duration = 1000/10000 = 0.1 second
%Am = 5
x = 5*sin(2*pi*100*t); % Define Message Signal with peak voltage 5V and frequency 100Hz


y = [0]; % Output DM signal i.e. stream of 1 or 0
xr = 0; % Output of Integrator i.e. staircase approximation; initial value = 0
del = 0.3; % Stepsize

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


MSE = sum((x - xr).^2) / length(x); % Mean Squared Error (MSE)
disp(['Mean Squared Error (MSE): ', num2str(MSE)]);



subplot(4, 1, 1);
plot(t, x);
title('I/P Signal');


subplot(4, 1, 2);
plot(t,y); 
title('Delta Modulated Signal');

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

subplot(4, 1, 3);
plot(t, y_demod);
title('Delta Demodulated Signal (Before Filtering)');

filter_order = 10;
lowpass_filter = fir1(filter_order, fm/(fs/2), 'low');
filtered_demod_signal = filter(lowpass_filter, 1, y_demod);

subplot(4, 1, 4);
plot(t, filtered_demod_signal);
title('Filtered Demodulated Signal');

