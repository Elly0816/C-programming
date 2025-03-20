#include <stdio.h>
#include <stdlib.h>

int sum(int[], int);

float average(int, int);

int *items(int);

long long unsigned factorial(int);

long long unsigned fibonacci(int);

int main(void)
{
    int grades[] = {70, 85, 65, 98, 88, 67};
    int total = sum(grades, 6);
    float avg = average(total, 6);
    int find_factorial_of = 44;
    int find_fibonacci_of = 15;

    printf("The total of all grades is: %d", total);
    printf("\n");
    printf("The average is: %.2f", avg);

    int *array = items(6);

    for (int i = 0; i < 6; i++)
    {
        printf("\nThe array value at address %p is %d", &array[i], array[i]);
    }

    free(array);
    array = NULL;
    printf("\n\nFactorial of %d is %llu", find_factorial_of, (long long unsigned)factorial(find_factorial_of));
    printf("\nThe %d term fibonacci sequence is: ", find_fibonacci_of);

    // long long unsigned my_fib = fibonacci(find_fibonacci_of);

    // printf("%llu, ", my_fib);

    // for (int i = find_fibonacci_of; i < 1; i--)
    // {
    //     printf("%llu, ", (long long unsigned)fibonacci(find_fibonacci_of));
    // }
    return 0;
}

int sum(int grades[], int SIZE)
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += grades[i];
    }

    return sum;
}

float average(int sum, int count)
{
    printf("%.2f", (float)sum / count);
    // return (float)sum / count;
}

int *items(int SIZE)
{

    int *array = (int *)malloc(SIZE * sizeof(int));

    if (array == NULL)
    {
        printf("Error creating the array");
        return (int *)1;
    };

    for (int i = 0; i < SIZE; i++)
    {
        *(array + i) = i + 1;
    }

    return array;
}

long long unsigned factorial(int number)
{
    if (number <= 0)
    {
        return -1;
    }

    if (number == 1)
    {
        return 1;
    }

    return number * factorial(number - 1);
}

// long long unsigned fibonacci(int number)
// {

//     if (number <= 1)
//     {
//         printf("Fibonacci of %d is %d", number, number);
//         return number;
//     }

//     int fib_1 = fibonacci(number - 1);
//     int fib_2 = fibonacci(number - 2);
//     int result = fib_1 + fib_2;

//     printf("Fibonacci of %d is %d", number, result);

//     return fibonacci(number - 1) + fibonacci(number - 2);
// }