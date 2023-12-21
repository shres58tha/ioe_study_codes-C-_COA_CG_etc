%continuous n discrete rectangular signal 
clc; close all; clear all;
i=1;
for t=-2:0.001:2
   if (abs(t)>1)
      x(i)=0;
   else
       x(i)=1;
   end;
   i=i+1;
end;
t= -2:0.001:2;
subplot(2,1,1)
plot(t,x)
grid on;
xlabel('time'); ylabel('amplitude');
title('rectangular pulse, umesh076bei029')
clear all;

i=1;
for t=-2:0.1:2
   if (abs(t)>1)
      x(i)=0,
   else
       x(i)=1;
   end;
   i=i+1;
end;
t= -2:0.1:2;
subplot(2,1,2)

stem(t,x)
grid on;
xlabel('time'); ylabel('amplitude');
title('rectangular discrete pulse, umesh076bei029')
clear all;