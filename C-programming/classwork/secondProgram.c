#include <stdio.h>
#include <string.h>

int main()
{

    // const
    char myName[] = "Eleazar", person[] = "Another", third[] = "Yet Another";
    // char ourName[15];
    int myAge = 45;

    printf("The names are: \n%s, \n%s, \n%s", myName, person, third);

    printf("\n");
    printf("Hi, my name is %s, and I am %d years old.", myName, myAge);

    strcpy(myName, "Someone");
    myAge = 55;

    printf("\n");
    printf("Hi, my name is %s, and I am %d years old.", myName, myAge);

    return 0;
}