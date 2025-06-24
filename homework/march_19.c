#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student
{
    char name[50];
    int age;
    char sex[7];
    float height;
    float cgpa;
    char email[80];
} Student;

// typedef struct Student Student;

void clear_buffer(void);

void get_name(char *);
void get_age(int *, char *);
void get_sex(char *, char *);
void get_height(float *, char *);
void get_cgpa(float *, char *);
void get_email(char *, char *);
int get_number_of_students();

int main(void)
{

    int number_of_students = get_number_of_students();

    Student *students = (Student *)malloc(number_of_students * sizeof(Student));
    if (students == NULL)
    {
        printf("There was an issue allocating memory for the student struct");
        return -1;
    }

    for (int i = 0; i < number_of_students; i++)
    {

        get_name(students[i].name);
        get_age(&students[i].age, students[i].name);
        get_sex(students[i].sex, students[i].name);
        get_height(&students[i].height, students[i].name);
        get_cgpa(&students[i].cgpa, students[i].name);
        get_email(students[i].name, students[i].email);

        printf("\n");
    }

    for (int i = 0; i < number_of_students; i++)
    {
        char pronoun[4], first_cap[4], possessive[4], first_cap_poss[4];
        if (strcmp(students[i].sex, "male") == 0)
        {
            strcpy(pronoun, "he");
            strcpy(first_cap, "He");
            strcpy(possessive, "his");
            strcpy(first_cap_poss, "His");
        }
        else
        {
            strcpy(pronoun, "she");
            strcpy(first_cap, "She");
            strcpy(possessive, "her");
            strcpy(first_cap_poss, "Her");
        }
        printf("%s is a %d years old %s.\n%s is %.2f meters tall and %s has a cgpa of %.2f.\n%s email is: %s\n\n", students[i].name, students[i].age, students[i].sex, first_cap, students[i].height, pronoun, students[i].cgpa, first_cap_poss, students[i].email);
    }

    free(students);

    return 0;
}

void clear_buffer(void)
{
    while (getchar() != '\n')
        ;
}

void get_name(char *name)
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

void get_age(int *age, char *name)
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

void get_sex(char *sex, char *name)
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

void get_height(float *height, char *name)
{
    printf("Enter %s's height in meters: ", name);
    scanf("%f", height);
    clear_buffer();
    printf("\n");
}

void get_cgpa(float *cgpa, char *name)
{
    printf("Enter %s's cgpa: ", name);
    while (scanf("%f", cgpa) && (*cgpa < 0 || *cgpa > 5))
    {
        printf("Enter a valid CGPA between 0 and 5: ");
        clear_buffer();
    }
    clear_buffer();
    printf("\n");
}

void get_email(char *name, char *email)
{

    printf("Enter %s's email: ", name);
    while (1)
    {

        scanf("%79s", email);

        if (strcspn(email, "@") == strlen(email) && strcspn(email, ".") == strlen(email))
        {
            printf("Enter a valid email: ");
            clear_buffer();
            continue;
        }
        clear_buffer();
        break;
    }
}

int get_number_of_students()
{
    int number = 0;
    printf("Enter the number of students you want to assign: ");

    while (1)
    {
        scanf("%d", &number);
        if (number < 1)
        {
            printf("Enter a number greater than zero! ");
            clear_buffer();
            continue;
        }
        break;
    }
    clear_buffer();
    return number;
}