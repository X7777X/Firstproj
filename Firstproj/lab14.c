#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
int sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);

int find_element(double* array, int n, double element)
{
	for (int i = 0; i < n; i++) {
		if (element == array[i])
			return i;
	}
	return -1;
}

double* full_elements(double* array, int n)
{
	for (int i = 0; i < n; i++) {
		array[i] = -30 + rand() % 61;
	}
}

int put_elements(double* array, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%lf\n", array[i]);
	}
}
double* calc_elements(double* array, int n)
{
	for (int i = 0; i < n; i++) {
		if (array[i] < 0) {
			array[i] = 0; 
		}
	}
}
int sum_elements(double* array, int begin, int end)
{
	int sum = 0;

	while (begin <= end) {
		sum += array[begin];
		begin += 1;
	}
	return sum;
}
int poiskpol1(double* array, int n)
{
	int poslpol;
	for (int i = 0; i < n; i++) {
		if (array[i] > 0) {
			poslpol = array[i];
		}
	}
	return poslpol;
}
double poiskpol2(double* array, int n)
{
	double poslpol;
	for (int i = 0; i < n; i++) {
		if (array[i] > 0) {
			poslpol = array[i];
		}
	}
	return poslpol;
}

int main()
{
	double array[100];
	int size;
	setlocale(LC_ALL, "RUS");

	printf("Введите размер массива > ");
	scanf("%d", &size);

	//Задание 1
	full_elements(array, size);
	calc_elements(array, size);
	put_elements(array, size);
	//Задание 2
	printf("Сумма элементов с 3 по 12: %d\n", sum_elements(array, 3, 12)); 
	printf("Индекс элемента 15.0: %d\n", find_element(array, size, 15.0));
	//Задание 3(инд)
	printf("Последний положительный элемент в int: %d\n", poiskpol1(array, size));
	printf("Последний положительный элемент в double: %lf", poiskpol2(array, size));

}
