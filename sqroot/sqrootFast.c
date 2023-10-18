/* Assumes that float is in the IEEE 754 single precision floating point format */
#include <stdint.h>
#include <stdio.h>
float sqrt_approx(float z)
{
	union { float f; uint32_t i; } val = {z};	/* Convert type, preserving bit pattern */
	/*
	 * To justify the following code, prove that
	 *
	 * ((((val.i / 2^m) - b) / 2) + b) * 2^m = ((val.i - 2^m) / 2) + ((b + 1) / 2) * 2^m)
	 *
	 * where
	 *
	 * b = exponent bias
	 * m = number of mantissa bits
	 */
	val.i -= 1 << 23;	/* Subtract 2^m. */
	val.i >>= 1;		/* Divide by 2. */
	val.i += 1 << 29;	/* Add ((b + 1) / 2) * 2^m. */

	return val.f;		/* Interpret again as float */
}

int main(){
    int num;
    printf("\n enter a num  ");
    scanf("%d",&num);
    printf("\n integral sq root of %d is : %f \n",num, sqrt_approx(num));
    printf("\n");
    return 0;
    getchar();
}
