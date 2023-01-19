#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


void Source_table();
void Result_table();
int search(int** array, int* array2, int n);
int sort(int** array);
int total_points(int** array);
int average_points(int** array);
int max_points(int** array);
int min_points(int** array);
int** randomznach(int** array);

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int sum = 0, kol = 0, n = 0, point = 1;
	int table[9][12];
	int comandlist[9];
	int comandlist2[9];





	
	while (point != 7) {
		printf("МЕНЮ:\n1. Чтение значений из файла и вывод исходной таблицы.\n2. Вывод результирующей таблицы(очки/места)\n3. Заполнение таблицы случайными значениями\n\
4. Поиск команд, набравших более n очков.\n5. Сортировка таблицы по убыванию.\n6. Вычислить общее, среднее, минимальное и максимальное количество очков по командам спортсменам.\n7. Завершение программы.");
		scanf("%d", &point);
		switch (point)
		{
		case 1:
			system("cls");
			Source_table(table);
			break;
		case 2:
			system("cls");
			Result_table(table);
			break;
		case 3:
			system("cls");
			randomznach(table);
			break;
		case 4:
			system("cls");
			printf("Введите кол-во очков:\n");
			scanf("%d", &n);
			kol = search(table, comandlist, n);
			for (int i = 0; i < kol; i++) {
				printf("%d ", comandlist[i]);
			}
			break;
		case 5:
			system("cls");
			sort(table, comandlist2);
			break;
		case 6:
			system("cls");
			printf("МЕНЮ:\n1. Общее кол-во очков.\n2. Среднее кол-во очков.\n3. Минимальное кол-во очков.\n4. Максимальное кол-во очков.");
			scanf("%d", &point);
			switch (point)
			{
			case 1:
				system("cls");
				printf("Общее кол-во очков, набранных всеми командами равно: %d\n", total_points(table));
				break;
			case 2:
				system("cls");
				printf("Среднее кол-во очков, набранных всеми командами равно: %d\n", average_points(table));
				break;
			case 3:
				system("cls");
				printf("Минимальное кол-во очков среди всех команд равно: %d\n", min_points(table));
				break;
			case 4:
				system("cls");
				printf("Максимальное кол-во очков среди всех команд: %d\n", max_points(table));
				break;
			}
		case 7:
			break;
		default:
			printf("Я таких значений не знаю\n");
			break;
		}

	}
	
	return 0;
}

int** randomznach(int array[9][12])
{
	
	int sum;
	for (int i = 0; i < 9; i++) {
		sum = 0;
		for (int j = 0; j < 11; j++) {
			if (i == j) {
				array[i][j] = -1;
			}
			else if (j < 9 && ((array[i][j] + array[j][i]) != 3)) {
				array[i][j] = rand() % 4;
				array[j][i] = 3 - array[i][j];
			}
		}
	}

	printf("Турнирная таблица:\n");
	printf("   № команды	 0	 1	 2	 3	 4	 5	 6	 7	 8\n");
	for (int i = 0; i < 9; i++) {
		printf("	%d ", i);
		for (int j = 0; j < 9; j++) {
			if (i == j)
				printf("%8c", 'o');
			else 
				printf("%8d", array[i][j]);
		}
		printf("\n");
	}

	return array;
}



void Source_table(int array[9][12])
{
	char fname[20] = "znachtable.txt";
	FILE* out;

	out = fopen("znachtable.txt", "r");
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == j)
				array[i][j] = -1;
			else if ((array[i][j] + array[j][i]) != 3) {
				fscanf(out, "%d", &array[i][j]);
				array[j][i] = 3 - array[i][j];
			}
		}
	}

	printf("Турнирная таблица:\n");
	printf("   № команды	 0	 1	 2	 3	 4	 5	 6	 7	 8\n");
	for (int i = 0; i < 9; i++) {
		printf("	%d ", i);
		for (int j = 0; j < 9; j++) {
			if (i == j)
				printf("%8c", 'o');
			else 
				printf("%8d", array[i][j]);
		}
		printf("\n");
	}


}

void Result_table(int array [9][12])
{
	int max = -111, flag = 0, sum, maxi = 0, maxj = 0;
	int maxpr[9];
	int maxind[9];
	for (int i = 0; i < 9; i++) {
		sum = 0;
		for (int j = 0; j < 10; j++) {
			if (j < 9 && i != j) {
				sum += array[i][j];
			}
			else if (j == 9) {
				array[i][j] = sum;
			}
		}
	}
	for (int k1 = 0; k1 < 9; k1++) {		//ЗАПОЛНЕНИЕ СТОЛБЦА С МЕСТАМИ
		max = -111;
		for (int k2 = 0; k2 < 9; k2++) {
			for (int k3 = 9; k3 < 10; k3++) {
				if (array[k2][k3] > max) {
					for (int k4 = 0; k4 < 9; k4++) {
						if (array[k2][k3] == maxpr[k4]) {
							for (int k5 = 0; k5 < 9; k5++) {
								if ((k2 + k3) == maxind[k5])
									flag = 1;

							}
						}

					}
					if (flag == 0) {
						max = array[k2][k3];
						maxi = k2;
						maxj = k3;
					}
					flag = 0;
				}
			}
		}
		maxpr[k1] = max;
		maxind[k1] = maxi + maxj;
		array[maxi][maxj + 1] = k1 + 1;
	}


	//ВЫВОД РЕЗУЛЬТИРУЮЩЕЙ ТАБЛИЦЫ
	printf("Результирующая турнирная таблица:\n");
	printf("   № команды	 0	 1	 2	 3	 4	 5	 6	 7	 8     Очки    Место\n");
	for (int i = 0; i < 9; i++) {
		printf("	%d ", i);
		for (int j = 0; j < 11; j++) {
			if (i == j)
				printf("%8c", 'o');
			else
				printf("%8d", array[i][j]);
		}
		printf("\n");
	}
}

int search(int array [9][12], int* array2, int n) // Поиск команд, набравших более 11 очков
{
	int kol = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 9; j < 10; j++) {
			if (array[i][j] > n) {
				array2[kol] = i;
				kol += 1;
			}
		}
	}
	return kol;
}
int sort(int array[9][12]) //Функция сортировки записей 
{
	int tmp;
	
	for (int i = 0; i < 9; i++) {
		array[i][11] = i;
	}
	for (int k = 0; k < 9; k++) {
		for (int k1 = 0; k1 < 9; k1++) {
			for (int k2 = 10; k2 < 11; k2++) {
				if (array[k1][k2] == (k + 1)) {
					for (int k3 = 0; k3 < 12; k3++) {
						tmp = array[k][k3];
						array[k][k3] = array[k1][k3];
						array[k1][k3] = tmp;

					}
				}

			}
			
			
		}
		printf("%\n");
	}
	printf("Результирующая турнирная таблица:\n");
	printf("   № команды	 0	 1	 2	 3	 4	 5	 6	 7	 8     Очки    Место\n");
	for (int i = 0; i < 9; i++) {
		printf("	%d ", array[i][11]);
		for (int j = 0; j < 11; j++) {
			if (array[i][j] == -1)
				printf("%8c", 'o');
			else
				printf("%8d", array[i][j]);
		}
		printf("\n");
	}

	return 1;
}
int total_points(int array[9][12])
{
	int total = 0;
	for (int i = 0; i < 9; i++) {
		total += array[i][9];
	}
	return total;
}
int average_points(int array[9][12])
{
	int average;
	average = total_points(array) / 9;

	return average;
}
int max_points(int array[9][12])
{
	int max = -111;

	for (int i = 0; i < 9; i++) {
		if (array[i][9] > max)
			max = array[i][9];
	}
	return max;
}
int min_points(int array[9][12])
{
	int min = 111;

	for (int i = 0; i < 9; i++) {
		if (array[i][9] < min)
			min = array[i][9];
	}
	return min;
}
