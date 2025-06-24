#include <stdio.h>
#include <errno.h>

typedef struct Employee
{
    int id;
    char name[50];
    float salary;
} Employee;

int write_binary_to_file(FILE *, Employee *, char *);
int read_binary_from_file(FILE *, char *);

int main(void)
{
    Employee empl = {1, "Eleazar", 550000};
    FILE *file_ptr;
    char filename[50] = "employee.bin";

    if (write_binary_to_file(file_ptr, &empl, filename) != 0)
    {
        return -1;
    }
    else
    {
        if (read_binary_from_file(file_ptr, filename) != 0)
        {
            return -1;
        }
    }

    return 0;
}

int write_binary_to_file(FILE *file_pointer, Employee *emp, char *filename)
{
    file_pointer = fopen(filename, "wb");
    if (file_pointer == NULL)
    {
        printf("%s could not be found\n", filename);
        perror("Invalid file path!");
        return -1;
    }

    fwrite(emp, sizeof(Employee), 1, file_pointer);
    fclose(file_pointer);
    file_pointer = NULL;
    return 0;
}

int read_binary_from_file(FILE *file_pointer, char *filename)
{
    Employee emp;
    file_pointer = fopen(filename, "rb");

    if (file_pointer == NULL)
    {
        printf("%s could not be found!\n", filename);
        perror("Invalid file path!");
        return -1;
    }

    fread(&emp, sizeof(Employee), 1, file_pointer);
    fclose(file_pointer);
    file_pointer = NULL;

    printf("Read employee: ID: %d, NAME: %s, SALARY:%.2f", emp.id, emp.name, emp.salary);
    return 0;
}