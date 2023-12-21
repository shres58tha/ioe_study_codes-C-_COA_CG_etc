% H(s) = (s+0.1)/((s+0.1)^2+9)
% impulse invariance
% a) convert the analog filter into digital IIR filter by means of impulse
% invariance method.
% b) plot the frequency response in S-domain and z-domain.
% c) Plot impulse respomse of LTI system.
% d) Plot impulse response in z-domain.

clc; close all; clear;

b = [1 0.1];
a = [1 .2  9 .01];
figure;
freqs(b,a);
title('frequency response plot, umeshbei029');
figure;
subplot(4,1,1);
impulse(b,a);
title('impulse response plot, umeshbei029');

[bz,az]= impinvar(b,a,2);

subplot(4,1,2);
dimpulse(bz,az);
[bz,az]= impinvar(b,a,10);

subplot(4,1,3);
dimpulse(bz,az);

[bz,az]= impinvar(b,a,20);
subplot(4,1,3);
dimpulse(bz,az);
