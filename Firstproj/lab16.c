#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

void task1()
{
	//два динамических массива, второй с обнулением
	int* array;
	int* array1;
	int size;

	printf("Введите размер массива: ");
	scanf("%d", &size);

	array = (int*)malloc(size * sizeof(int));

	if (array == NULL) {
		puts("error");
		return -1;
	}
	array1 = (int*)malloc(size * sizeof(int));
	if (array == NULL) {
		puts("error");
		return -1;
	}
	
	for (int i = 0; i < size; i++) {
		array[i] = -100 + rand() % 201;
	}
	for (int i = 0; i < size; i++) {
		printf("%d\n", array[i]);
	}
	for (int i = 0; i < size; i++) {
		if (array[i] < 0)
			array1[i] = 0;
		else array1[i] = array[i];
	}
	puts("");
	for (int i = 0; i < size; i++) {
		printf("%d\n", array1[i]);
	}
	free(array);
	free(array1);

}
int delete_k(double* ptr_arr, int size, int k) {


	int n = size - 1;
	for (int i = k; i < (size - 1); i++) 
		ptr_arr[i] = ptr_arr[i + 1];
	return n;

}
double* insert(double* ptr_arr, int* size, int index, int num) {
	int size_n = (*size) + 1;
	if (ptr_arr == NULL) return NULL;
	double* ptr_arr_n = (double*)realloc(ptr_arr, size_n * sizeof(double));
	if (ptr_arr_n == NULL) return ptr_arr;
	ptr_arr = ptr_arr_n;
	for (int i = size_n - 1; i > index; i--)
		ptr_arr[i] = ptr_arr[i - 1];
	ptr_arr[index] = num;
	*size = size_n;
	return ptr_arr;
}
int find_element(double* ptr_array, int n, double element) {
	int elementId = -1;
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] == element) {
			elementId = i + 1;
		}
	}
	return elementId;
}

void task2()
{
	double* array;
	int size, k;

	printf("Введите размер массива: ");
	scanf("%d", &size);

	array = (int*)malloc(size * sizeof(double));
	if (array == NULL) {
		puts("error");
		return -1;
	}

	for (int i = 0; i < size; i++) {
		array[i] = -1 + (rand() / (double)RAND_MAX) * 2;
	}

	for (int i = 0; i < size; i++) {
		printf("%lf\n", array[i]);
	}
	double max1 = -100000, max2 = -100000;
	for (int i = 0; i < size; i++) {
		if (array[i] > max1) {
			max2 = max1;
			max1 = array[i];
		}
	}
	printf("\n\nMax 1 = %lf; Max 2 = %lf", max1, max2);
	delete_k(array, size, max1);
	size--;
	delete_k(array, size, max2);
	size--;
	puts("\n\n\n");
	for (int i = 0; i < size; i++) {
		printf("array[%d] = %lf\n", i, array[i]);
	}

	//2.2
	double max = -10000;
	for (int i = 0; i < size; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	printf("\n\nMax = %lf;\n", max);
	insert(array, &size, find_element(array, size, max), -999);
	for (int i = 0; i < size; i++) {
		printf("array[%d] = %lf\n", i, array[i]);
	}

}
double* a(double* arr1, double* arr2, double* arr3, int size) {
	double* arr = (double*)malloc(size * sizeof(double));
	for (int i = 0; i < size; i++) {
		arr[i] = (arr1[i] + arr2[i] + arr3[i]) / 3;
		printf("array[%d] = %lf\n", i, arr[i]);
	}
	return arr;
}
void task3()
{
	//Среднее арифм. из трех массивов
	int size1 = 10 + rand() % 50 - 10;
	int size2 = 10 + rand() % 50 - 10;
	int size3 = 10 + rand() % 50 - 10;
	double* arr1 = (double*)malloc(size1 * sizeof(double));
	double* arr2 = (double*)malloc(size2 * sizeof(double));
	double* arr3 = (double*)malloc(size3 * sizeof(double));
	puts("ARR 1 \n\n ");
	for (int i = 0; i < size1; i++) {
		arr1[i] = -10 + 1.f * (20 - -10) * rand() / RAND_MAX;
		printf("array[%d] = %lf\n", i, arr1[i]);
	}
	puts("ARR 2\n\n");
	for (int i = 0; i < size2; i++) {
		arr2[i] = -10 + 1.f * (20 - -10) * rand() / RAND_MAX;
		printf("array[%d] = %lf\n", i, arr2[i]);
	}
	puts("ARR 3\n\n");
	for (int i = 0; i < size3; i++) {
		arr3[i] = -10 + 1.f * (20 - -10) * rand() / RAND_MAX;
		printf("array[%d] = %lf\n", i, arr3[i]);
	}
	int minSize;
	if (size2 < size1 && size2 < size3) {
		minSize = size2;
	}
	else if (size3 < size2 && size3 < size1) {
		minSize = size3;
	}
	else {
		minSize = size1;
	}
	puts("ARR 4\n\n");
	a(arr1, arr2, arr3, minSize);
	return 0;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	task1();
	//task2();
	//task3();
}
