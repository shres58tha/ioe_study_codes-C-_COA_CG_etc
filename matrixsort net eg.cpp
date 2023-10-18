#include <stdio.h>
#include <stdlib.h>

#define n 3

int main()
{
    int arr[n][n] = {{9,8,2},{4,5,1},{6,7,3}},min,i,j,tmp,y,k,w,z=0,q=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            z = i;
            q = j;
            min=arr[i][j];
            w=j;
            for(k=i;k<n;k++)
            {
                for(;w<n;w++)
                if(arr[k][w]<min)
                {
                    min=arr[k][w];
                    z=k;
                    q=w;
                }
                w=0;
            }
            tmp=arr[i][j];
            arr[i][j]=min;
            arr[z][q]=tmp;
        }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    return 0;
}
