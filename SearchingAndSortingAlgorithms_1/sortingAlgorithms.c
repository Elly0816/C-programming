#include <stdio.h>
#include <stdlib.h>

int printArray(int array[], int SIZE)
{

    if (array == NULL || SIZE == 0)
        return -1;

    printf("[ ");
    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
        {

            printf("%d", array[i]);
        }
        else
        {

            printf("%d, ", array[i]);
        }
    }
    printf(" ]\n");
    return 0;
}

// Insertion Sort
int selection_sort(int array[], int size)
{

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
    printf("The sorted array is: ");
    printArray(array, size);

    return 0;
}

int merge(int array[], int start, int mid, int end)
{
    int *left = (int *)malloc((mid - start + 1) * sizeof(int));
    int *right = (int *)malloc((end - mid) * sizeof(int));

    if (left == NULL || right == NULL)
        return -1;

    int i = 0;
    int j = 0;
    int k = start;

    // int n_left = sizeof(left) / sizeof(int);
    int n_left = mid - start + 1;
    // int n_right = sizeof(right) / sizeof(int);
    int n_right = end - mid;

    for (i = start; i < n_left; i++)
    {
        left[i] = array[i];
    }
    for (j = 0; j < n_right; j++)
    {
        right[j] = array[j];
    }

    i = 0, j = 0;
    while (i < n_left && j < n_right)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n_left)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < n_right)
    {
        array[k] = right[j];
        j++;
        k++;
    }
    // while (i <= mid && j <= end)
    // {
    //     if (array[i] < array[j])
    //     {
    //         temp[k++] = array[i++];
    //     }
    //     else
    //     {
    //         temp[k++] = array[j++];
    //     }
    // }

    // while (i <= mid)
    // {
    //     temp[k++] = array[i++];
    // }

    // while (j <= end)
    // {
    //     temp[k++] = array[j++];
    // }

    // for (int i = start + 0; i < (end - start + 1); i++)
    // // for (int i = 0; i < (sizeof(*array) / sizeof(int)); i++)
    // {
    //     array[i] = temp[i];
    // }

    free(right);
    free(left);
    // printArray(array, (end - start + 1));
    return 0;
}

int merge_sort(int array[], int start, int end)
{

    if (array == NULL || (end - start + 1) <= 0)
        return -1;

    if (start < end)
    {
        int mid = start + (end - start) / 2;
        merge_sort(array, start, mid);   // Merge sort left
        merge_sort(array, mid + 1, end); // Merge sort right
        merge(array, start, mid, end);
        return 0;
    }
}

int main()
{
    const int SIZE = 9;

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
    array[5] = 54;
    array[6] = 63;
    array[7] = 38;
    array[8] = 6;
    // array[9] = 41;

    printf("The original array is: ");
    printArray(array, SIZE);

    // printf("Using selection sort:\n");
    // selection_sort(array, SIZE);

    printf("Using merge sort:\n");
    merge_sort(array, 0, SIZE - 1);
    // size_t new_array_size = sizeof(new_array) / sizeof(int);

    printArray(array, 9);

    free(array); // Always remember to free the memory on the heap
    return 0;
}
