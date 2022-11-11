#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void task1()
{
	int* pi, i = 5;
	float* pf, f = 2.1f;
	char* pc, c = '2';
	double* pd, d = 2.12939123;

	printf("%lu\n", sizeof(pi));
	printf("%lu\n", sizeof(pf));
	printf("%lu\n", sizeof(pc));
	printf("%lu\n", sizeof(pd));

}
void task2()
{
	float PI = 3.14159, * p1, * p2;
	p1 = p2 = &PI;

	printf("По адресу p1=%x хранится *p1=%g\n", p1, *p1);
	printf("По адресу p2=%x хранится *p2=%g\n", p2, *p2);
}
void task3()
{
	_Bool* pa, x = 1;
	pa = &x;

	printf("По адресу %x хранится *ptr=%d\n", pa, *pa);
	pa++;
	printf("По адресу %x хранится *ptr=%d\n", pa, *pa);
	pa--;
	printf("По адресу %x хранится *ptr=%d\n", pa, *pa); //char, _Bool - 1; double - 8; long double - 8, unsigned short int - 8;
}
void task4()
{
	float array[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 11};
	float *ptr_a = &array;

	printf("адрес array: %p, адрес &array[0]: %p, адрес array: %p\n", array, &array[0], &array);
	printf("Адрес указателя ptr_a: %x; Значение указателя ptr_a: %f\n Адрес указателя ptr_a+4: %x; Значение указателя ptr_a+4: %f\nАдрес указателя ptr_a-2: %x; Значение указателя ptr_a-2: %f\n", ptr_a, *ptr_a, ptr_a + 4, *(ptr_a + 4), ptr_a - 2, *(ptr_a-2));

	//4.3
	for (int i = 0; i < 5; i++) {
		printf("После увеличения указателя на %d значение указателя равно %f\n", 2*i, *ptr_a);
		ptr_a = ptr_a + 2;
	}
	//4.4
	printf("\n");
	ptr_a = ptr_a--;
	for (int i = 0; i < 10; i++) {
		printf("После уменьшения указателя на %d значение указателя равно %f\n", i, *ptr_a);
		ptr_a = ptr_a--;
	}

}
void btint(int x)
{
	for (int i = 0; i <= (sizeof(x) - 1); i++) {
		printf("Байт %d: ", i + 1);
		printf("%02x\n", *((char*)&x + i));
	}
}
void btfloat(float x)
{
	for (int i = 0; i <= (sizeof(x) - 1); i++) {
		printf("Байт %d: ", i + 1);
		printf("%02x\n", *((char*)&x + i));
	}
}
void btdouble(double x)
{
	for (int i = 0; i <= (sizeof(x) - 1); i++) {
		printf("Байт %d: ", i + 1);
		printf("%02x\n", *((char*)&x + i));
	}
}
void task5()
{
	int x = 0x12345678;
	int* prt;
	unsigned char* a1, * a2, * a3, * a4;
	unsigned char* a;

	prt = &x;
	a = (unsigned char*)prt;

	a1 = a + 3;
	a2 = a + 2;
	a3 = a + 1;
	a4 = a;

	printf("%.2x\n%.2x\n%.2x\n%.2x\n", *a1, *a2, *a3, *a4);
	//Усовершенствуйте программу так, чтобы она могла побайтно выводить переменные любого типа.
	int ai = 12345.0;
	float af = 12345.0;
	double ad = 12345.0;

	btint(ai);
	puts("");
	btfloat(af);
	puts("");
	btdouble(ad);
}

int main()
{
	setlocale(LC_ALL, "RUS");

	//task1();
	//task2();
	//task3();
	//task4();
	task5();

	return 0;
}
