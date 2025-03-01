#include <stdio.h>
#include <string.h>

int main()
{
    char color[15], plural_noun[15], celebrity[20];

    printf("Enter a color: ");
    fgets(color, sizeof(color), stdin);
    color[strcspn(color, "\n")] = '\0';
    printf("\nEnter a plural noun: ");
    fgets(plural_noun, sizeof(plural_noun), stdin);
    plural_noun[strcspn(plural_noun, "\n")] = '\0';
    printf("\nEnter the name of a celebrity: ");
    scanf("%[^\n]", celebrity);
    // fgets(celebrity, sizeof(celebrity), stdin);
    // celebrity[strcspn(celebrity, "\n")] = '\0';
    printf("\n");
    printf("Roses are %s,\n%s are blue,\nI love %s.", color, plural_noun, celebrity);
    return 0;
}