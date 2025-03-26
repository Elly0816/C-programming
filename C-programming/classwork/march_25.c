#include <stdio.h>

void bubble_sort(int *, int);

void print_array(int *, int);

void insertion_sort(int *, int);

int main(void)
{

    int numbers[] = {98, 65, 59, 53, 25, 56, 8, 55, 94, 6, 41, 60, 30, 26, 17, 92, 12, 95, 4, 73};

    int size = sizeof(numbers) / sizeof(int);

    printf("Unsorted Array: ");
    print_array(numbers, size);
    printf("\n");
    // bubble_sort(numbers, size);
    insertion_sort(numbers, size);
    printf("Sorted Array: ");
    print_array(numbers, size);

    return 0;
}

void bubble_sort(int *numbers, int size)
{
    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j + 1];
                numbers[j + 1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

void insertion_sort(int *numbers, int size)
{
    /*

    Loop through the entire array;
        Keep track of current index;
        while the value at the next index is less than that at the current index and the current index is no less than 0(start of array);
            swap the value at the current index with that at the next index;
            backtrack
    */

    for (int i = 0; i < size - 1; i++)
    {
        int j = i;
        while (j >= 0 && numbers[j + 1] < numbers[j])
        {
            // if (j >= 0)
            // {
            int temp = numbers[j];
            numbers[j] = numbers[j + 1];
            numbers[j + 1] = temp;
            j--;
            // }
            // else
            // {
            //     break;
            // }
        }
    }
}

void print_array(int *array, int size)
{
    if (size == 1)
    {
        printf("{%d}", array[0]);
    }
    else
    {

        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {

                printf("{%d, ", array[i]);
            }
            else if (i == size - 1)
            {

                printf("%d} ", array[i]);
            }
            else
            {
                printf("%d, ", array[i]);
            }
        }
    }
}