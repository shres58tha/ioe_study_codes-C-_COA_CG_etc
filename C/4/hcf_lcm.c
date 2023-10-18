
#include <stdio.h>
#define block 2
                // block switch for alternate codes
                // 1 simple code generating lcm first
                // 2 code generates hcf first
                // 3 geneerates hcf from hand operating way should be the fastest algorithm
#if (block == 1)
int main() {
    int n1, n2, lcm;
    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);
    // maximum number between n1 and n2 is stored in lcm
    lcm = (n1 > n2) ? n1 : n2;
    while (1) {
        if (lcm % n1 == 0 && lcm % n2 == 0) {
            printf("The LCM of %d and %d is %d.", n1, n2, lcm);
            break;
        }
        ++lcm;
    }
    return 0;
}

*/
#endif

#if (block == 2)
#include <stdio.h>
int main() {
    int n1, n2, i, hcf, lcm;
    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);
    for (i = 1; i <= n1 && i <= n2; ++i) {
        // check if i is a factor of both integers
        if (n1 % i == 0 && n2 % i == 0)
            hcf = i;
    }
    lcm = (n1 * n2) / hcf;
    printf("\nThe LCM of two numbers %d and %d is %d.", n1, n2, lcm);
    printf("\nThe HCF of two numbers %d and %d is %d.", n1, n2, hcf);
    printf("\n");
    return 0;
}
#endif

#if (block == 3)
#include <stdio.h>
int main() {
  int a, b, x, y, t, hcf, lcm;

  printf("Enter two integers\n");
  scanf("%d%d", &x, &y);

  a = x;
  b = y;

  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }

  hcf = a;
  lcm = (x*y)/hcf;

  printf("Greatest common divisor of %d and %d = %d\n", x, y, hcf);
  printf("Least common multiple of %d and %d = %d\n", x, y, lcm);

  return 0;
}
#endif
