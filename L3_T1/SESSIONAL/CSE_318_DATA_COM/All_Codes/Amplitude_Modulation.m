%Amplitude Modulation
clear;
close all;
clc;

%time parameters
fs = 1000;                %sampling frequency (Hz)
t = linspace(0, 1, 1000); %time vector (0 to 1 second)

%Message signal parameters
fm = 10;       %message signal frequency
Am = 1;        %message signal amplitude
message_signal = Am * sin(2*pi*fm.*t); %message signal

%Carrier signal parameters
fc = 100;      %carrier signal frequency
Ac = 2;        %carrier signal amplitude
carrier_signal = Ac * sin(2*pi*fc.*t); %carrier signal

%modulated signal
modulated_signal = (1 + message_signal) .* carrier_signal;

%plotting
figure;
subplot(7,1,1);
plot(t, message_signal);
title('Message Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;
subplot(7,1,2);
plot(t, carrier_signal);
title('Carrier Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;
subplot(7,1,3);
plot(t, modulated_signal);
title('Modulated Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

%%demodulation 
%Rectification process
rectified_signal = abs(modulated_signal);

%plotting
figure;
subplot(7,1,4);
plot(t, modulated_signal);
title('Modulated Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;
subplot(7,1,5);
plot(t, rectified_signal);
title('Rectified Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

%low pass filter parameters
cutoff_freq = 20;

%design the low pass filter
order = 4;                 %filter order
nyquist_freq = fs/2;       %Hz
normalized_cutoff_freq = cutoff_freq / nyquist_freq;
[b,a] = butter(order, normalized_cutoff_freq, 'low');

%apply the lowpass filter to the rectified signal
filtered_signal = filter(b, a, rectified_signal);

%plotting
figure;
subplot(7,1,6);
plot(t, rectified_signal);
title('Rectified Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;
subplot(7,1,7);
plot(t, filtered_signal);
title('Filtered Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;
