#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Student
{
    char first_name[20];
    char last_name[20];
    int age;
    char sex[7];
    char email[50];
    char course[7];
    char phone_number[12];

} Student;

void clear_buffer(void);
void get_first_name(Student *);
void get_last_name(Student *);
void get_age(Student *);
void get_sex(Student *);
void get_email(Student *);
void get_course(Student *);
void get_phone_number(Student *);

int main(void)
{

    Student myStudent;

    get_first_name(&myStudent);
    get_last_name(&myStudent);
    get_age(&myStudent);
    get_sex(&myStudent);
    get_email(&myStudent);
    get_course(&myStudent);
    get_phone_number(&myStudent);

    printf("\n\nWELCOME TO APTECH\n\n");
    printf("\n\nHi %s %s, \nSome info about you: You're a %d year old %s.\nYour selected course is %s. \nYour classes will hold Monday to Thursday from 9am to 11am.\nRegularly check your email at: %s, otherwise we'll reach out to you on the phone number: %s.", myStudent.first_name, myStudent.last_name, myStudent.age, myStudent.sex, myStudent.course, myStudent.email, myStudent.phone_number);
    printf("\nWe hope you learn a lot here and you're ready to buuld software systems by the end of your stay here at Aptech.");
    return 0;
}
/*
 *
 *
 *
 *
 */
void clear_buffer(void)
{
    while (getchar() != '\n')
        ;
}
/*
 *
 *
 *
 *
 */
void get_first_name(Student *student)
{
    printf("Enter the first name of the student: ");

    int valid = 0;
    while (!valid)
    {
        valid = 1;
        scanf("%19s", student->first_name);

        for (int i = 0; i < strlen(student->first_name); i++)
        {
            if (!isalpha(*(student->first_name + i)))
            {
                printf("Enter a valid first name: ");
                clear_buffer();
                valid = 0;
                break;
            }
        }
    }
}
/*
 *
 *
 *
 *
 */
void get_last_name(Student *student)
{
    printf("Enter %s's last name: ", student->first_name);
    int valid = 0;
    while (!valid)
    {
        valid = 1;
        scanf("%19s", student->last_name);

        for (int i = 0; i < strlen(student->last_name); i++)
        {
            if (!isalpha(*(student->last_name + i)))
            {
                printf("Enter a valid last name: ");
                clear_buffer();
                valid = 0;
                break;
            }
        }
    }
}
/*
 *
 *
 *
 *
 */
void get_age(Student *student)
{
    printf("Enter %s %s's age: ", student->first_name, student->last_name);
    int age = 0;

    int valid = 0;
    while (!valid)
    {
        valid = 1;
        if (scanf("%d", &age) != 1 || age < 1)
        {
            printf("Enter a valid age greater than 1: ");
            clear_buffer();
            valid = 0;
        }
    }
    student->age = age;
}
/*
 *
 *
 *
 *
 */
void get_sex(Student *student)
{
    printf("Enter %s %s's sex: ", student->first_name, student->last_name);

    int valid = 0;
    while (!valid)
    {
        valid = 1;
        scanf("%6s", student->sex);
        if (strcmp(student->sex, "male") != 0 && strcmp(student->sex, "female") != 0)
        {
            printf("Enter either 'male' or 'female': ");
            valid = 0;
            clear_buffer();
        }
    }
}
/*
 *
 *
 *
 *
 */
void get_email(Student *student)
{
    printf("Enter %s %s's email: ", student->first_name, student->last_name);
    int valid = 0;
    while (!valid)
    {
        valid = 1;
        scanf("%49s", student->email);

        if (strcspn(student->email, "@") == strlen(student->email) || strcspn(student->email, ".") == strlen(student->email))
        {
            printf("Enter a valid email address: ");
            clear_buffer();
            valid = 0;
        }
    }
}
/*
 *
 *
 *
 *
 */
void get_course(Student *student)
{
    printf("Enter %s %s's course: ", student->first_name, student->last_name);
    int valid = 0;
    while (!valid)
    {
        valid = 1;
        scanf("%6s", student->course);
        for (int i = 0; i < strlen(student->course); i++)
        {
            if (!isalpha(*(student->course + i)))
            {
                printf("The course has to be a string! ");
                clear_buffer();
                valid = 0;
                break;
            }
        }
    }
}
/*
 *
 *
 *
 *
 */
void get_phone_number(Student *student)
{
    printf("Enter %s %s's phone number: ", student->first_name, student->last_name);

    int valid = 0;
    while (!valid)
    {
        valid = 1;
        scanf("%s", student->phone_number);
        if (strlen(student->phone_number) != 11)
        {
            printf("Enter a phone number containing 11 characters! ");
            clear_buffer();
            valid = 0;
            continue;
        }

        if (student->phone_number[0] != '0')
        {
            printf("The number must start with a zero! ");
            clear_buffer();
            valid = 0;
            continue;
        }

        for (int i = 0; i < strlen(student->phone_number); i++)
        {
            if (!isdigit(*(student->phone_number + i)))
            {
                printf("Your phone number cannot contain letters or symbols! ");
                valid = 0;
                clear_buffer();
                break;
            }
        }
    }
}
/*
 *
 *
 *
 *
 */