#include<stdio.h>
//display aug matrix
void display( float aug[3][4]){
    for (int i=0;i<3;i++){
        for (int j=0; j<4;j++){
            printf ("\t%8.3f",aug[i][j]);
        }
    printf ("\n");    
    }
}
int main(){
    float x,y,aug[3][4]={0};
    int n;
    printf("Enter no of data points: ");
    scanf("%d",&n);
    aug[0][0]=n;
    printf("Enter the values:\n");
    for(int i=1;i<=n;i++){
        float temp;
        printf("Enter x[%d], y[%d]: ",i,i);
        scanf("%f%f",&x,&y);
        
        aug[0][1] +=  x;     // sum(x)
        aug[0][3] +=  y;     // sum(y)
        aug[1][3] +=x*y;     // sum(xy)
        
        temp =x*x;                   // temp == x*x
        aug[0][2] += temp;   // sum(x^2)
        aug[2][3] +=temp*y;  // sum(x^2*y)
        
        temp *=x;                    // temp == x*x*x
        aug[1][2] += temp;   // sum(x^3)
        temp *=x;                    // temp == x*x*x*x
        aug[2][2] += temp;   // sum(x^4)
        //display(aug);
    }
    aug[1][0]=aug[0][1];
    aug[2][0]=aug[1][1]=aug[0][2];
    aug[2][1]=aug[1][2];
    printf("Aug matrix\n");
    display(aug);            //display aug matrix
    
    //solve by gauss jordan method
    for(int op=0;op<3;op++){ // R1
        for(int  row=0; row<3; row++){ // select R2  opreate all rows
            if(op!= row) {
                float ratio = aug[row][op]/aug[op][op];
                for(int col=0;col<3+1;col++){ // OPERATING R2--> R2-A21/A11*R2 opreate all rows
                    aug[row][col] -= ratio*aug[op][col];
                }
            }
        }
    }
    /*
    printf("solved\n");
    display(aug);
    // Obtaining Solution 
    //*/
    for(int row=0;row<3;row++){
        aug[row][3]=aug[row][3]/aug[row][row];   // for putting aug matrix in proper form
        aug[row][row]=1;
    }
    /*
    printf("Solution matrix\n");
    display(aug);
    //*/
    printf("\nthe fitted parabolic eqn is\n\t\ty = %f + %f x + %f x^2\n",aug[0][3],aug[1][3],aug[2][3]);
return 0;  
}
