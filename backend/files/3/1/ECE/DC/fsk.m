clc;
clear all;
close all;
ac=5;
a=1;
fc=50;
f1=20;
f2=80;
fs=1000;
t=0:1/fs:2;
b=a*square(2*pi*t);
c1=ac*cos(2*pi*f1*t);
c2=ac*cos(2*pi*f2*t);
for i=1:length(b);
if b(i)==1
s(i)=c1(i);
else
s(i)=c2(i);
end
end
subplot(6,1,1);
plot(t,b);
title('message signal-22881A04');
xlabel('time');
ylabel('amplitude');
subplot(6,1,2);
plot(t,c1);
title('carier1 signal-22881A04');
xlabel('time');
ylabel('amplitude');
subplot(6,1,3);
plot(t,c2);
title('carier2 signal-22881A04');
xlabel('time');
ylabel('amplitude');
subplot(6,1,4);
plot(t,s);
title('modulated signal-22881A04');
xlabel('time');
ylabel('amplitude');
v1=s.*c1;
v2=s.*c2;
[b,a]=butter(5,f1/fs);
y1=filter(b,a,v1);
y2=filter(b,a,v2);
y=y1-y2;
for i=1:length(y);
if y(i)>=0
bk(i)=1;
else
bk(i)=-1;
end
end
subplot(6,1,5);
plot(t,y);
title('filter output-22881A04');
xlabel('time');
ylabel('amplitude');
subplot(6,1,6);
plot(t,bk);
title('demodulated output-22881A04');
xlabel('time');
ylabel('amplitude');