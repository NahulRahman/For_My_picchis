clc;
clear;
A=5;
f=10;
t=0:0.0001:1;
y=A*sin(2*pi*f*t);
subplot(2,1,1) %2 rows, 2 cols, 1st pic
stem(t,y);
subplot(2,1,2);
plot(t,y);

subplot(1,2,1) %2 rows, 2 cols, 1st pic
stem(t,y);
subplot(1,2,2);
plot(t,y);
%2,2,1 row cols cant relate.



