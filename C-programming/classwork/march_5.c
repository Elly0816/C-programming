#include <stdio.h>

int main()
{

    // int age[] = {17, 45, 54, 25, 56, 75, 50};
    // int size = (sizeof(age) / sizeof(int));

    // for (int i = 0; i < size; i++)
    // {
    //     if (i == size - 1)
    //     {

    //         printf("%d.", age[i]);
    //     }
    //     else
    //     {

    //         printf("%d, ", age[i]);
    //     }
    // }

    // int student_grades[] = {66, 75, 65, 34, 72, 23, 15};

    // for (int i = 0; i < 7; i++)
    // {
    //     if (i == 6)
    //     {
    //         printf("%d.\n", student_grades[i]);
    //     }
    //     else
    //     {

    //         printf("%d, ", student_grades[i]);
    //     }
    // }

    // for (int i = 0; i < 7; i++)
    // {
    //     int age;
    //     printf("Enter age %d: ", i + 1);

    //     while (scanf("%d", &age) != 1)
    //     {
    //         printf("Enter a valid number: ");
    //         while (getchar() != '\n')
    //             ;
    //     }
    //     student_grades[i] = age;
    // }

    // for (int i = 0; i < 7; i++)
    // {
    //     if (i == 6)
    //     {
    //         printf("%d.", student_grades[i]);
    //     }
    //     else
    //     {

    //         printf("%d, ", student_grades[i]);
    //     }
    // }

    int student_grades[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Enter the grade of student %d: ", i + 1);
        while (scanf("%d", &student_grades[i]) != 1)
        {
            printf("Enter a valid grade as a number: ");
            while (getchar() != '\n')
                ;
        }
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nThe grade of student %d is %d", i + 1, student_grades[i]);
    }

    return 0;
}