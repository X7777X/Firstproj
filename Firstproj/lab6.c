#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void task1()
{
	int years;

	puts("Введите год: ");
	scanf("%d", &years);

	if ((years % 4 == 0 && years % 100 != 0) || (years % 400 == 0)) {
		printf("Год %d високосный год", years);
	}
	else {
		printf("Год %d не вискосный ", years);
	}
}

void task2()
{
	double x = -6;
	printf("%lf", x <= -3 ? 9 : ( (float) 1 /(pow(x, 2) + 1)));

}

void task3()
{
	int N, i;

	puts("Введите число: ");
	scanf("%d", &N);

	puts("Если хотите последнюю цифру числа - введите 1, если первую - введите 2");
	scanf("%d", &i);

	if (i == 1)
		printf("%d", N % 10);
	else {
		if ((N / 100) == 0 && (N / 10) != 0)
			printf("%d", N /10);
		else if ((N / 100) != 0)
			printf("%d", N / 100);
		else if ((N / 10) == 0)
			printf("%d", N);
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	//task1();
	//task2();
	//task3();

	return 0;
}
