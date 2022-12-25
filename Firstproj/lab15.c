#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void task1()
{
	double a[50][50];
	int str, stl, stlmax;
	double maxvstl = 0;
	//1 индекс - целая, 2 индекс - дробная
	printf("Введите кол-во строк: ");
	scanf("%d", &str);
	printf("Введите кол-во столбцов: ");
	scanf("%d", &stl);
	for (int i = 0; i < str; i++) {
		for (int j = 0; j < stl; j++) {
			if (j < 10)
				a[i][j] = i + (double) j / 10;
			else a[i][j] = i + (double) j / 100;
		}
	}
	//Вывод в виде таблицы
	for (int i = 0; i < stl; i++) {
		printf("%5d", i);
	}
	for (int i = 0; i < str; i++) {
		printf("\n%d", i);
		for (int j = 0; j < stl; j++) {
			printf(" %.2lf", a[i][j]);
		}
	}
	//Элемент в правом нижнем углу массива
	printf("\nЭлемент в правом нижнем углу массива: %lf\n", a[str-1][stl-1]);
	//Элемент массива максимальный в указанном столбце
	printf("Введите столбец: ");
	scanf("%d", &stlmax);

	for (int i = 0; i <= str; i++) {
		if (a[i][stlmax] > maxvstl)
			maxvstl = a[i][stlmax];
	}

	printf("Максимальный элемент в %d столбце равен %lf", stlmax, maxvstl);
}

void output(int array[][7], int a)
{
	for (int i = 0; i < a; i++) {
		puts("");
		for (int j = 0; j < 7; j++) {
			printf("array[%d][%d] = %-5d", i, j, array[i][j]);
		}
	}
}
void maxel(int array[][7], int a)
{
	int max = -1111, maxi, maxj;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (array[i][j] > max) {
				max = array[i][j];
				maxi = i;
				maxj = j;
			}
			if (array[i][j] == max && maxi < i) {
				max = array[i][j];
				maxi = i;
				maxj = j;
			}
		}
	}
	printf("\nИндексы максимального элемента  [%d][%d]", maxi, maxj);
}
void task2()
{
	int a[7][7];
	int atrans[7][7];
	int k = 0, kpar = 0;
	//2.1 перевод в транспонированную матрицу
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			a[i][j] = -10 + rand() % 21;
		}
	}
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			atrans[i][j] = a[j][i];
		}
	}
	output(a, 7);
	puts("");
	output(atrans, 7);
	//2.2 кол-во ненулевых элементов первой строки массива
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 7; j++) {
			if (atrans[i][j] != 0)
				k += 1;
		}
	}
	printf("\nКол-во ненулевых элементов первой строки массива: %d\n", k);
	//Кол-во пар одинаковых соседних элементов
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (atrans[i][j] == atrans[i][j + 1])
				kpar += 1;
			if (atrans[i][j] == atrans[i + 1][j])
				kpar += 1;
			
		}
	}
	printf("Кол-во пар одинаковых соседних элементов равно: %d", kpar);
	//Координаты максимального элемента самого нижнего
	maxel(atrans, 7);
}
void task3()
{
	//Баллы спортсменов
	int table[20][5];
	int sum = 0;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 5; j++) {
			table[i][j] = rand() % 10;
		}
	}
	for (int i = 0; i < 20; i++) {
		printf("\nСпортсмен %2d: ", i + 1);
		for (int j = 0; j < 5; j++) {
			printf("%7d баллов ", table[i][j]);
		}
	}
	//Сумма баллов третьего спортсмена
	for (int i = 2; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			sum += table[i][j];
		}
	}
	printf("\nСумма баллов третьего спортсмена: %d", sum);
}
int main()
{
	setlocale(LC_ALL, "RUS");
	task1();
	//task2();
	//task3();
}
