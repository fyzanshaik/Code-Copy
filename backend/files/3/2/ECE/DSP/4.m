clc;
clear all;
close all;

% Convolution of two sequences
x = input('Enter the i/p sequence x(n): ');
h = input('Enter the i/p sequence y(n): ');
n1 = length(x);
n2 = length(h);
N = n1 + n2 - 1;
x = [x, zeros(1, (N - n1))];
h = [h, zeros(1, (N - n2))];
y = zeros(1, N);
for n = 1:N
    for k = 1:n
        y(n) = y(n) + x(k) * h(n - k + 1);
    end
end
disp(y);

% Stability check of a system
num = [1];
den = [1, -3, 2];
z = roots(num);
p = roots(den);
c = 0;
for i = 1:length(p)
    if abs(p(i)) > 1
        c = c + 1;
    end
end
if c == 0
    disp('Stable');
else
    disp('Not Stable');
end
zplane(z, p);
