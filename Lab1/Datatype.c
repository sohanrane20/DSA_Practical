/*
2: Write a C program to declare primitive and nonprimitive
datatypes and display the values of variables, their memory
addresses, and their sizes for similar and dissimilar datatypes
*/
#include <stdio.h>
struct Student
{
	int rollNumber;
	char name[20];
	float marks;
};
char assignGrade(double percentage);
int main()
{
	int rollNumber;
	char name[20];
	char grade;
	float totalMarks;
	float marks[5];
	double percentage;
	printf("Enter roll number: ");
	scanf("%d", rollNumber);
	printf("Enter name: ");
	fflush(stdin);
	fgets(name, sizeof(name), stdin);
	int i;
	totalMarks = 0;
	for (i = 0; i < 5; i++)
	{
		printf("Enter marks scored in subject %d: ", i + 1);
		scanf("%f", &marks[i]);
		totalMarks += marks[i];
	}
	percentage = totalMarks * 100.0 / 500;
	grade = assignGrade(percentage);
	struct Student student1 = {rollNumber, name, totalMarks};
	printf("Roll number is %d\n", rollNumber);
	printf("Name is %s\n", name);
	for (i = 0; i < 5; i++)
	{
		printf("Marks scored in subject %d are %f\n", i + 1, marks[i]);
	}
	printf("Total marks are %f\n", totalMarks);
	printf("Percentage is %lf\n", percentage);
	printf("Grade is %c\n\n", grade);
	printf("Roll number is %d\n", student1.rollNumber);
	printf("Name is %s\n", student1.name);
	printf("Marks are %f\n", student1.marks);
	return 0;
}
char assignGrade(double percentage)
{
	char grade;
	int per = (int)percentage / 10;
	switch (per)
	{
	case 10:
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
	case 6:
	case 5:
		grade = 'C';
		break;
	case 4:
		grade = 'D';
		break;
	default:
		grade = 'F';
	}
	return grade;
}