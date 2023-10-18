 
program readdata
implicit none
!reads data from a file called mydata.txt
integer :: x,i
    open(10,file='evenodd.txt')
    do i=1,10
    read(10,*) x
    if (mod(x,2).gt.0) then
              print *, x , ' is odd'
          else
              print *, x , ' is even'
          end if  
    end do
end program readdata
