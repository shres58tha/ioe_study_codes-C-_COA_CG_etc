% bilineat Transform
% e) convert the analog filter into digital IIR filter by bilinear transformation
% f) Plot the frequency response of transformation filter by bilinear transformation
% g) Plot the step response of LTI model
% h) Step response of discrete time linear system

clc; close all; clear;

b = [1 0.1];
a = [1 .2  9 .01];

[bz,az]= bilinear(b,a,2);
freqs(bz,az);
title('frequency response by bilinear transformation, umeshbei029');

figure;
dimpulse(bz,az);
title('impulse response plot in z domain, umeshbei029');

figure;
sys = tf(b,a);
step(sys);
title(' step response plot of LTI system, umeshbei029 ');

figure;
dstep(bz, az);
title(' step response plot for discrete time linear sytem, umeshbei029');
