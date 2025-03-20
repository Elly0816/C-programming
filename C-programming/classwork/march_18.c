#include <stdio.h>

void print_char(char[], int, int);
void print_items(int[], int, int);

int main(void)
{
    char name[] = "Something fishy is going on";
    int length = sizeof(name) / sizeof(char);
    int items[] = {2, 5, 3, 1, 5, 6, 7, 8};
    int array_length = sizeof(items) / sizeof(int);
    print_char(name, length, 0);
    printf("\n");
    print_items(items, array_length, 0);
    return 0;
}

void print_char(char string[], int length, int start_pos)
{

    if (start_pos < length)
    {
        printf("%c\n", string[start_pos]);
        print_char(string, length, start_pos + 1);
    }
}

void print_items(int items[], int length, int current_pos)
{
    if (current_pos < length)
    {
        printf("%d\n", items[current_pos]);
        print_items(items, length, current_pos + 1);
    }
}