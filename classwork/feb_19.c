#include <stdio.h>

int main()
{
    int age;
    char name[50];

    printf("Enter your age and name: "); // Prompt the user for their age
    scanf("%d %s", &age, name);          // Save the age to the variable

    printf("The age you entered is: %d and your name is %s", age, name); // Print the age to the console

    return 0;
}