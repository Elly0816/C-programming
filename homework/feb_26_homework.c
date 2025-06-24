#include <stdio.h>

int main()
{

    int x = 15, y = 11;
    int bitwise_right = x >> 5, bitwise_left = y << 4, bitwise_xor = y ^ x, bitwise_or = x | y, bitwise_negate = ~(y & x);

    printf("Performing a bitwise right shift of 5 on 15 (x>>5) would give: %d", bitwise_right);

    printf("\n\nPerforming a bitwise left shift of 4 on 11 (y<<4) would give: %d", bitwise_left);

    printf("\n\nPerforming a bitwise exclusive or on 11 and 15 (y^x) would give: %d", bitwise_xor);

    printf("\n\nPerforming a bitwise or on 15 and 11 (x|y) would give: %d", bitwise_or);

    printf("\n\nNegating the result of a bitwise and operation between 15 and 11 ~(y&x) would give: %d\n\n", bitwise_negate);

    return 0;
}