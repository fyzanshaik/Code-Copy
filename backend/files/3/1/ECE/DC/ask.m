clc;
clear all;
close all;
ac=5;
a=1;
fc=20;
fs=1000;
t=0:1/fs:2;
b=a*square(2*pi*t)+a;
c=ac*cos(2*pi*fc*t);
s=b.*c;
subplot(5,1,1);
plot(t,b);
title('message signal-22881A04');
xlabel('time');
ylabel('amplitude');
subplot(5,1,2);
plot(t,c);
title('carier signal-22881A04');
xlabel('time');
ylabel('amplitude');
subplot(5,1,3);
plot(t,s);
title('modulated signal-22881A04');
xlabel('time');
ylabel('amplitude');
v=s.*c;
[b,a]=butter(5,fc/fs);
y=filter(b,a,v);
for i=1:length(y);
if y(i)>=1
bk(i)=2;
else
bk(i)=0;
end
end
subplot(5,1,4);
plot(t,y);
title('filter output-22881A04');
xlabel('time');
ylabel('amplitude');
subplot(5,1,5);
plot(t,bk);
title('demodulated output-22881A04');
xlabel('time');
ylabel('amplitude');