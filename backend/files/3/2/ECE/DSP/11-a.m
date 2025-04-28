%% Design of Butterworth IIR Filter and verify Frequency Response of Filter
%% Low Pass Filer
clc;
clear all;
close all;
disp('Enter the IIR Filter Design Specifications');
%rp = input('Enter the Passband Ripple: ');
rp = 0.15;
%rs = input('Enter the Stopband Ripple: ');
rs = 60;
%wp = input('Enter the Passband Frequency: ');
wp = 1500;
%ws = input('Enter the Stopband Frequency: ');
ws = 3000;
%fs = input('Enter the Sampling Frequency: ');
fs = 7000;
w1 = 2*wp/fs;
w2 = 2*ws/fs;
[n,wn] = buttord(w1,w2,rp,rs,'s');
%c = input('Enter choice of Filters 1.LPF 2.HPF \n');
c=1;
if(c==1)
    disp('Frequency Response of IIR LPF is:');
    [b,a] = butter(n,wn,'low','s');
end
if(c==2)
    disp('Frequency Response of IIR HPF is:');
    [b,a] = butter(n,wn,'high','s');
end
w = 0:.01:pi;
[h,om] = freqs(b,a,w);
m = 20*log10(abs(h));
an=angle(h);
subplot(2,1,1);
plot(om/pi,m);
title('Magnitude Response of IIR Filter - 22881A0440');
xlabel('Normalized Frequency');
ylabel('Gain in db');
subplot(2,1,2);
plot(om/pi,an);
title('Frequency Response of IIR Filter - 22881A0440');
xlabel('Normalized Frequency');
ylabel('Phase in radians');

%% High Pass Filer
clc;
clear all;
close all;
disp('Enter the IIR Filter Design Specifications');
%rp = input('Enter the Passband Ripple: ');
rp = 0.15;
%rs = input('Enter the Stopband Ripple: ');
rs = 60;
%wp = input('Enter the Passband Frequency: ');
wp = 1500;
%ws = input('Enter the Stopband Frequency: ');
ws = 3000;
%fs = input('Enter the Sampling Frequency: ');
fs = 7000;
w1 = 2*wp/fs;
w2 = 2*ws/fs;
[n,wn] = buttord(w1,w2,rp,rs,'s');
%c = input('Enter choice of Filters 1.LPF 2.HPF \n');
c=2;
if(c==1)
    disp('Frequency Response of IIR LPF is:');
    [b,a] = butter(n,wn,'low','s');
end
if(c==2)
    disp('Frequency Response of IIR HPF is:');
    [b,a] = butter(n,wn,'high','s');
end
w = 0:.01:pi;
[h,om] = freqs(b,a,w);
m = 20*log10(abs(h));
an=angle(h);
subplot(2,1,1);
plot(om/pi,m);
title('Magnitude Response of IIR Filter - 22881A0440');
xlabel('Normalized Frequency');
ylabel('Gain in db');
subplot(2,1,2);
plot(om/pi,an);
title('Frequency Response of IIR Filter - 22881A0440');
xlabel('Normalized Frequency');
ylabel('Phase in radians');