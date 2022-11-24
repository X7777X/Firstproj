#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int A[9][11];
void sportoutput()
{
	printf("Вид спорта - волейбол");
}
void alltableoutput()
{
	printf("Турнирная таблица:\n");
	printf("   № команды	 0	 1	 2	 3	 4	 5	 6	 7	 8     Очки    Место\n");
	for (int i = 0; i < 9; i++) {
		printf("	%d ", i);
		for (int j = 0; j < 11; j++) {
			printf("%8d", A[i][j]);
		}
		printf("\n");
	}
}
void _1playoutput(a, b)
{
	printf("Результат относительно 1 команды: ");
	printf("[%d] [%d] = %4c", a, b, A[a][b]);
}
int main()
{
	setlocale(LC_ALL, "RUS");
	int i, j;
	int n, a, b;


	printf("Введите 1 для вывода вида спорта\n2 - для вывода турнирной таблицы\n3 - для вывода результата конкретного матча\n");
	scanf("%d", &n);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 11; j++) {
			if (i == j)
				A[i][j] = 0;
			else if ((rand() % 2) == 0)
				A[i][j] = 0;
			else
				A[i][j] = 0;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 11; j++) {
			if (i == j)
				A[i][j] = -1;
			else {
				A[i][j] = rand() % 4;
				A[j][i] = 3 - A[i][j];
			}
		}
	}
	switch (n)
	{
	case 1:
		sportoutput();
		break;
	case 2:
		alltableoutput();
		break;
	case 3:
		printf("Индексы команд:\nВолгоград - 0\nЕкатеринбург - 1\nМосква - 2\nНовотроицк - 3\nОренбург - 4\nОмск - 5\nХромтау - 6\nЧелябинск - 7\n");
		printf("Введите индексы команд:");
		scanf("%d%d", &a, &b);
		_1playoutput(a, b);
		break;
	default:
		printf("Я таких значений не знаю");
	}


	return 0;
}
