#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

void sort_select(int* array, int n)
{
	int max, nom, b;


	for (int i = 0; i < n; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++)
			if (array[max] > array[j])
				max = j;
		b = array[max];
		array[max] = array[i];
		array[i] = b;
	}
}

void task1()
{
	int k, n;
	int array[20];

	for (int i = 0; i < 5; i++) {
		array[i] = rand() % 20;
	}
	puts("Исходный массив: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", array[i]);
	}
	sort_select(array, 5);
	puts("\nПосле сортировки: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", array[i]);
	}

}

int main()
{
	setlocale(LC_ALL, "RUS");
	task1();
	//task2();
	//task3();
}
