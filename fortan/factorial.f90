
program factorial  
implicit none  

   ! define variables
   integer :: nfact = 1   
   integer :: n = 1 
   
   ! compute factorials   
   do 222 n=1, 16      
      nfact = nfact * n 
      print*,  n, " ", nfact   
    
 222  continue
end program factorial 
