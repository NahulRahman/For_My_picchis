%load checksum.txt;
clear;
close all;
clc;

data = [7 11 12 0 6];

len = length(data);
cs = sum(data);
cs = dec2bin(cs);

len = length(cs);
mainBin = cs(len-4+1:len)
wrapBin = cs(1:len-4)

mainDec = bin2dec(cs(len-4+1:len))
wrapDec = bin2dec(cs(1:len-4))
wrappedsum = (dec2bin((mainDec+wrapDec), 4))


checksum = "";
for i=1:1:4
    if(wrappedsum(i) == '1')
        checksum = checksum+"0";
    else
        checksum = checksum+"1";
    end
end
checksum = bin2dec(checksum)

