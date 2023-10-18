#include <stdio.h>
#include <stdint.h>
#include <assert.h>
int32_t isqrt(int32_t n) {
    assert(("sqrt input should be non-negative", n > 0));

    // Xₙ₊₁
    int32_t x = n;

    // cₙ
    int32_t c = 0;

    // dₙ which starts at the highest power of four <= n
    int32_t d = 1 << 30; // The second-to-top bit is set.
                         // Same as ((unsigned) INT32_MAX + 1) / 2.
    while (d > n)
        d >>= 2;

    // for dₙ … d₀
    while (d != 0) {
        if (x >= c + d) {      // if Xₘ₊₁ ≥ Yₘ then aₘ = 2ᵐ
            x -= c + d;        // Xₘ = Xₘ₊₁ - Yₘ
            c = (c >> 1) + d;  // cₘ₋₁ = cₘ/2 + dₘ (aₘ is 2ᵐ)
        } else {
            c >>= 1;           // cₘ₋₁ = cₘ/2      (aₘ is 0)
        };
        d >>= 2;               // dₘ₋₁ = dₘ/4
    };
    return c;                  // c₋₁
}


int main(){
    int num;
    printf("\n enter a num  ");
    scanf("%d",&num);
    printf("\n integral sq root of %d is : %d \n",num, isqrt(num));
    printf("\n");
    return 0;
    getchar();
}
