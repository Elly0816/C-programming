#include <stdio.h>

// Print the times table from 1 to 12 in the form

/*

1 2 3 4 5 6 7 8 9 ...
2 4 6 8 10 12 14 16 18 ...
3 6 9 12 15 18 21 24 27 ...
.
.
.




*/

int main()
{

    printf("\n");

    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            printf("%4d", i * j);
        }
        printf("\n");
        printf("\n");
    }

    return 0;
}