clc;
clear;
close all;

data = [1 0 1 1 0 1];
bp = 0.00001;

bit=[];

for i=1:1:length(data)
    if data(i) == 1
        se = ones(1,100);
    else
        se = zeros(1,100);
    end
    bit = [bit se];
end

t1 = bp/100:bp/100:bp*length(data);

subplot(4,1,1);

plot(t1,bit);

axis([0,bp*length(data),0,1.5]);


%ASK

A0 = 0;

A1 = 1;

f = 5/bp;

t2 = bp/100:bp/100:bp;
st=[];

for i=1:1:length(data)
    if data(i)==1
        y = A1 * sin(2*pi*f*t2);
    else
        y = A0 * sin(2*pi*f*t2);
    end
    st = [st,y];
end

subplot(4,1,2);

plot(t1,st);

axis([0,bp*length(data),-4,4]);