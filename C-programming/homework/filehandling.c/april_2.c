#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

/*
 *
 * Ask the user for their info, use the info to write a letter to the student.
 * Save that letter to a file, and then read the letter from the file
 *
 *
 *
 *
 *
 *
 */

typedef struct Student
{
    char name[50];
    int age;
    char sex[7];
    char course[60];
    float high_school_gpa;
} Student;

void get_name(Student *);
void get_age(Student *);
void get_sex(Student *);
void get_course(Student *);
void get_gpa(Student *);
void clear_buffer(void);
int write_to_file(FILE *, Student *, char *);
int read_from_file(FILE *, char *);
void read_or_write(char *);

int main(void)
{

    FILE *student_file;
    char student_letter[100];
    char *file_path = "student_info.txt";

    char read_or_write_char[6];

    Student student;

    int should_ask;

    do
    {
        should_ask = 1;
        printf("Do you want to read or write to the file?\n Enter 'read' to read, 'write' to write and 'none' to close the program: ");

        read_or_write(read_or_write_char);
        printf("\n\n");
        if (strcmp(read_or_write_char, "read") == 0)
        // Read from the file at the location specified by the filepath
        {
            if (read_from_file(student_file, file_path) != 0)
            {
                printf("There is no file named %s!\nMake sure the file exist!", file_path);
            }
            printf("\n\n\n\n");
        }
        else if (strcmp(read_or_write_char, "write") == 0)
        // Write to the file at the location specified by the filepath
        {
            get_name(&student);
            get_age(&student);
            get_sex(&student);
            get_course(&student);
            get_gpa(&student);

            if (write_to_file(student_file, &student, file_path) != 0)
            {
                return -1;
            }
        }
        else if (strcmp(read_or_write_char, "none") == 0)
        { // End the program
            printf("Goodbye");

            should_ask = 0;
        }
        else
        {
            printf("Invalid input! ");
        }

    } while (should_ask);

    return 0;
}

void clear_buffer(void)
{
    while (getchar() != '\n')
        ;
}

void get_name(Student *student)
{

    char student_name[50];
    int invalid;

    // printf("%llu", strlen(student_name));
    printf("Enter the name of the student: ");
    do
    {
        invalid = 0;

        if (scanf("%[^\n]", student_name) != 1)
        {
            printf("Enter a valid name: ");
            invalid = 1;
            clear_buffer();
            continue;
        }

        if (strlen(student_name) >= 49)
        {
            printf("Your name is too long! ");
            invalid = 1;
            clear_buffer();
            continue;
        }

        for (int i = 0; i < strlen(student_name); i++)
        {
            if (!isalpha(student_name[i]) && !isspace(student_name[i]))
            {
                printf("Your name cannot contain numbers! ");
                invalid = 1;
                clear_buffer();
                break;
            }
        }
    } while (invalid);
    strcpy(student->name, student_name);
}

void get_age(Student *student)
{
    printf("Enter %s's age: ", student->name);

    int invalid;
    int age = 0;

    do
    {
        invalid = 0;
        if (scanf("%d", &age) != 1)
        {
            printf("Enter a number: ");
            invalid = 1;
            clear_buffer();
            continue;
        }

        if (age < 1)
        {
            printf("Enter a valid age: ");
            invalid = 1;
            clear_buffer();
        }
    } while (invalid);
    student->age = age;
}

void get_sex(Student *student)
{
    int invalid;
    printf("Enter %s's sex: ", student->name);
    char sex[7];

    do
    {
        invalid = 0;
        scanf("%s", sex);
        if (strcmp(sex, "male") != 0 && strcmp(sex, "female") != 0 && strcmp(sex, "MALE") != 0 && strcmp(sex, "FEMALE") != 0)
        {
            printf("Enter either 'male or MALE' or 'female or FEMALE': ");
            clear_buffer();
            invalid = 1;
        }
    } while (invalid);
    for (int i = 0; i < strlen(sex); i++)
    {
        sex[i] = tolower(sex[i]);
    }
    strcpy(student->sex, sex);
}

void get_course(Student *student)
{

    char courses[5][60] = {"Software Engineering", "Graphic Design", "UI/UX", "MultiMedia", "Data Science and Machine Learning"};
    int number_of_courses = 5;

    int invalid;
    int user_choice = 0;

    printf("Pick your preferred course from the list below:\n");
    for (int i = 0; i < number_of_courses; i++)
    {
        printf("Press %d for %s.\n", i + 1, courses[i]);
    }
    do
    {
        invalid = 0;

        if (scanf("%d", &user_choice) != 1 || user_choice < 1 || user_choice > 5)
        {
            printf("Enter a valid number from 1 to 5! ");
            clear_buffer();
            invalid = 1;
        }

    } while (invalid);

    strcpy(student->course, courses[user_choice - 1]);
}

void get_gpa(Student *student)
{
    printf("Enter your high school gpa: ");

    int invalid;
    float gpa = 0;

    do
    {

        invalid = 0;
        if (scanf("%f", &gpa) != 1 || gpa > 5 || gpa <= 0)
        {
            printf("Enter a valid number for gpa! It should be between more than zero and less than or equal to 5! ");
            invalid = 1;
            clear_buffer();
        }

    } while (invalid);

    student->high_school_gpa = gpa;
}

int write_to_file(FILE *file, Student *student, char *filepath)
{

    file = fopen(filepath, "w");

    if (file == NULL)
    {
        printf("There was an error opening the file!");
        perror("Error details");
        return -1;
    }

    fprintf(file, "\t\t\t\t\t\t\t\t\tWELCOME TO APTECH\n");
    fprintf(file, "Hi %s!\nFrom what we know about you, you are a %d year old %s.\n", student->name, student->age, student->sex);
    fprintf(file, "Your chosen course of study is %s and your high school graduating gpa is %.2f\n", student->course, student->high_school_gpa);
    fprintf(file, "We hope you make the best of your time here and you graduate to be world class at %s\n", student->course);
    fprintf(file, "Goodluck!");
    fclose(file);
    return 0;
}

int read_from_file(FILE *file, char *filepath)
{
    char string[100];
    file = fopen(filepath, "r");
    if (file == NULL)
    {
        perror("Could not open the file");
        return -1;
    }
    while (fgets(string, 100, file))
    {
        printf("%s", string);
    }
    fclose(file);
    return 0;
}

void read_or_write(char *character)
{
    int invalid;
    char choice[6];

    do
    {
        invalid = 0;
        scanf("%s", choice);
        if (strcmp(choice, "read") != 0 && strcmp(choice, "write") != 0 && strcmp(choice, "none") != 0)
        {
            invalid = 1;
            clear_buffer();
            printf("Enter either read, or write, or none\n");
        }
    } while (invalid);

    clear_buffer();
    strcpy(character, choice);
}