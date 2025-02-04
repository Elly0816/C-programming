#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b)
{

    return (*(int *)a - *(int *)b);
}

// Searching Algorithms
// Linear Search

int linear_search(int items[], int size, int item)
{

    for (int i = 0; i < size; i++)
    {
        if (items[i] == item)
        {

            printf("Item: %d found at index: %d", item, i);
            return 0;
        }
    }

    printf("Item not found in the input array");
    return -1;
}

// Binary Search

int binary_search(int items[], int size, int item)
{

    int left = 0, right = size - 1, mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (items[mid] == item)
        {

            printf("The item: %d was found at index: %d using binary search\n", item, mid);
            return 0;
        }
        else if (items[mid] > item)
        {
            right = mid - 1;
        }
        else if (items[mid] < item)
        {
            left = mid + 1;
        }
    }

    printf("Item: %d is not in the array using binary search\n", item);

    return -1;
}

// Exponential search

int exponential_search(int items[], int size, int item)
{
    int lower_bound = 0, upper_bound;
    if (items[lower_bound] == item)
    {
        printf("Item: %d has been found at index: %d", item, lower_bound);
        return 1;
    }

    upper_bound = 1;
    while (upper_bound < size && items[upper_bound] <= item)
    {
        upper_bound = upper_bound * 2;
    }
    lower_bound = upper_bound / 2;

    upper_bound = (upper_bound > size) ? size - 1 : upper_bound;

    return binary_search(items + lower_bound, (upper_bound - lower_bound) + 1, item);
}

//

int main()
{
    const int SIZE = 20000000;
    int *items = (int *)malloc(SIZE * sizeof(int));

    if (items == NULL)
    {
        printf("Memory allocation failed");
        return -1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        items[i] = 10 * (i + 1);
    }

    linear_search(items, SIZE, 190400500);

    qsort(items, SIZE, sizeof(int), compare_int);

    printf("\n");
    binary_search(items, SIZE, 190400500);

    printf("\n");
    exponential_search(items, SIZE, 190400500);
    free(items);
    return 0;
}