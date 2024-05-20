%modulation

clear all;
clc;

%time parameter

fs=1000; %sample frequency
t = linspace(0,1,1000); % time parameter 0 to 1000, 1s difference

%message signal parameter

fm=10;
Am=1;
message_signal = Am * sin(2*pi*fm.*t); %message signal

%carrier_signal 

fc=100;
Ac=2;
carrier_signal =  Ac * sin(2*pi*fm.*t); %carrier signal

%modulated signal
kf=10;
modulated_signal = Ac * sin(2*pi*fm.*t + kf*message_signal) ;

%plotting

figure;

subplot(3,1,1);
plot(t,message_signal);
title ('message signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;


subplot(3,1,2);
plot(t,carrier_signal);
title ('carrier signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;


subplot(3,1,3);
plot(t,modulated_signal);
title ('modulated signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;


%demodulation

%1. rectification

rectified_signal = abs (modulated_signal);

%plotting

figure;
subplot(2,1,1);
plot(t,modulated_signal);
title ('modulated signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;

subplot(2,1,2);
plot(t,rectified_signal);
title ('rectified signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;


%low pass filter

cutoff_frequency = 20;

%2. designing low pass filter

order = 4;

nyquist_freq = fs/2;

normalized_cutoff_freq = cutoff_frequency / nyquist_freq;

%butterworth
[b,a]= butter(order, normalized_cutoff_freq, 'low');

%apply lowpass filter to the rectified signal

filtered_signal = filter(b,a,rectified_signal);

%plotting

figure;
subplot(2,1,1);
plot(t,rectified_signal);
title ('rectified signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;

subplot(2,1,2);
plot(t,filtered_signal);
title ('filtered_signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;