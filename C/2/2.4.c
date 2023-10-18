#include<stdio.h>
//#include<conio.h>
// #include<math.h> // not needed

int main(){
	int x0=2, y=0, z0=4, x, z;
	// a
	x=x0 ; z=z0;
	y=x++ + ++x;
	printf ("\n the evaluation of expression y=x++ + ++x is = %d",y);
	printf (" \n x= %d and z =  %d after operation ",x,z);
	printf ("\n-----------------------------------------\n");

	// b
	x=x0 ; z=z0;
	y=++x + ++x;
	printf ("\n the evaluation of expression y=++x + ++x is = %d",y);
	printf (" \n x= %d and z =  %d after operation ",x,z);
	printf ("\n-----------------------------------------\n");
	// c
	x=x0 ; z=z0;
	y=++x + ++x + ++x;
	printf ("\n the evaluation of expression y=++x + ++x + ++x is = %d",y);
	printf (" \n x= %d and z =  %d after operation ",x,z);
	printf ("\n-----------------------------------------\n");
	// d
	x=x0 ; z=z0;
	y=x>y;
	printf ("\n the evaluation of expression y=x>y is = %d",y);
	printf (" \n x= %d and z =  %d after operation ",x,z);
	printf ("\n-----------------------------------------\n");
	// e
	x=x0 ; z=z0;
	y=x>z?x:z;
	printf ("\n the evaluation of expression y=x>z?x:z is = %d",y);
	printf (" \n x= %d and z =  %d after operation ",x,z);
	printf ("\n-----------------------------------------\n");
	// f
	x=x0 ; z=z0;
	y=x&z;
	printf ("\n the evaluation of expression y=x&z is = %d",y);
	printf (" \n x= %d and z =  %d after operation ",x,z);
	printf ("\n-----------------------------------------\n");
	// g
	x=x0 ; z=z0;
	y=x>>2+z<<1;
	printf ("\n the evaluation of expression y=x>>2+z<<1 is = %d",y);
	printf (" \n x= %d and z =  %d after operation ",x,z);
	printf ("\n-----------------------------------------\n");

	return 0;

}

/* OUTPUT

 the evaluation of expression y=x++ + ++x is = 6
 x= 4 and z =  4
-----------------------------------------

 the evaluation of expression y=++x + ++x is = 8
 x= 4 and z =  4
-----------------------------------------

 the evaluation of expression y=++x + ++x + ++x is = 13
 x= 5 and z =  4
-----------------------------------------

 the evaluation of expression y=x>y is = 0
 x= 2 and z =  4
-----------------------------------------

 the evaluation of expression y=x>z?x:z is = 4
 x= 2 and z =  4
-----------------------------------------

 the evaluation of expression y=x&z is = 0
 x= 2 and z =  4
-----------------------------------------

 the evaluation of expression y=x>>2+z<<1 is = 0
 x= 2 and z =  4
-----------------------------------------

*/
