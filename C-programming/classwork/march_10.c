#include <stdio.h>

int main()
{

    // int myVal = 5;
    // int *myValPointer = &myVal;

    // printf("%d is located at %p", myVal, myValPointer);
    // printf("\nThe value stored at %p is %d", myValPointer, *myValPointer);

    // int myArray[] = {5, 2, 3, 5, 6, 7, 7, 2};

    // for (int i = 0; i < (sizeof(myArray) / sizeof(int)); i++)
    // {
    //     printf("\nThe address of %d is %p", myArray[i], &myArray[i]);
    // }

    int a = 20;
    int b = 20;

    int *a_ptr = &a;
    int *b_ptr = &b;

    if (a_ptr == b_ptr)
    {
        printf("The memory addresses are the same");
    }
    else
    {

        printf("The memory addresses are not the same");
    }

    return 0;
}