#include <stdio.h>
#include <ctype.h>

int is_alpha_numeric(const char *input)
{
    while (*input)
    {
        if (!isalpha(*input))
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
    int number_of_tasks;

    printf("-------------TO-DO LIST--------------\n\n");

    printf("Enter your name: ");
    while (scanf("%s", name) && !is_alpha_numeric(name))
    {
        printf("Enter a valid name: ");
        while (getchar() != '\n')
            ;
    }

    printf("Enter the number of tasks you have: ");
    while (scanf("%d", &number_of_tasks) != 1)
    {
        printf("Enter a valid number: ");
        while (getchar() != '\n')
            ;
    }

    for (int i = 0; i < number_of_tasks; i++)
    {
        while (getchar() != '\n' && getchar() != EOF)
            ;
        printf("Enter task %d: ", i + 1);
        while (scanf("%[^\n]", tasks[i]) && !is_alpha_numeric(tasks[i]))
        {
            printf("Enter a valid task: ");
            while (getchar() != '\n')
                ;
        }
    }

    printf("Hi %s, \n", name);
    for (int i = 0; i < number_of_tasks; i++)
    {
        printf("Your task %d is %s\n", i + 1, tasks[i]);
    }

    return 0;
}