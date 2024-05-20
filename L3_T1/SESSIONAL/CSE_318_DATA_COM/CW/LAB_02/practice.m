clear all;
clc;

fs=1000; 
t = linspace(0,1,1000);

fm=100;
Am=1;
mes_sig = Am * sin(2*pi*fm.*t);

fc=1000;
Ac=1;
car_sig =  Ac * sin(2*pi*fm.*t);

mod_sig = (1+mes_sig).*car_sig;

figure;

subplot(3,1,1);
plot(t,mes_sig);
title ('message signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;


subplot(3,1,2);
plot(t,car_sig);
title ('carrier signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;


subplot(3,1,3);
plot(t,mod_sig);
title ('modulated signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;

%demod

rect = abs (mod_sig);
cutoff_frequency = 200;
order = 4;

nyquist_freq = fs/2;
normalized_cutoff_freq = cutoff_frequency / nyquist_freq;
[b,a]= butter(order, normalized_cutoff_freq, 'low');
filtered_signal = filter(b,a,rect);


figure;
subplot(2,1,1);
plot(t,rect);
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
