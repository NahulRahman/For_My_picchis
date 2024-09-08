%SIDE BAND:

%Double Sideband Modulation in Frequency Domain:

clear;
clear all;

% Define parameters
fm = 1;
fc = 10;
fs = 100 * fc;
t = 0:1/fs:5;
Am = 5;
Ac = 5;

% Generate signals
message_signal = Am .* cos(2 * pi * fm * t);
carrier_signal = Ac .* cos(2 * pi * fc * t);

% DSB-SC Modulation in TIME DOMAIN
dsb_sc = message_signal .* carrier_signal;

% DSB-SC Modulation shifting to FREQ DOMAIN
N = length(dsb_sc);
f = linspace(-fs/2, fs/2, N);
DSB_SC = fftshift(fft(dsb_sc)/N);

% Demodulation (Envelope detection in Time Domain)
% ... (Include your demodulation code here if needed)
pmo = 2*dsb_sc.*carrier_signal;
pmo = pmo/Ac;
nf = fm/fs;
[num, den] = butter(5,3*nf);
msg_r = filter(num,den,pmo);

% Demodulation (Envelope detection in Freq Domain)
lr = length(msg_r);
fr = linspace(-fs/2,fs/2,lr);
MSG_R = fftshift(fft(msg_r,lr)/lr);

% Plotting in Frequency Domain
figure;

subplot(3,1,1);
plot(t, message_signal);
title('Message Signal in Time Domain');
xlabel('Time(t)');
ylabel('Magnitude');
grid on;

subplot(3,1,2);
plot(t, carrier_signal);
title('Carrier Signal in Time Domain');
xlabel('Time(t)');
ylabel('Magnitude');
grid on;

subplot(3,1,3);
plot(f, abs(DSB_SC));
title('Modulated Signal in Frequency Domain');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
grid on;

% Plotting in Frequency Domain
figure;

subplot(3,1,1);
plot(t, message_signal);
title('Message Signal in Time Domain');
xlabel('Time(t)');
ylabel('Magnitude');
grid on;

subplot(3,1,2);
plot(f, abs(DSB_SC));
title('Modulated Signal in Frequency Domain');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
grid on;

subplot(3,1,3);
plot(f, MSG_R);
title('Demodulated Signal in Frequency Domain');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
grid on;