%ASK PSK FSK
clear;
close all;
clc;

data = [1 0 1 1 0 1 0 1];
bp = 0.00001;

bit = [];
for i=1:1:length(data)
    if data(i) == 1
        se = zeros(1,100);
    else
        se = ones(1,100);
    end
    bit = [bit se];
    
end
t1 = bp/100:bp/100:bp*length(data);
subplot(4,1,1);
plot(t1,bit,'Linewidth',1.5);
axis([0,8*bp, -1.5,1.5]);


%ASK
A0 = 0;
A1 = 1;
f = 5/bp;
st = [];
t2 = bp/100:bp/100:bp;
for i=1:1:length(data)
    if data(i) == 1
        y = A1*sin(2*pi*f*t2);
    else
        y = A0*sin(2*pi*f*t2)
    end
    st = [st y];
end
subplot(4,1,2);
plot(t1,st, 'Linewidth',1.5);
axis([0,8*bp,-1.5,1.5]);


%FSK
A = 1;
f1 = 5/bp;
f0 = 2/bp;
st = [];
t2 = bp/100:bp/100:bp;
for i=1:1:length(data)
    if data(i) == 1
        y = A*sin(2*pi*f1*t2);
    else
        y = A*sin(2*pi*f0*t2)
    end
    st = [st y];
end
subplot(4,1,3);
plot(t1,st, 'Linewidth',1.5);
axis([0,8*bp,-1.5,1.5]);

%PSK
A = 1;
f = 5/bp;
st = [];
t2 = bp/100:bp/100:bp;
for i=1:1:length(data)
    if data(i) == 1
        y = -A*cos(2*pi*f*t2);
    else
        y = -A*sin(2*pi*f*t2)
    end
    st = [st y];
end
subplot(4,1,4);
plot(t1,st, 'Linewidth',1.5);
axis([0,8*bp,-1.5,1.5]);

