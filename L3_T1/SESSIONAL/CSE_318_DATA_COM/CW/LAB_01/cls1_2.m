a=[1 2 3; 4 5 6; 7,8,9];
b=[1,2,3;
    4 5 6;
    7,8,9];
disp(a(1,1));
disp(a(1,1:3));
disp(a(1,1:3));
disp(a(:,2));
disp(a(1:2,2));


c=[a b];

c=[a; b];

a=zeros(1,3);
b=ones(3,3);
c=eye(3,3);
d=rand(3,3)*30+30;

a=[1 2 3 4 5 6 7 8 9];
for i=1:2:length(a)
   if i == 2
        disp(a(i));
   %elseif
       
   else
       disp('not2');
   end
end


