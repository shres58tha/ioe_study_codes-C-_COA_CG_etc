//working 
#include<stdio.h>
#include<math.h>
#define MAX 100
int main(){
    float axy[MAX][MAX]={0},xp,h,p,yp;
    int i,j,n,index;
    // Input Section 
    printf("Enter number of data? ");
    scanf("%d", &n);
    printf("Enter data: \n");
    for(i = 1; i <=n ; i++) {
        printf("x[%i]=", i);
        scanf("%f", &axy[i][0]); //column of index 0 = x
        printf("y[%d]=", i);
        scanf("%f", &axy[i][1]); //column of index 1 = y
    }
    printf("\nEnter the value of x for which the value of y is wanted: ");
    scanf("%f",&xp);
    h=axy[2][0]-axy[1][0];    // val of x is in first col index starts at 1
    printf("\nh %f\n",h);
    // Generating Forward Difference Table 
    for(i = 1; i <=n; i++) {  // deal column here
        for(j = 1; j <=n-i; j++)  {  // row select
            axy[j][i+1] = axy[j+1][i] - axy[j][i]; //creating diff table and making upper skew traingular matrix
        }
    }
    
    // Displaying Forward Difference Table 
    printf("\nFORWARD DIFFERENCE TABLE\n\n");
    for(i = 1; i <=n; i++) {   // row
        printf("x=%6.2f\ty=%6.2f \tDY=>  ", axy[i][0],axy[i][1]); // xval
        for(j = 2; j <=n-i+1; j++){ //column 0 contain x
            printf("%4.2f\t", axy[i][j]); // yvals
        }
        printf("\n");
    }
    
    for(i=0;axy[i][0]<xp;i++);  //find the index location where x[i] just < xp
    index=i-1;                // index
    p=(xp-axy[1][0])/h; 
    //p=(xp-axy[index][0])/h; 
    //carrying interpolation      
    float nr=1.0, dr=1.0; // numerator and denominator
    yp=axy[1][1]; // for summing the interpolate get val of y
    //yp=axy[index][1];
    printf("\nindex %d ;xp %.1f ;axp %.1f ;p  %.1f\n",index,xp,axy[1][0],p);
    for(i=1;i<=n;i++){
        nr *=p-i+1;
        dr *=i;           //factorial
        yp +=(nr/dr)*axy[1][i+1];    // i=0 ->x ;i=1 ->y ; i>=2 gives del^n y
        //yp +=(nr/dr)*axy[index][i+1];   
    }      
    printf("\nWhen x = %6.1f, corresponding yp = %6.2f\n",xp,yp);
    return 0;
}
