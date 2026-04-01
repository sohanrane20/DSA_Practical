// 2: Design a calendar
#include <stdio.h>
int main()
{
	int year, month;
	char daysOfWeek[7][10] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
	char monthsInYear[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	printf("Enter year: ");
	scanf("%d", &year);
	printf("Enter month: ");
	scanf("%d", &month);
	int reference = 1990, totalDays = 0;
	for (int i = reference; i < year; i++)
	{
		if (i % 4 == 0)
		{
			totalDays += 366;
		}
		else
		{
			totalDays += 365;
		}
	}
	for (int i = 1; i < month; i++)
	{
		switch (i)
		{
		case 2:
			if (year % 4 == 0)
			{
				totalDays += 29;
			}
			else
			{
				totalDays += 28;
			}
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			totalDays += 31;
			break;
		default:
			totalDays += 30;
		}
	}
	int start = totalDays % 7, row, column, date = 1, days;
	switch (month)
	{
	case 2:
		if (year % 4 == 0)
		{
			days = 29;
		}
		else
		{
			days = 28;
		}
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		days = 31;
		break;
	default:
		days = 30;
	}
	printf("%s, %d\n", monthsInYear[month - 1], year);
	for (int i = 0; i < 7; i++)
	{
		printf("%s\t", daysOfWeek[i]);
	}
	printf("\n");
	for (column = 0; column < 7 && date <= days; column++)
	{
		if (column < start)
			printf("   \t");
		else
		{
			printf("%3d\t", date);
			date++;
		}
	}
	printf("\n");
	for (row = 1; date <= days; row++)
	{
		for (column = 0; column < 7 && date <= days; column++)
		{
			printf("%3d\t", date);
			date++;
		}
		printf("\n");
	}
	return 0;
}