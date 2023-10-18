//series sum n=f(x)
#include <stdio.h>
int fac(int n){
    int ret_val=1;
    for (int i=1;i<=n;i++)
        ret_val*=i;
    return ret_val;
}
int pwr(int x, int n){
    int ret_val=1;
    for (int i=1;i<=n;i++)
        ret_val*=x;
   return ret_val;
}
int main (){
    int x,n;
    float sum=0,term;
    printf("\nenter no of terms n ad value of x: ");
    scanf ("%d %d",&n,&x);
    for (int i=0;i<n;i++){
        term =pwr(-1,i)*pwr(x,2*i)/(float)fac(2*i); // casting because dividing int givees float most of time
        printf("%+f   ",term);
        //sum+=term;
    }
    printf("\n"); 
    //printf("\nsum of %d terms with value of x=%d is : %f\n",n,x,sum);  
    return 0;
}

