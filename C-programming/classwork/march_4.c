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
    int number = 2943768, reversed;

    reversed = reverse(number);

    printf("%d reversed is %d", number, reversed);

    return 0;
}