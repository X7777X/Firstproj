#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
 

struct ram* sort(struct ram* a, int* c);
struct ram* reading(int* n);
struct ram* new_entry(struct ram* b, int* c);
void output(struct ram* b, int* c);
struct ram* find_entry_amount(struct ram* a, int* c);
struct ram* edit_entry(struct ram* a);
struct ram* adding_entries_to_a_file(struct ram* a, int* c);
void writing(struct ram* a, int* c);

struct ram {
	int amount;
	char name[9];
	float supply_voltage;
	int clock_frequency;
	char type[5];
};


int main()
{
	struct ram* a;
	setlocale(LC_ALL, "RUS");
	int s = 0;
	int* n = &s;
	int point = 1;

	printf("Считывание данных из файла:\n");
	a = reading(n);
	output(a, n);


	while (point != 0) {
		printf("\n0. Выход.\n1. Поиск записей по объему/тактовой частоте оперативной памяти.\n2.Сортировка по объему оперативной памяти.\n3.Создание записи.\
				\n4. Изменение отдельных записей в файле.\n6. Добавить произвольное кол-во записей в файл.\n");
		scanf("%d", &point);
		switch (point) {
		case 1:
			find_entry_amount(a, n);
			break;
		case 2:
			sort(a, n);
			output(a, n);
			break;
		case 3:
			new_entry(a, n);
			output(a, n);
			break;
		case 4:
			edit_entry(a);
			output(a, n);
			writing(a, n);
			break;
		case 6:
			adding_entries_to_a_file(a, n);
			output(a, n);
			writing(a, n);

		}
	}

	

	return 9;
}	

struct ram* edit_entry(struct ram* a)
{
	int i;

	printf("Введите номер редактируемой записи: ");
	scanf("%d", &i);

	printf("Введите имя модуля оперативной памяти: ");
	scanf("%s", a[i - 1].name);
	printf("Введите объем модуля оперативной памяти: ");
	scanf("%d", &a[i - 1].amount);
	printf("Введите напряжение питания модуля оперативной памяти: ");
	scanf("%f", &a[i - 1].supply_voltage);
	printf("Введите тактовую частоту оперативной памяти: ");
	scanf("%d", &a[i - 1].clock_frequency);
	printf("Введите тип оперативной памяти: ");
	scanf("%s", a[i - 1].type);

	return a;
}

void writing(struct ram* a, int *c)
{
	FILE* file;

	file = fopen("entries.txt", "w");

	for (int i = 0; i < *c; i++) {
		fprintf(file, "%d. %8s %d %f %d %s\n", i + 1, a[i].name, a[i].amount, a[i].supply_voltage, a[i].clock_frequency, a[i].type);
	}

	fclose(file);
}
struct ram* reading(int* n)
{
	struct ram* a = NULL;
	FILE* file;
	int i = 0;
	file = fopen("entries.txt", "r");
	if (file == NULL) {
		puts("File could not be opened");

	}
	while (!feof(file)) {
		*n += 1;
		a = (struct ram*)realloc(a, *n * sizeof(struct ram));
		fscanf(file, "%d.%s%d%f%d%s\n", &i, &a[i].name, &a[i].amount, &a[i].supply_voltage, &a[i].clock_frequency, &a[i].type);
	}

	fclose(file);

	return a;
}

struct ram* new_entry(struct ram* b, int* c)
{
	*c += 1;
	b = (struct ram*)realloc(b, *c * sizeof(struct ram));
	printf("Введите название модуля оперативной памяти: ");
	scanf("%s", b[*c - 1].name);
	printf("Введите объем модуля оперативной памяти: ");
	scanf("%d", &b[*c - 1].amount);
	printf("Введите напряжение питания модуля оперативной памяти: ");
	scanf("%f", &b[*c - 1].supply_voltage);
	printf("Введите тактовую частоту модуля оперативной памяти: ");
	scanf("%d", &b[*c - 1].clock_frequency);
	printf("Введите тип памяти модуля оперативной памяти: ");
	scanf("%s", b[*c - 1].type);
	return b;
}

void output(struct ram* a, int* c)
{

	for (int i = 0; i < *c; i++) {
		printf("%d. Название:%11s, Объем: %2d ГБ, Напряжение питания: %.1f В, Тактовая чистота: %d МГц, Тип памяти: %s;\n", i + 1, a[i].name, a[i].amount, a[i].supply_voltage, a[i].clock_frequency, a[i].type);
	}
}
struct ram* find_entry_amount(struct ram* a, int* c)
{
	int point, amount1, clock_frequency1;
	printf("1. Поиск по объему памяти.\n2. Поиск по тактовой частоте.\n3. Поиск по объему и тактовой частоте ОЗУ.\n");
	scanf("%d", &point);
	switch (point) {
	case 1:
		printf("Введите значение для поиска по объему памяти: ");
		scanf("%d", &amount1);

		for (int i = 0; i < *c; i++) {
			if (a[i].amount == amount1)
				printf("%d. Название:%11s, Объем: %2d ГБ, Напряжение питания: %.1f В, Тактовая чистота: %d МГц, Тип памяти: %s;\n", i + 1, a[i].name, a[i].amount, a[i].supply_voltage, a[i].clock_frequency, a[i].type);
		}
		break;
	case 2: 
		printf("Введите значение для поиска по объему памяти: ");
		scanf("%d", &clock_frequency1);
		for (int i = 0; i < *c; i++) {
			if (a[i].clock_frequency == clock_frequency1)
				printf("%d. Название:%11s, Объем: %2d ГБ, Напряжение питания: %.1f В, Тактовая чистота: %d МГц, Тип памяти: %s;\n", i + 1, a[i].name, a[i].amount, a[i].supply_voltage, a[i].clock_frequency, a[i].type);
		}
		break;
	case 3:
		printf("Введите значение объема памяти: ");
		scanf("%d", &amount1);
		printf("Введите значение тактовой частоты памяти: ");
		scanf("%d", &clock_frequency1);
		for (int i = 0; i < *c; i++) {
			if ((a[i].amount == amount1) && (a[i].clock_frequency == clock_frequency1))
				printf("%d. Название:%11s, Объем: %2d ГБ, Напряжение питания: %.1f В, Тактовая чистота: %d МГц, Тип памяти: %s;\n", i + 1, a[i].name, a[i].amount, a[i].supply_voltage, a[i].clock_frequency, a[i].type);
		}
		break;
	}

	return a;

}

struct ram* sort(struct ram* a, int* c)
{
	int maxPosition;
	struct temp {
		int amount;
		char name[9];
		float supply_voltage;
		int clock_frequency;
		char type[5];
	}tmp;
	for (int i = 0; i < *c; i++)
	{
		maxPosition = i;
		for (int j = i + 1; j < *c; j++)
			if (a[maxPosition].amount < a[j].amount)
				maxPosition = j;

		for (int k = 0; k < 9; k++) {
			tmp.name[k] = a[maxPosition].name[k];
			a[maxPosition].name[k] = a[i].name[k];
			a[i].name[k] = tmp.name[k];
		}

		for (int k = 0; k < 5; k++) {
			tmp.type[k] = a[maxPosition].type[k];
			a[maxPosition].type[k] = a[i].type[k];
			a[i].type[k] = tmp.type[k];
		}

		tmp.amount = a[maxPosition].amount;
		tmp.supply_voltage = a[maxPosition].supply_voltage;
		tmp.clock_frequency = a[maxPosition].clock_frequency;
		a[maxPosition].amount = a[i].amount;
		a[maxPosition].supply_voltage = a[i].supply_voltage;
		a[maxPosition].clock_frequency = a[i].clock_frequency;
		a[i].amount = tmp.amount;
		a[i].supply_voltage = tmp.supply_voltage;
		a[i].clock_frequency = tmp.clock_frequency;
	}

	return a;
}
struct ram* adding_entries_to_a_file(struct ram* a, int *c)
{
	int s = 1;

	while (s != 2)
	{
		new_entry(a, c);
		printf("Ввести еще одну запись? - 1/2");
		scanf("%d", &s);
	}
	return a;
}
