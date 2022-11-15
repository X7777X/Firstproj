#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

char A[9][9];
void sportoutput()
{
	printf("Вид спорта - волейбол");
}
void alltableoutput()
{
	printf("Турнирная таблица:\n");
	printf("	0	1	2	3	4	5	6	7	8\n");
	for (int i = 0; i < 9; i++) {
		printf("%d ", i);
		for (int j = 0; j < 9; j++) {
			printf("	%c", A[i][j]);
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
		for (int j = 0; j < 9; j++) {
			if (i == j)
				A[i][j] = "!";
			else if ((rand() % 2) == 0)
				A[i][j] = 'W';
			else
				A[i][j] = 'L';
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
		printf("Индексы команд:\nАрзамас - 0\nВятич - 1\nТранспневматика - 2\nМеталлург - 3\nАрзамасский район - 4\nСпартак - 5\nСергач - 6\nАвтодеталь - 7\n");
		printf("Введите индексы команд:");
		scanf("%d %d", &a, &b);
		_1playoutput(a, b);
		break;
	default:
		printf("Я таких значений не знаю");
	}
	
	
	return 0;
}
