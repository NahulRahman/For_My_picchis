clear all;
clc;
fs=25000;
t = 0:1/fs:2000/fs;


fm=60;
Am=1;
message = Am * cos(2*pi*fm.*t);

fc=1200;
Ac=1;
carrier =  Ac * sin(2*pi*fm.*t); 

modu = (1+message).* carrier;


recti = abs (modu);



cutoff= 90;
order = 4;
nyquist_freq = fs/2;
norm_cutoff = cutoff / nyquist_freq;
[b,a]= butter(order, norm_cutoff, 'low');
filtered = filter(b,a,recti);



figure;

subplot(5,1,1);
plot(t,message);
title ('message signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;


subplot(5,1,2);
plot(t,carrier);
title ('carrier signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;


subplot(5,1,3);
plot(t,modu);
title ('modulated signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;

subplot(5,1,4);
plot(t,recti);
title ('rectified signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;


subplot(5,1,5);
plot(t,filtered);
title ('filtered signal');
xlabel('time(s)');
ylabel('Amplitude');
grid on;
