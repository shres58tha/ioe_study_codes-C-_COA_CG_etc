program calculate
implicit none
! a simple calculator
real :: x,y,z,answer
x=1.5
y=2.5
z=3.5
answer=x+y/z
print *,'result is ',answer
print *,'result (x+y)/(x+y)is ',(x+y)/(x+y)
print *,'result xyz ', x*y*z
print *,'result x pow y pow z ',x**y**z
end program calculate
