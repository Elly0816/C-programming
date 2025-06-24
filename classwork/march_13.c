#include <stdio.h>

char *sayHi()
{

    return "Print Hi.\nThis is ridiculous!";
}

int *arrayofnumbers(int numbers)
{
    int *returnnumbers;

    for (int i = 0; i < numbers; i++)
    {
        *(returnnumbers + i) = (numbers - i) * 2;
    }
    return returnnumbers;
}

int main(void)
{
    char *Hi = sayHi();

    printf(Hi);
    printf("\n");

    int *myNumbers = arrayofnumbers(8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d\n", *(myNumbers + i));
    }

    // printf("%d", myNumbers);
    printf("%f", (float)234 / 4);

    return 0;
}