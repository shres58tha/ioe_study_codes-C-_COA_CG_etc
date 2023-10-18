#include<stdio.h>
#include<conio.h>
int main (){
//clrscr();
int i,j;
for(i=0;i<5;i++){
	for( j=0;j<5;j++){
		if( ( (i==1|i==3) & j==2) | (i==2 & (j==1|j==3) ) )
			printf(" ");
		else 
			printf("*");
	}
	printf("\n");
}
 getchar();
 return 0;
}
