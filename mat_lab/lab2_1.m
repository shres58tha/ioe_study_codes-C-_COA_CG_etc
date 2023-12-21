%construct a sine wave having amplitude 5 unit and frequency 3 Hz
%add noise and then plot resulting signal
clc; close all; clear all;
a=5; f=3;
t=0:0.001:1;

x=a*sin(2*pi*f*t);
subplot(3,1,1);
plot(t,x);
xlabel('time');
ylabel('amplitude');
title('sine, umesh076bei029');
grid on;

z= rand(1,length(t));  %z=rand(1,size(x))
subplot(3,1,2)
plot(t,z,'RED');
xlabel('time');
ylabel('amplitude');
title('noise, umesh076bei029');
grid on;

a=x+z;
subplot(3,1,3);
plot(t,a,'RED');
xlabel('time');
ylabel('amplitude');
title('noise + sine wave, umesh076bei029');
grid on;