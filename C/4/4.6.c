/* write a program to calculate and print the terms of following series up to nth terms

-10 -12 -14 -18 -26 -42 -74 .............
// complex series after term -12 the difference is in geometric series of 2 pow n
//so treating 12 as a base and -10 as a outlying there is another way to treat this difference
too but coding became complicated and realized that these is a easy way while debugging
*/

/* this series is also in form of t3=2*t2-$t$1 */

#include <stdio.h>
int main() {
   int n1_term=-12,term, n=0,i=1;
   int diff=1;// initialized one as diff calculation is in power series of 2 with first term 1

        printf("enter the n term for which to generate series :");
        scanf("%d",&n);
        term=n1_term;
        while (i<=n){
            if (i==1){printf("\%8d",n1_term+2); i++; continue;}
            if (i==2){printf("\t%8d",n1_term); i++; continue;}
            diff=2*diff;
            //printf("\tdiff = %d",diff);
            term = term - diff;
           // printf("\n\t%8d",n1_term);    printf("\t%8d",n2_term);
            i++;
            //printf ("\nt%d",i);
            printf("\t%8d",term);
            }
return 0;
}
