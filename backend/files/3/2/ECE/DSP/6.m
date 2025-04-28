clc
clear all
close all
%frq resp of continous time system
b=[1 -1];
a=[1 -3 5];
w=-pi:0.01:pi;
H=freqs(b,a,w)
mag=abs(H);
phase=angle(H);
subplot(2,2,1);
plot(w,mag);
title('Magnitude response of the first order CT system');
xlabel('normalized freq');
ylabel('magnitude in radians');
subplot(2,2,2)
plot(w,phase);
title('Phase response of first order CT system');
xlabel('normalized freq');
ylabel('magnitude in radians');
%freq response of discrete time system
b=[1 -1];
a=[1 -3 5];
w=-pi:0.01:pi;
H=freqz(b,a,w)
mag=abs(H);
phase=angle(H);
subplot(2,2,3)
plot(w,mag);
title('Magnitude response of first order DT system')
xlabel('normalized freq');
ylabel('magnitude in radians');
subplot(2,2,4)
plot(w,phase);
title('Phase response of first order DT system')
xlabel('normalized freq');
ylabel('magnitude in radians');
gtext('22881A04J5');