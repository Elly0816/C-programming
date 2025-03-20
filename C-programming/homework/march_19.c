#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct Student
{
    char name[50];
    int age;
    char sex[7];
    float height;
    float cgpa;
};

void clear_buffer(void);

void getName(char *);
void getAge(int *, char *);
void getSex(char *, char *);
void getHeight(float *, char *);
void getCGPA(float *, char *);

int main(void)
{

    struct Student students[3];
    size_t length = sizeof(students) / sizeof(struct Student);

    for (int i = 0; i < length; i++)
    {

        getName(students[i].name);
        getAge(&students[i].age, students[i].name);
        getSex(students[i].sex, students[i].name);
        getHeight(&students[i].height, students[i].name);
        getCGPA(&students[i].cgpa, students[i].name);

        printf("\n");
    }

    for (int i = 0; i < length; i++)
    {
        char pronoun[4], first_cap[4];
        if (strcmp(students[i].sex, "male") == 0)
        {
            strcpy(pronoun, "he");
            strcpy(first_cap, "He");
        }
        else
        {
            strcpy(pronoun, "she");
            strcpy(first_cap, "She");
        }
        printf("%s is a %d years old %s.\n%s is %.2f meters tall and %s has a cgpa of %.2f.\n\n", students[i].name, students[i].age, students[i].sex, first_cap, students[i].height, pronoun, students[i].cgpa);
    }

    return 0;
}

void clear_buffer(void)
{
    while (getchar() != '\n')
        ;
}

void getName(char *name)
{
    printf("What is name of the student: ");

    while (1)
    {

        if (scanf("%[^\n]", name) != 1)
        {
            printf("\nEnter a valid name: ");
            clear_buffer();
            continue;
        }

        // check the length
        size_t length = strlen(name);
        if (length >= 49)
        {
            printf("\nEnter a valid name shorter than 50 characters! ");
            clear_buffer();
            continue;
        }

        // Check if all the characters are alphabets or space
        int valid = 1;
        for (size_t i = 0; i < length; i++)
        {
            if (!isalpha((unsigned char)name[i]) && !isspace((unsigned char)name[i]))
            {
                valid = 0;
                break;
            }
        }
        if (valid)
        {
            break;
        }
        printf("\nEnter a valid name including only letters and spaces! ");
        clear_buffer();
    }
    clear_buffer();
    printf("\n");
}

void getAge(int *age, char *name)
{
    printf("Enter %s's age: ", name);
    while (scanf("%d", age) != 1)
    {
        printf("Enter a valid number for age: ");
        clear_buffer();
    }
    clear_buffer();
    printf("\n");
}

void getSex(char *sex, char *name)
{

    printf("Enter %s's sex: ", name);

    while (scanf("%8s", sex) && (strcmp(sex, "male") != 0 && strcmp(sex, "female") != 0))
    {
        printf("Enter either male or female: ");
        clear_buffer();
    }
    clear_buffer();
    printf("\n");
}

void getHeight(float *height, char *name)
{
    printf("Enter %s's height in meters: ", name);
    scanf("%f", height);
    clear_buffer();
    printf("\n");
}

void getCGPA(float *cgpa, char *name)
{
    printf("Enter %s's cgpa: ", name);
    while (scanf("%f", cgpa) && (*cgpa < 0 || *cgpa > 5))
    {
        printf("Enter a valid CGPA between 0 and 5: ");
        clear_buffer();
    };
    clear_buffer();
    printf("\n");
}