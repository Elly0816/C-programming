#include <stdio.h>

int main(void)
{

    char myText[300];

    char *myText_ptr = &myText[0];
    int length = sizeof(myText) / sizeof(char);

    printf("Enter your text: ");
    scanf("%[^\n]", myText);

    // for (int i = 0; i < length; i++)
    // {
    //     if (*(myText_ptr + i) == '\0')
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         printf("\n%c is stored in: %p", *(myText_ptr + i), myText_ptr + i);
    //     }
    // }

    while (*myText_ptr)
    {

        printf("\n%c is stored in: %p", *(myText_ptr), myText_ptr);
        myText_ptr++;
    }
    return 0;
}