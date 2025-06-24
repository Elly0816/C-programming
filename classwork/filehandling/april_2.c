#include <stdio.h>

int main(void)
{

    // printf("Enter some text to write to the file: \n");
    char my_file[100];

    // scanf("%99[^\n]", my_file);

    FILE *file_pointer;
    file_pointer = fopen("new_file.txt", "r");

    if (file_pointer == NULL)
    {
        printf("There was an issue locating the file");
        return 1;
    }
    // fprintf(file_pointer, my_file);
    while (fgets(my_file, 5, file_pointer))
    {

        printf("%s", my_file);
    }
    // fgets(my_file, 100, file_pointer);

    fclose(file_pointer);

    return 0;
}