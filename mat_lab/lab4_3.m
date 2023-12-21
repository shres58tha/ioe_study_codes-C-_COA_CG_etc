% Q2  Design Chebyshev1 low pass filter using following specifications

% Q3  Design Chebyshev2 low pass filter using following specifications


% passband attunation <= 1dB
% Stop band Attenuation <= 15 dB
% stop band edge frequency = 0.3* pi rad /s
% Passband edge frequency = 0.2* pi rad /s

% a) find its order
% b) plot frequency response
% c) Plot poles and zeros
% d) Plot impulse response
% e) Convert the filter into IIR filter by impulse invarianvce method
% f) Plot frequency response in z- domain
% g) plot impulse response in z- domain
% h) step response of discrete time linear system


close all; clear;
wp = .2*pi;
ws = 0.3*pi;
rp = 1;
rs = 15;
[n,wn] = cheb1ord(wp,ws,rp,rs);
[b,a]= cheby1(n,wn);
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
