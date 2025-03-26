#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void printArray(int arr[], int n);

// Bubble Sort Implementation
void bubbleSort(int arr[], int n)
{
    // Outer loop - number of passes
    for (int i = 0; i < n - 1; i++)
    {
        // Inner loop - comparing adjacent elements
        for (int j = 0; j < n - i - 1; j++)
        {
            // If current element is greater than next element, swap them
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort Implementation
void insertionSort(int arr[], int n)
{
    // Start from the second element
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // Element to be inserted
        int j = i - 1;    // Index of the last element in sorted portion

        // Move elements that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Insert the key in its correct position
    }
}

// Merge Sort Implementation
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Find middle point

        // Sort first and second halves recursively
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Merge function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Create temporary arrays using dynamic allocation
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge temporary arrays back into arr[left..right]
    i = 0;    // Initial index of left subarray
    j = 0;    // Initial index of right subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the allocated memory
    free(L);
    free(R);
}

// Utility function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to demonstrate sorting
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Bubble Sort demonstration
    int bubbleArr[7] = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(bubbleArr, n);
    printf("Bubble sorted array: ");
    printArray(bubbleArr, n);

    // Insertion Sort demonstration
    int insertArr[7] = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(insertArr, n);
    printf("Insertion sorted array: ");
    printArray(insertArr, n);

    // Merge Sort demonstration
    int mergeArr[7] = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(mergeArr, 0, n - 1);
    printf("Merge sorted array: ");
    printArray(mergeArr, n);

    return 0;
}
