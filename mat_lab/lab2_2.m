%continuous n discrete unit impulse signal
clc; close all; clear all;
i=1;
for t=-2:0.001:2
   if (t==0)
      x(i)=1;
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
title('delta impulse, umesh076bei029')
clear all;

i=1;
for t=-2:0.001:2
   if (t==0)
      x(i)=1,
   else
       x(i)=0;
   end;
   i=i+1;
end;
t= -2:0.001:2;
subplot(2,1,2)
stem(t,x)
grid on;
xlabel('time'); ylabel('amplitude');
title('delta impulse, umesh076bei029')
clear all;
