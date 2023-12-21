%constructuous n discrete unit impulse signal 
clc; close all; clear all;
i=1;
t=-2:0.01:2
for t
   if (t>=0)
      x(i)=1;
   else
       x(i)=0;
   end;
   i=i+1;
end;

subplot(2,1,1)
plot(t,x)
grid on;
xlabel('time'); ylabel('amplitude');
title('delta impulse, umesh076bei029')

subplot(2,1,2)
stem(t,x)
grid on;
xlabel('time'); ylabel('amplitude');
title('delta impulse, umesh076bei029')
clear all;