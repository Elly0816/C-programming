#include <stdio.h>
#include <ctype.h>

int is_alpha(const char *input)
{
    while (*input)
    {
        if (!isalpha(*input) || *input != '\n')
        {
            return 0;
        }
        input++;
    }

    return 1;
}

int main()
{
    char name[20], tasks[100][100];
    int number_of_tasks = 0;

    printf("\n\n-------------TO-DO LIST--------------\n\n");

    printf("Enter your name: ");
    while (scanf("%[^\n]", name) && is_alpha(name))
    {
        printf("Enter a valid name: ");
        while (getchar() != '\n')
            ;
    }

    printf("Enter the number of tasks you have: ");
    while (scanf("%d", &number_of_tasks) != 1 || number_of_tasks < 1)
    {
        printf("Enter a valid number: ");
        while (getchar() != '\n')
            ;
    }

    for (int i = 0; i < number_of_tasks; i++)
    {
        while (getchar() != '\n')
            ;
        printf("\nEnter task %d: ", i + 1);
        while (scanf("%[^\n]", tasks[i]) && is_alpha(tasks[i]))
        {
            printf("Enter a valid task: ");
            while (getchar() != '\n')
                ;
        }
    }

    printf("\n\nHi %s, \nYour tasks are: \n", name);
    for (int i = 0; i < number_of_tasks; i++)
    {
        printf("%d: %s\n", i + 1, tasks[i]);
    }

    return 0;
}

// #include <stdio.h>

// int main()
// {

//     int nTask;
//     char tasks[100][100], username[20];

//     printf("Enter your name: ");
//     fgets(username, 20, stdin);

//     printf("Enter the number of tasks you wish to carry out: ");
//     scanf("%d", &nTask);

//     while (getchar() != '\n')
//         ;
//     for (int i = 0; i < nTask; i++)
//     {
//         printf("Enter the tasks accordingly: ");
//         fgets(tasks[i], 100, stdin);
//     }

//     printf("Hi %s,", username);
//     for (int i = 0; i < nTask; i++)
//     {
//         printf("\nYour task is: %s", tasks[i]);
//         // fgets(tasks[i], nTask, stdin);
//     }

//     return 0;
// }