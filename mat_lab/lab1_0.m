clc; close all; clear all;
a=5; f=4;
t=0:0.01:1;
x=a*cos(2*pi*f*t);
plot(t,x);
xlabel('time');
ylabel('amplitude');
title('coswave, Sujit.076bei027');
grid on;