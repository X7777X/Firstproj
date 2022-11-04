#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 10
#define Pi 3,14


void task1()
{
	float A[N];
	float temp;
	float nach;
	float s = 0;

	for (int i = 0; i < 10; i++) {

		printf("a[%d] = ", i + 1);
		scanf("%f", &temp);
		A[i] = temp;
		s += A[i];
	}
	printf("Среднее арифметическое элементов массива равно %lf\n", s / N);

	for (int i = 0; i < 10; i++) {	//Вывод элементов массива

		nach = A[i];
		if (A[i] < 0)
			A[i] = 0;
		printf("| %d | %10.lf | %lf \n", i, nach, A[i]);

	}
}

double rasfunc()
{
	return 1.8 * pow((0.2 + (double)rand() / RAND_MAX), 2) - sin(10 * (0.2 + (double)rand() / RAND_MAX));
}
void task2()
{
	double a[100];
	double smin = 0, spl = 0, sred = 0;
	int kolpl = 0, kolmin = 0;



	for (int i = 0; i < 100; i++) {
		a[i] = rasfunc();
		printf("%lf\n", a[i]);
		sred += a[i];
		if (a[i] < 0) {
			smin += a[i];
			kolmin += 1;
		}
		else {
			spl += a[i];
			kolpl += 1;
		}
	}
	sred = sred / 100;
	printf("|Имя массива - 'a'\nНакопленное положительное значение - %lf\nНакопленное отрицательное значение - %lf\nКол-во пол. элментов - %d\nКол-во отриц. элементов - %d\nСреднее элементов массива - %lf", spl, smin, kolpl, kolmin, sred);

}
void task3()
{
	int a[1000];
	int sum = 0, kol = 0, posl, posli;
	char c;

	for (int i = 0; i < 1000; i++) {
		puts("Введите элементы массива: (введите * сразу после элемента для конца последовательности)");
		scanf("%d%c", &a[i], &c);
		kol += 1;
		if (c == '*')
			break;
	}
	for (int i = 0; i < kol; i++) {
		if (a[i] > 0) {
			posl = a[i];
			posli = i;
		}
	}
	for (int i = 0; i < kol; i++) {
		if (i < posli)
			sum += a[i];
		else
			break;
	}
	printf("Сумма до последнего положительного - %d", sum);

}

int main()
{
	setlocale(LC_ALL, "RUS");

	//task1();
	//task2();
	task3();


	return 0;
}
