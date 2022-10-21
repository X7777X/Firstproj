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

void task2()
{
	float A, B;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	
	//task1();
	task2();
	//task3();

	return 0;
}
