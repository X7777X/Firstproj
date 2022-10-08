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
	scanf("%f %c %f", &x, &c, &y);


	switch (c)
	{
	case '+':
		printf("%f\n", x + y);
		break;
	case '-':
		printf("%f\n",x - y);
		break;
	case '*':
		printf("%f\n", x * y);
		break;
	case '/':
		printf("%f\n",x / y);
		break;
	case '^':				//доп. функционал
		printf("%f", pow(x, y));
	}
}

void task3() //3 вариант
{
	int number;

	puts("Введите число: ");
	scanf("%d", &number);

	switch (number % 10)
	{
	case 1:
		puts("Последняя цифра двухзначного числа - не простое число");
		break;
	case 2:
		puts("Последняя цифра двухзначного числа - простое число");
		break;
	case 3:
		puts("Последняя цифра двухзначного числа - простое число");
		break;
	case 4:
		puts("Последняя цифра двухзначного числа - не простое число");
		break;
	case 5:
		puts("Последняя цифра двухзначного числа - простое число");
		break;
	case 6:
		puts("Последняя цифра двухзначного числа - не простое число");
		break;
	case 7:
		puts("Последняя цифра двухзначного числа - простое число");
		break;
	case 8:
		puts("Последняя цифра двухзначного числа - не простое число");
		break;
	case 9:
		puts("Последняя цифра двухзначного числа - не простое число");
		break;
	}


}


int main()
{
	setlocale(LC_ALL, "RUS");
	task1();
	//task2();
	//task3();


	return 0;
}
