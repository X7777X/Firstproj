#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void task1()
{
	char c;
	int i;
	float f;
	double d;

	puts("Введите значения переменных");
	scanf("%c", &c);
	scanf("%d", &i);
	scanf("%f", &f);
	scanf("%lf", &d);

	printf("Целая часть вещественного числа - %d, дробная часть вещественного числа - %f\n", (int) f, f - (int) f);
	printf("Десятичный код символа - %d\nШестнадцатеричный код символа - %x\n", (int) c, (int) c);
	printf("Десятичное число соответствующее 1/i - %f", (float)1 / i);
}

void task2()
{
	int a = 11;
	int b = 3;
	int x = a/b;
	float y = (float) a/b;
	double z = (double) a/b;

	printf("%d\n%f\n%lf", x, y, z);
	// Использовав операцию преобразования типа, получим точные результаты. Без нее - только целую часть с '0' после запятой.
}

void task3()
{
	int N;

	puts("Введите целое трехзначное число:");
	scanf("%d", &N);

	printf("Последняя цифра числа N - %d, Первая цифра числа N - %d, сумма цифр данного числа - %d\nЧисло наоборот - %d%d%d", N % 10, 
		N / 100,(N / 10 - N/100*10) + N/100 + N % 10, N % 10, (N / 10 - N / 100 * 10), N / 100);

}

void indiv3()
{
	int schet;

	puts("Введите сумму счета:");
	scanf("%d", &schet);

	printf("Сумма чаевых, которые получит официант равна %.2f рублей", schet * 4 * 0.15);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	task1();
	//task2();
	//task3();
	//indiv3();

	return 0;
}

