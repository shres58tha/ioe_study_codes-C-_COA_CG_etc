#include<stdio.h>
#include<math.h>
#define f(x,y) (sin(x)+cos(y))

int main() {
    float x0, y0, xn, h, yn, m;
    int i, n;
    printf("Enter Initial Condition (x0, y0) :");
    scanf("%f%f", &x0, &y0);
    printf("Enter calculation point xn :");
    scanf("%f", &xn);
    printf("Enter number of steps : ");
    scanf("%d", &n);

    h = (xn-x0)/n;
 
    printf("\nx0\t\ty0\t\tslope\t\tyn\n");  // Euler's Method 
  
    for(i=0; i < n; i++) {
        m = f(x0, y0);
        yn = y0 + h * m;
        printf("%f\t%f\t%f\t%f\n",x0,y0,m,yn);
        y0 = yn;
        x0 = x0+h;
    }
     printf("%f\t%f\n",x0,y0);

    printf("\nValue of y at x = %f is %f \n",xn, yn);
    return 0;
}


/* OUTPUT

Enter Initial Condition (x0, y0) :0 3.14159
Enter calculation point xn :2
Enter number of steps : 5

x0              y0              slope           yn
0.000000        3.141590        -1.000000       2.741590
0.400000        2.741590        -0.531642       2.528933
0.800000        2.528933        -0.100766       2.488627
1.200000        2.488627        0.137754        2.543728
1.600000        2.543728        0.173034        2.612942
2.000000        2.612942
Value of y at x = 2.000000 is 2.612942 
**********************************************************
Enter Initial Condition (x0, y0) :0 3.14159
Enter calculation point xn :2
Enter number of steps : 10

x0              y0              slope           yn
0.000000        3.141590        -1.000000       2.941590
0.200000        2.941590        -0.781397       2.785311
0.400000        2.785311        -0.547782       2.675754
0.600000        2.675754        -0.328803       2.609994
0.800000        2.609994        -0.144642       2.581065
1.000000        2.581065        -0.005504       2.579965
1.200000        2.579965        0.085650        2.597095
1.400000        2.597095        0.130062        2.623107
1.600000        2.623107        0.131003        2.649307
1.800000        2.649307        0.092592        2.667826
2.000000        2.667826
Value of y at x = 2.000000 is 2.667826 


*/
