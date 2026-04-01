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
    printf("rollNumber is %d.\nrollNumber Size is %d.\nrollNumber Address is %u.\n\n", rollNumber, sizeof(rollNumber), &rollNumber);
    printf("name is %s.\nname Size is %d.\nname Address is %u.\n\n", name, sizeof(name), &rollNumber);
    printf("percentage is %lf.\npercentage Size is %d.\npercentage Address is %u.\n\n", percentage, sizeof(percentage), &rollNumber);
    printf("grade is %c.\ngrade Size is %d.\ngrade Address is %u.\n\n", grade, sizeof(grade), &rollNumber);
    printf("marks Size is %d\n", sizeof(marks));
    printf("marks Address is %d\n\n", &marks);
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("marks Element %d is %f. marks Element %d Address is %u.\n", i + 1, marks[i], i + 1, &marks[i]);
    }
    printf("\nStudent Size is %d\n", sizeof(student1));
    printf("Student Address is %d\n\n", &student1);
    printf("Student rollNumber is %d.\nStudent rollNumber Address is %u.\n\n", student1.rollNumber, &student1.rollNumber);
    printf("Student percentage is %lf.\nStudent percentage Address is %u.\n\n", student1.percentage, &student1.percentage);
    return 0;
}