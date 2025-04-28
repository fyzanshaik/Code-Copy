%% Linearity Check
clc;
clear all;
close all;

% Define input signals
x1 = [1 2 3 4];
x2 = [4 5 6 7];

% System outputs for individual inputs
y1 = x1.^2;
y2 = x2.^2;

% Linear combination of inputs
a1 = 1;
a2 = 1;
y3 = a1 * y1 + a2 * y2; % Output for linear combination of inputs
disp('y3 (Linear Combination of Outputs):');
disp(y3);

% Output for combined input
x4 = a1 * x1 + a2 * x2;
y4 = x4.^2; % Output for combined input
disp('y4 (Output for Combined Input):');
disp(y4);

% Check linearity
if isequal(y3, y4)
    disp('The system is linear.');
else
    disp('The system is non-linear.');
end

%% Time Invariance Check
n = 0:3; % Time indices
x = [1 2 3 4]; % Input signal

% Delayed input
x1 = [zeros(1, 2), x]; % Delay input by 2 samples
n1 = 0:length(x1)-1; % New time indices for delayed input

% Output for delayed input
y1 = n1 .* x1;

% Original output
y = n .* x;

% Delayed output
y2 = [zeros(1, 2), y]; % Delay output by 2 samples

% Check time invariance
if isequal(y1, y2)
    disp('The system is time-invariant.');
else
    disp('The system is time-variant.');
end
