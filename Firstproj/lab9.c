#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#define ROW 9
#define COL 9
#define COL2 10


void task1()
{
	int row, col;

	printf("\n");
	for (row = 1; row <= ROW; row++) {
		for (col = 1; col <= COL; col++) {
			printf("%5d", col * row);
			if (col == row) {
				printf("\n");
				break;
			}
		}
			
	}
	system("pause");
}

void task2() //вариант 3
{
	int row, col, number1, number2, number3;

	puts("Введите числа с индексом 11 и конечное число с индексом n10");
	scanf("%d%d", &number1, &number3);
	number2 = number1;
	printf("%d %d %d", number1, number2, number3);


	printf("\n");
	for (row = 1; row <= ((number3 / 10)  - (number1 / 10)); row++) {
		for (col = 1; col <= COL2; col++) {
			if (row == 1 && col == 1) {
				printf("%5d", number1);
				number2 += 1;
			}
			else {
				if (number2 % 10 == 1)
					printf("\n");
				printf("%5d", number2);
				number2 += 1;
			}
		}

	}
}


void task3() //3 вариант
{
	int a, b;
	char c;

	printf("Введите значение стороны стороны и символ: ");
	scanf("%d %c", &b, &c);
	

	for (int i = 1; i <= b; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%c", c);
		}
		printf("\n");
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
