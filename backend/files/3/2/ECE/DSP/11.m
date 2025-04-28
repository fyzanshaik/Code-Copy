%% Design of Butterworth IIR Filter and Verify Frequency Response
clc;
clear all;
close all;

disp('Enter the IIR Filter Design Specifications');
rp = 0.15; % Passband Ripple
rs = 60;   % Stopband Ripple
wp = 1500; % Passband Frequency
ws = 3000; % Stopband Frequency
fs = 7000; % Sampling Frequency

w1 = 2 * wp / fs; % Normalized Passband Frequency
w2 = 2 * ws / fs; % Normalized Stopband Frequency

[n, wn] = buttord(w1, w2, rp, rs); % Determine filter order

c = input('Enter choice of Filters: 1.LPF 2.HPF \n'); % Filter type

if c == 1
    disp('Frequency Response of IIR LPF is:');
    [b, a] = butter(n, wn, 'low'); % Design Low-Pass Filter
elseif c == 2
    disp('Frequency Response of IIR HPF is:');
    [b, a] = butter(n, wn, 'high'); % Design High-Pass Filter
else
    error('Invalid choice. Enter 1 for LPF or 2 for HPF.');
end

[h, om] = freqz(b, a, 1024, fs); % Frequency response of digital filter
m = 20 * log10(abs(h)); % Magnitude response in dB
an = angle(h); % Phase response in radians

subplot(2, 1, 1);
plot(om / (fs / 2), m); % Normalize frequency to Nyquist frequency
title('Magnitude Response of IIR Filter - 22881A0440');
xlabel('Normalized Frequency');
ylabel('Gain in dB');

subplot(2, 1, 2);
plot(om / (fs / 2), an); % Normalize frequency to Nyquist frequency
title('Phase Response of IIR Filter - 22881A0440');
xlabel('Normalized Frequency');
ylabel('Phase in radians');
