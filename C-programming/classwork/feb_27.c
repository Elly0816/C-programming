#include <stdio.h>

int main()
{

    int student_score = 65;
    student_score >= 75 ? printf("student score is: %d%\n\nStudent grade is: A", student_score) : student_score >= 60 ? printf("student score is: %d%\n\nStudent grade is: B", student_score)
                                                                                              : student_score >= 50   ? printf("student score is: %d%\n\nStudent grade is: C", student_score)
                                                                                              : student_score >= 45   ? printf("student score is: %d%\n\nStudent grade is: D", student_score)
                                                                                              : student_score >= 40   ? printf("student score is: %d%\n\nStudent grade is: E", student_score)
                                                                                                                      : printf("student score is: %d%\n\nStudent grade is: F", student_score);

    return 0;
}