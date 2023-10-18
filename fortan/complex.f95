//
! program for complex number equation
program cmplx
    implicit none
    integer x, y
    complex a, b, c, result 
1   format ("enter two complex numbers format (real,img)")
    write (*,1) 
    read *, a,b
    write (*,*) "sum", a+b
    write (*,*) "dividing", a/b
    write (*,*) "diff", a-b
    write (*,*) "prod", a*b
    write (*,*) "pow", a**b 
    print *,
        

        
end program cmplx
