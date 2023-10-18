// formatted output
#include <stdio.h>
//#include<conio.h>
int main(){
	float x=3.0,y=12.5, z=523.3 , A=300.0 ,B=1200.5,C=5300.3;
	printf("\n\tx\ty\tz\t=%8.2f|%8.2f|%8.2f",x,y,z); //%8.2  8 field and 2 decimal pace
	printf("\n\tA\tB\tC\t=%8.2f|%8.2f|%8.2f",A,B,C);
	printf("\n\t-------------------------------------------------");
	printf("\n\tx\ty\tz\t=%-8.2f|%-8.2f|%-8.2f",x,y,z);    // - left justified
	printf("\n\tA\tB\tC\t=%-8.2f|%-8.2f|%-8.2f",A,B,C);
	return 0;

}



