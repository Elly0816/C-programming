#include <stdio.h>
#include <string.h>

float average(float *numbers, size_t SIZE)
{

    float current_sum = 0, average;

    for (int i = 0; i < SIZE; i++)
    {
        current_sum += numbers[i];
    }

    average = current_sum / SIZE;

    return average;
}

int main()
{
    char course[8][50];
    float score[8], average_score;
    strcpy(course[0], "Programming Principles and Techniques");
    strcpy(course[1], "Logic Building and Elementary Programming");
    strcpy(course[2], "Building Modern Websites");
    strcpy(course[3], "UI/UX for Responsive Web Design");
    strcpy(course[4], "Frontend Web Development with React");
    strcpy(course[5], "e-Project - Responsive Website Development");
    strcpy(course[6], "Object-Oriented Programming Concepts");
    strcpy(course[7], "Data Management with SQL Server");

    for (int i = 0; i < (sizeof(score) / sizeof(score[0])); i++)
    {
        printf("Enter your score for %s: ", course[i]);
        scanf("%f", score + i);
    }

    average_score = average(score, sizeof(score) / sizeof(score[0]));
    char letter_grade = average_score >= 75 ? 'A' : average_score >= 65 ? 'B'
                                                : average_score >= 60   ? 'C'
                                                : average_score >= 50   ? 'D'
                                                                        : 'E';
    printf("Your average score is: %f\% which means you got an %c", average_score, letter_grade);

    return 0;
}