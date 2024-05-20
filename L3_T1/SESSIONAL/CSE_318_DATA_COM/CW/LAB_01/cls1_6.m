clc;
clear;
N = input('');
while ~isscalar(N) || N <= 0 || ~fix(N) == N
  N = input('Invalid. another one: ');
end
d = floor(rand(N, N) * 9) + 1;
while true
 a = input('Enter 1 to replace 10s with 0s, 2 to display the transpose, or anything else to exit: ');
  if a == 1
    d(d == 10) = 0;
    disp(d);
  elseif a == 2
    disp(d');
  else
    break;
  end
end

disp('Exiting...');
