#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_valid_name(const char *name)
{
    while (*name)
    {
        if (!isalpha(*name) && !isspace(*name))
        {
            return 0;
        }
        name++;
    }
    return 1;
}

int is_valid_grade(char grade)
{
    grade = toupper(grade);
    return (grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D' || grade == 'E' || grade == 'F');
}

int main(void)
{

    char *grades = (char *)malloc(6 * sizeof(char));
    char names[6][100];
    char temp_grade;
    char temp_name[100];

    if (grades == NULL)
    {
        printf("There was an issue with memory allocation\n");
        return 1;
    }

    for (int i = 0; i < 6; i++)
    {
        do
        {

            printf("Enter the name of the student: ");
            scanf("%[^\n]", temp_name);
            while (getchar() != '\n')
                ;
            if (!is_valid_name(temp_name))
            {
                printf("Enter a valid name\n");
            }

        } while (!is_valid_name(temp_name));

        strcpy(names[i], temp_name);

        do
        {

            printf("Enter the letter grade of %s: ", names[i]);
            scanf("%c", &temp_grade);
            while (getchar() != '\n')
                ;

            if (!is_valid_grade(temp_grade))
            {
                printf("Enter a valid grade!\n");
            }

        } while (!is_valid_grade(temp_grade));

        grades[i] = toupper(temp_grade);
    }

    for (int i = 0; i < 6; i++)
    {
        printf("%s has the grade %c\n", names[i], *(grades + i));
    }

    free(grades);

    return 0;
}