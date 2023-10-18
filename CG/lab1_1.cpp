#include<stdio.h>
//#include<conio.h>
int main()
{	
	int a,m , i, j ;
	printf("enter the size of flag :");
	scanf ("%d",&a);
	for( m=0; m<2; m++ ){	
		for( i=1;i<a+1;i++){
			for (  j=0;j<i;j++){
				printf("*");			
			}
			printf("\n");
		}
	}	
	printf("*\n\n");
	getchar();
return 0;
}
