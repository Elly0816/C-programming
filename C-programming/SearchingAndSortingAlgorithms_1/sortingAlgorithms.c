#include <stdio.h>
#include <stdlib.h>

// Try implementing the searching algorithms on your own

const int SIZE = 500;

const int value = 480;

// Linear search

int linear_search(int items[], int size, int item)
{
    for (int i = 0; i < size; i++)
    {
        if (items[i] == item)
        {
            printf("Found the item: %d at index %d\n", item, i);
            return i;
        }
    }
    printf("Item %d is not in the array", item);
    return -1;
}

// Binary Search

int binary_search(int array[], int size, int item)
{
    int left = 0, right = size - 1, mid;

    if (!array || size <= 0)
    {
        return -1;
    }

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (array[mid] == item)
        {
            printf("The item %d was found at index %d using binary search", item, mid);
            return mid;
        }
        else if (array[mid] < item)
        {
            left = mid + 1;
        }
        else if (array[mid] > item)
        {
            right = mid - 1;
        }
    }
    printf("The item %d is not in the array", item);
    return -1;
}

// Exponential Search

int exponential_search(int array[], int size, int value)
{
    int lower_bound = 0, upper_bound = 1;

    if (array[0] == value)
    {
        printf("The value %d was found at index 0", value);
        return 0;
    }

    while (array[upper_bound] < value && upper_bound < size)
    {
        upper_bound = upper_bound * 2;
    }
    lower_bound = upper_bound / 2;
    upper_bound = upper_bound > size - 1 ? size - 1 : upper_bound;

    return binary_search(array + lower_bound, (upper_bound - lower_bound) + 1, value);
}

int compare_values(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{

    int *array = (int *)malloc(SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = (i + 1) * 2;
    }

    // for (int i = 0; i < SIZE; i++)
    // {
    //     printf("The value in the index %d is: %d\n\n", i, array[i]);
    // }

    linear_search(array, SIZE, value);
    qsort(array, SIZE, sizeof(int), compare_values);
    printf("\n");
    binary_search(array, SIZE, value);

    printf("\n");
    exponential_search(array, SIZE, value);

    free(array);
    return 0;
}