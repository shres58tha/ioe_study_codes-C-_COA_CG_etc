program loop
    implicit none
    integer :: i
    real :: y
    do i=-10,0
    y=1.0/i;
    print *,y
    end do

    print *,'inf*0',y*0
end program loop
