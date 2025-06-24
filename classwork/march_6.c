#include <stdio.h>

int three_dimensional_array_print()
{

    int three_dimensional_items[5][5][4];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                three_dimensional_items[i][j][k] = i + 1 * j + 1 * k + 1;
            }
        }
    }

    printf("[ ");
    for (int i = 0; i < 5; i++)
    {
        printf("\n");
        printf("[ ");
        for (int j = 0; j < 5; j++)
        {
            printf("[ ");
            for (int k = 0; k < 4; k++)
            {
                if (k == 3)
                {

                    printf("%d", three_dimensional_items[i][j][k] + 1);
                }
                else
                {

                    printf("%d, ", three_dimensional_items[i][j][k] + 1);
                }
            }
            if (j == 4)
            {

                printf(" ]");
            }
            else
            {

                printf(" ], ");
            }
        }
        printf(" ], \n");
    }
    printf("\n");
    printf(" ]");

    return 0;
}

int main()
{
    // three_dimensional_array_print();

    int matrix[2][3] = {{1, 4, 2}, {3, 6, 8}};
    int inner_length = sizeof(matrix[0]) / sizeof(int);
    int outer_length = sizeof(matrix) / sizeof(matrix[0]);

    printf("%d", inner_length);
    printf("%d", outer_length);
    printf("\n\t\t\t");
    for (int i = 0; i < inner_length; i++)
    {
        printf("Column %d\t\t", i);
    }
    for (int i = 0; i < outer_length; i++)
    {
        printf("\n");
        // printf("%d outer length", outer_length);
        printf("Row %d", i);
        for (int j = 0; j < inner_length; j++)
        {
            printf("\t\t%11d", matrix[i][j]);
        }
    }

    return 0;
}