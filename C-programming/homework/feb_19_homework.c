#include <stdio.h>
#include <time.h>
#include <string.h>

int calculate_age(int year, int month, int day)
{

    int age, current_year, current_month, current_day;

    time_t current_time = time(NULL);                // This gets the current time
    struct tm *time_info = localtime(&current_time); // converts the time to y-m-d:h-m-s format

    current_year = time_info->tm_year + 1900; // Since time_info->tm_year gives the number of years since 1900, adding 1990 gives the appropriate year
    current_month = time_info->tm_mon + 1;    // Month starts counting from 0
    current_day = time_info->tm_mday + 1;     // Date starts counting from 0

    age = current_year - year;

    if ((current_month < month) || ((current_month == month) && (current_day < day)))
    { // This checks if the entered date has occured this year
        age--;
    }

    return age;
}

int main()
{
    char first_name[50], last_name[50], sex[10], email[50];
    int birth_year, birth_month, birth_day, age;

    printf("Hi! Please enter your first name: ");
    scanf("%s", first_name);
    printf("\nPlease enter your last name: ");
    scanf("%s", last_name);
    while (strcmp(sex, "male") && strcmp(sex, "female"))
    {
        printf("\nWell done! Now what's your gender? Enter male or female: ");
        scanf("%s", sex);
    }
    printf("\nGreat job! Now what's your email?: ");
    scanf("%s", email);
    while ((birth_year >= 2025) || (birth_year < 1900))
    {
        printf("\nGreat, now what year were you born in? ");
        scanf("%d", &birth_year);
    }
    while (((birth_month > 12) || (birth_month < 1)))
    {
        printf("\nFantastic! Now what month were you born in? (Enter as a number eg 1 for January and 12 for December): ");
        scanf("%d", &birth_month);
    }
    while (((birth_day > 31) || (birth_day < 1)))
    {
        printf("\nGreat! Now what day of the month were you born in?: ");
        scanf("%d", &birth_day);
    }

    age = calculate_age(birth_year, birth_month, birth_day);

    printf("\n\nHello %s %s,\n\tYou are apparently %d years old.\nYou're %s, and your email is %s.\nYours truly\nEleazar.", first_name, last_name, age, sex, email);

    return 0;
}