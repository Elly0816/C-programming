#include <stdio.h>
#include <string.h>

#define NUM_OF_COURSES 8

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
    char course[NUM_OF_COURSES][50];
    float score[NUM_OF_COURSES], average_score;
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

    average_score = average(score, NUM_OF_COURSES);
    printf("Your average score is: %f", average_score);

    return 0;
}