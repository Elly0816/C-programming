#include <stdio.h>
#include <string.h>

int main(void)
{

    char name[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%c", &name[i]);
        while (getchar() != '\n')
            ;
        printf("\n%c", name[i]);
    }

    return 0;
}