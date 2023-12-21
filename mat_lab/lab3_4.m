%two discrete signals are given as h[n] ={1,(2),1,-1}
%x[n]={(1).2,3,1}. plot these two signals
% a without using convolution function
% b with convolution function

clc; close all; clear all;
h=[1 2 1 -1];
nh=[-1 0 1 2 ];
x=[1 2 3 1];
nx=[0 1 2 3];
X=[x, zeros(1,length(h))];
H=[h, zeros(1, length(x))];
n1=length(x);
n2=length(h);

for n=  1:n1+n2-1
    y(n)=0;
    for k=1:n1
        if((n-k+1)>0)
            y(n)=y(n) +X(k)*H(n-k+1);
        end
    end
end
n=min(nh)+min(nx):max(nh)+max(nx);
stem(n,y);
xlabel('n'); ylabel('y[n]');
title('without using convolution function. umesh076bei029')
grid on;
clear all;
