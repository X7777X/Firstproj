#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

void task1()
{
	char c;

	printf("Введите символ: ");
	scanf("%c", &c);//считывание с консоли

	switch (c >= '0' && c <= '9')
	{
	case 1:
		puts("Это число.\n");
		break;
	case 0:
		puts("Это буква.\n");
		break;
	default:
		printf("Неизвестный символ - %c\n", c);
	}

}

void task2()
{
	float x, y;
	char c;
	puts("Введите значения и операцию:");
	scanf("%f %c %y", &x, &c, &y);

	printf("%c\n", c);

	switch (c)
	{
	case '+':
		printf("%f + %f = %f\n", x, y, x + y);
	case '-':
		printf("%f - %f = %f\n", x, y, x - y);
	case '*':
		printf("%f * %f = %f\n", x, y, x * y);
	case '/':
		printf("%f / %f = %f\n", x, y, x / y);
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	//task1();
	task2();
	//task3();
	
	return 0;
}
