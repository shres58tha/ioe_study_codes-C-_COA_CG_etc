program ramagic2      
implicit none
real , dimension(10) :: x
integer :: i
do i=1,10
  x(i)=i/10.0
end do       
print *,'cos(x) = ',cos(x)
print *,'sin(x) = ',sin(x)

end program ramagic2
