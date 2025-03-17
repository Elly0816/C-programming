#include <stdio.h>
#include <stdlib.h>

int sum(int *, int);

float average(int, int);

int *items(int);

int main(void)
{
    int grades[] = {70, 85, 65, 98, 88, 67};
    int total = sum(grades, 6);
    float avg = average(total, 6);

    printf("The total of all grades is: %d", total);
    printf("\n");
    printf("The average is: %.2f", avg);

    int *array = items(6);

    for (int i = 0; i < 6; i++)
    {
        printf("\nThe array value at address %p is %d", &array[i], array[i]);
    }

    return 0;
}

int sum(int *grades, int SIZE)
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += *(grades + i);
    }

    return sum;
}

float average(int sum, int count)
{
    return (float)sum / count;
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