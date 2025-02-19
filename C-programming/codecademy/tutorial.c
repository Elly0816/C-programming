#include <stdio.h>

int main()
{
    char character = 'F';
    char characterName[] = "John";
    int characterAge = 35;
    float gpa = 3.7;

    printf("There once was a man named %s.\nHe was %d years old.\nHe liked the name %s.\nBut he didn't like being %d", characterName, characterAge, characterName, characterAge);
    printf("\n%c", character);
    return 0;
}
