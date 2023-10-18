PROGRAM    Fibonacci
   IMPLICIT   NONE
   INTEGER :: FIRST, SECOND, TEMP, IX
   FIRST = 0
   SECOND = 1
   TEMP = FIRST
   
   DO while (temp <=500)
      
      WRITE (*,*) TEMP
      TEMP = FIRST + SECOND
      FIRST = SECOND
      SECOND = TEMP
      
   END DO
END PROGRAM Fibonacci

