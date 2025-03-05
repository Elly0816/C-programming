#include <stdio.h>

// Reverse a number

int reverse(int number)
{

    int new_number = 0;

    while (number)
    {

        int remainder = number % 10;
        new_number = (new_number * 10) + remainder;
        number = number / 10;
    }
    return new_number;
}

int main()
{
    int number, reversed;
    int valid_number = 0;

    printf("Enter a number: ");
    while (!valid_number)
    {
        if (scanf("%d", &number) != 1)
        {
            printf("\nPlease enter a valid number: ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            valid_number = 1;
        }
    }

    reversed = reverse(number);

    printf("%d reversed is %d", number, reversed);

    return 0;
}