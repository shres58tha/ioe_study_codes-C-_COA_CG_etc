% H(s) = (s+0.1)/((s+0.1)^2+9)
% impulse invariance 
% a) convert the analog filter into digital IIR filter by means of impulse
% invariance method
% b) plot the frequency response in S-domain and z-domain
% c) Plot impulse respomse of LTI system
% d) Plot impulse response in z-do

clc; close all; clear;
a=1; f=1;fs=200;
w=2*pi*(f/fs);
t=0:0.001:1024;
x=a*sin(w*t);
subplot(2,1,1);
plot(t,x)
title('sine, umesh076bei029');
xlabel('t');ylabel('y(t)');
grid on;
y=xcorr(x);
%size(y)
%size(t)
subplot(2,1,2);
t=0:0.001:2048;
plot(t,y);
xlabel('t');ylabel('y(t)');
title('autocorr, umesh076bei029');
grid on;
