%continuous n discrete ramp  signal 
clc; close all; clear all;
i=1;
for t=-2:0.001:2
   if (t>=0)
      x(i)=t;
   else
       x(i)=0;
   end;
   i=i+1;
end;
t= -2:0.001:2;
subplot(2,1,1)
plot(t,x)
grid on;
xlabel('time'); ylabel('amplitude');
title('ramp, umesh076bei029')
clear all;

i=1;
for t=-2:0.1:2
   if (t>=0)
      x(i)=t,
   else
       x(i)=0;
   end;
   i=i+1;
end;
t= -2:0.1:2;
subplot(2,1,2)
stem(t,x)
grid on;
xlabel('time'); ylabel('amplitude');
title('ramp discrete, umesh076bei029')
clear all;