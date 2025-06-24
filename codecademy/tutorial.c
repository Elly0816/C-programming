#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char characterName[] = "John Doe";
    int characterAge = 35;

    // printf("There was a man named %s", characterName);
    // printf("\nHe was %d years old", characterAge);
    // strcpy(characterName, "James");
    // printf("\nHe really liked the name %s", characterName);
    // characterAge = 67;
    // printf("\nBut he did not like being %d", characterAge);
    // printf("\n%c", character);
    // printf("\nYour GPA is %.2lf", (double)gpa);
    // int num1 = 5, num2 = 4;

    // float number = (float)num1 / num2;
    // // printf("%.2f", number);

    // double myNum = sin(num1);

    // int another_number = 5;
    // another_number = 23;
    // printf("%lf", myNum);

    // int myNumber;

    // char grade;
    // float gpa;
    // char name[20];
    // printf("Enter your new GPA: ");
    // scanf("%f", &gpa);
    // printf("\nEnter your letter grade: ");
    // scanf(" %c", &grade);
    // printf("\nEnter your name: ");
    // // scanf(" %[^\n]s", name);
    // while (getchar() != '\n')
    //     ;
    // fgets(name, 20, stdin);
    // name[strcspn(name, "\n")] = '\0';
    // printf("\nHi %s, your new GPA is: %.2f and your grade is %c", name, gpa, grade);

    float num1, num2;
    float result;
    char operator;
    char buffer[100];
    printf("Enter your calculation below, it should have two numbers and a single operator:\n");
    if (scanf("%f %c %f", &num1, &operator, & num2) != 3)
    { // If the user entered more than 3 inputs
        while (fgets(buffer, sizeof(buffer), stdin) && buffer[strlen(buffer) - 1] != '\n')
            ; // Reads from stdin in to the buffer until it hits the new line character or the input length is longer than the buffer size
        printf("Error: Invalid input format, Please enter two numbers and an operator\n");
        return 1;
    };

    if (strchr("+-*/", operator) == NULL)
    { // Compares the chars in the string to that which is stored in the operator variable
        printf("Invalid operator entered\n");
        return 1;
    }

    if (operator== '/' && num2 == 0)
    {
        printf("You cannot divide by zero");
        return 1;
    }
    switch (operator)
    {
    case '+':
        result = num1 + num2;
        /* code */
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    default:
        printf("Invalid operator! \nYour operators should be one of the following: +, -, *, /");
        break;
    }

    printf("%f %c %f = %f", num1, operator, num2, result);
    return 0;
}
