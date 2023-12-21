clc; close all; clear all;
a=5; f=4;
t=0:0.02:1;
x=a*cos(2*pi*f*t);
stem(t,x);
xlabel('time');
ylabel('amplitude');
title('stem plot, Umesh.076bei029');
grid on;