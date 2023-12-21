% Q2  Design Butterworth low pass filter using following specifications
% passband attunation <= 1dB
% Stop band Attenuation <= 30 dB
% stop band edge = 800 Hz
% Passband edge = 400 Hz
% sample rate = 2 KHz
% a) find its order
% b) plot frequency response
% c) Plot poles and zeros
% d) Plot impulse response
% e) Convert the filter into IIR filter by impulse invarianvce method
% f) Plot frequency response in z- domain
% g) plot impulse response in z- domain
% h) step response of discrete time linear system


close all; clear;
wp = 400/2000;
ws = 800/2000;
rp = 4;
rs = 30;
[n,wn] = buttord(wp,ws,rp,rs);
[b,a]= butter(n,wn);
sys = tf(b,a);
figure;
freqs(b,a);
title('frequency response, umesh29');
figure;
pzmap(sys);
title('poles and zeros, umesh29');
figure;
impulse(b,a);
[bz,az] = impinvar(b,a,10);
figure;
dimpulse(bz,az);
figure;
dstep(bz,az);
chebyshev1;
clc;
