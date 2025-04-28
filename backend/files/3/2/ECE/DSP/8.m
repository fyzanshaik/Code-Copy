clc;
clear all;
close all;
x=[1 2 3 4]
h=[2 3]
l1=length(x)
l2=length(h)
N=max(l1,l2)
x1=[x,zeros(1,N-l1)]
h1=[h,zeros(1,N-l2)]
%DFT
for k=0:N-1
for n=0:N-1
w(k+1,n+1)=exp(-j*2*pi*n*k/N);
end
end
xk=x1*w
display(xk)
hk=h1*w
display(hk)
yk=xk.*hk
%IDFT
for n=0:N-1
for k=0:N-1
iw(n+1,k+1)=exp(j*2*pi*n*k/N);
end
end
xn=[yk*iw]/N;
display(xn)
yconv=cconv(x,h,N)
display(yconv)


---------------------------------------------------------------------------------------------


%LINEAR CONV:
clc;
clear all;
close all;x=[1 2 3 4]
h=[2 3]
l1=length(x)
l2=length(h)
N=l1+l2-1
x1=[x,zeros(1,N-l1)]
h1=[h,zeros(1,N-l2)]
%DFT
for k=0:N-1
for n=0:N-1
w(k+1,n+1)=exp(-j*2*pi*n*k/N);
end
end
xk=x1*w
display(xk)
hk=h1*w
display(hk)
yk=xk.*hk
%IDFT
for n=0:N-1
for k=0:N-1
iw(n+1,k+1)=exp(j*2*pi*n*k/N);
end
end
xn=[yk*iw]/N;
yconv=cconv(x,h)
display(yconv)