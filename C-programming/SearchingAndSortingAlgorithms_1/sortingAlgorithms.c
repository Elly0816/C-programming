#include <stdio.h>
#include <stdlib.h>

// Insertion Sort
int selection_sort(int array[], int size)
{
    // start from the 0th index
    // Check if the next index is contains a smaller value
    // if it does set the start index to that and start scanning the next indexes
    // WHen at the end of the list, move the smallest element to the first index, and continue from the next index
    if (!array || size <= 0)
        return -1;

    for (int i = 0; i < size; i++)
    {
        int min_idx = i;

        for (int j = min_idx + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            int temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;
        }
    }
    printf("The sorted array is: [ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printf(" ]");

    return 0;
}

int main()
{
    const int SIZE = 5;

    int *array = (int *)malloc(SIZE * sizeof(int));

    if (array == NULL) // Always check if memory allocation was successful
    {
        printf("Memory allocation failed");
        return -1;
    }
    array[0] = 23;
    array[1] = 15;
    array[2] = 50;
    array[3] = 36;
    array[4] = 21;

    // for (int i = 0; i < SIZE; i++)
    // {
    //     array[i] = (i + 1) * 3;
    // }

    printf("The original array is: [ ");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d, ", array[i]);
    }
    printf(" ]");

    selection_sort(array, SIZE);

    free(array); // Always remember to free the memory on the heap
    return 0;
}
