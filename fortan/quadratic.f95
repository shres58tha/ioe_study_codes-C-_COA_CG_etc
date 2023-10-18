! program to solve quadratic equation
program quadratic
    print *, "input coefficeient a, b, c"
    read *, a,b,c
    d=b**2-4*a*c
    if (d) 222,333,444   ! three types of if in fortran if arthematic is used here .lt.0 222 .eq.0 333 and .gt.0 444
    
222     print *, 'roots are imagianary' 
        rp=-b/(2*a)
        emg=sqrt (-d)/(2*a)
        ! d is already negative if (arthematic jumps to here)
        ! first seven characters of each line has special meaning in fortan 77 must start with no or comment lindicator c but in fortan 95 above it is relaxed
        ! characters in senternce see to have limit too 
        print *, '(',rp,', ±',emg,')' 
        stop 

333     print *, 'roots are real and equal'
        x1=-b/(2*a)
        print *, x1, x1
        stop
        ++
444     print *, 'roots are real and unequal'
        x1=(-b + sqrt(d))/(2*a)
        print *, x1,(-b - sqrt(d))/(2*a)
        stop
        
end program quadratic
