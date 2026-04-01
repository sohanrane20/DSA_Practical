/*
2: Write a C program to declare primitive and nonprimitive
datatypes and display the values of variables, their memory
addresses, and their sizes for similar and dissimilar datatypes
*/
#include <stdio.h>
struct Student
{
    int rollNumber;
    double percentage;
};
int main()
{
    int rollNumber = 12;
    char name[] = "Sohan Rane";
    float marks[5] = {78.9, 12.3, 23.4, 34.5, 45.6};
    double percentage = 67.8;
    char grade = 'B';
    struct Student student1 = {rollNumber, percentage};
    printf("rollNumber value is %d.\nrollNumber size is %d.\nrollNumber address is %u.\n\n", rollNumber, sizeof(rollNumber), &rollNumber);
    printf("name value is %s.\nname size is %d.\nname address is %u.\n\n", name, sizeof(name), &rollNumber);
    printf("percentage value is %lf.\npercentage size is %d.\npercentage address is %u.\n\n", percentage, sizeof(percentage), &rollNumber);
    printf("grade value is %c.\ngrade size is %d.\ngrade address is %u.\n\n", grade, sizeof(grade), &rollNumber);
    printf("marks size is %d\n", sizeof(marks));
    printf("marks base address is %d\n\n", &marks);
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("marks element %d value is %f. marks element %d address is %u.\n", i, marks[i], i, &marks[i]);
    }
    printf("\nStudent size is %d\n", sizeof(student1));
    printf("Student base address is %d\n\n", &student1);
    printf("Student rollNumber value is %d.\nStudent rollNumber address is %u.\n\n", student1.rollNumber, &student1.rollNumber);
    printf("Student percentage value is %lf.\nStudent percentage address is %u.\n\n", student1.percentage, &student1.percentage);
    return 0;
}
