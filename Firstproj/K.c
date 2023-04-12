#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


struct ram* sort(struct ram* dynamic_array, int* ptr_to_number_of_elements, int point);
struct ram* reading(int* ptr_to_number_of_elements);
struct ram* new_entry(struct ram* dynamic_array, int* ptr_to_number_of_elements);
void output(struct ram* dynamic_array, int* ptr_to_number_of_elements);
struct ram* find_entry(struct ram* dynamic_array, int i, int point, int first_value_of_range,
	int second_value_of_range, int first_value_of_range2, int second_value_of_range2);
struct ram* edit_entry(struct ram* dynamic_array);
void writing(struct ram* dynamic_array, int* ptr_to_number_of_elements);

struct ram
{
	int amount;
	char name[9];
	float supply_voltage;
	int clock_frequency;
	char type[5];
};

/*------------главная функция, ----------------------------------------
--------------выполняет диалог с пользователем-----------------------*/
int main()
{
	struct ram* dynamic_array;
	system("chcp 1251");
	int number_of_dynArray_elements = 0, first_value_of_range = 0, second_value_of_range = 0, index_of_element = 0, first_value_of_range2 = 0, second_value_of_range2 = 0;

	int point = 1;

	printf("Считывание данных из файла:\n");
	dynamic_array = reading(&number_of_dynArray_elements);
	output(dynamic_array, &number_of_dynArray_elements);


	while (point != 0)
	{
		printf("\n0. Выход.\n1. Поиск записей по объему/тактовой частоте оперативной памяти.\n2. Сортировка по объему оперативной памяти.\n3. Создание записи.\
				\n4. Изменение отдельных записей в файле.\n5. Запись всех данных в файл.\n6. Добавить произвольное кол-во записей в файл.\n\nВы ввели: ");
		scanf("%d", &point);
		switch (point)
		{
		case 0:
			break;
		case 1:
			index_of_element = 0;
			printf("1. Поиск по объему памяти.\n2. Поиск по тактовой частоте.\n3. Поиск по объему и тактовой частоте ОЗУ.\n\nВы ввели: ");
			scanf("%d", &point);
			switch (point)
			{
			case 1:
				printf("Введите значения для поиска по объему памяти(от и до): ");
				scanf("%d%d", &first_value_of_range, &second_value_of_range);
				for (int i = 0; i < number_of_dynArray_elements; i++)
				{
					index_of_element = find_entry(dynamic_array, i, point, first_value_of_range, second_value_of_range, first_value_of_range2, second_value_of_range2);
					if (index_of_element != -1)
					{
						printf("%d. Название:%11s, Объем: %2d ГБ, Напряжение питания: %.1f В, Тактовая чистота: %d МГц, Тип памяти: %s;\n", index_of_element + 1, dynamic_array[index_of_element].name, dynamic_array[index_of_element].amount,
							dynamic_array[index_of_element].supply_voltage, dynamic_array[index_of_element].clock_frequency, dynamic_array[index_of_element].type);
					}
				}
				break;
			case 2:
				printf("Введите значения для поиска по тактовой частоте(от и до): ");
				scanf("%d%d", &first_value_of_range, &second_value_of_range);
				for (int i = 0; i < number_of_dynArray_elements; i++)
				{
					index_of_element = find_entry(dynamic_array, i, point, first_value_of_range, second_value_of_range, first_value_of_range2, second_value_of_range2);
					if (index_of_element != -1)
					{
						printf("%d. Название:%11s, Объем: %2d ГБ, Напряжение питания: %.1f В, Тактовая чистота: %d МГц, Тип памяти: %s;\n", index_of_element + 1, dynamic_array[index_of_element].name, dynamic_array[index_of_element].amount,
							dynamic_array[index_of_element].supply_voltage, dynamic_array[index_of_element].clock_frequency, dynamic_array[index_of_element].type);
					}
				}
				break;
			case 3:
				printf("Введите диапазон для  объема памяти: ");
				scanf("%d%d", &first_value_of_range, &second_value_of_range);
				printf("Введите диапазон для тактовой частоты памяти: ");
				scanf("%d%d", &first_value_of_range2, &second_value_of_range2);
				for (int i = 0; i < number_of_dynArray_elements; i++)
				{
					index_of_element = find_entry(dynamic_array, i, point, first_value_of_range, second_value_of_range, first_value_of_range2, second_value_of_range2);
					if (index_of_element != -1)
					{
						printf("%d. Название:%11s, Объем: %2d ГБ, Напряжение питания: %.1f В, Тактовая чистота: %d МГц, Тип памяти: %s;\n", index_of_element + 1, dynamic_array[index_of_element].name, dynamic_array[index_of_element].amount,
							dynamic_array[index_of_element].supply_voltage, dynamic_array[index_of_element].clock_frequency, dynamic_array[index_of_element].type);
					}
				}
				break;
			}
			break;
		case 2:
			printf("1. Сортировка по убыванию.\n2. Сортировка по возрастанию.\n\nВы ввели: ");
			scanf("%d", &point);
			if ((point == 1) || (point == 2)) {
				sort(dynamic_array, &number_of_dynArray_elements, point);
				output(dynamic_array, &number_of_dynArray_elements);
			}
			else 
				printf("Введено неправльное значение.\n");
			break;
		case 3:
			printf("Введите название, объем, напряжение питания, тактовую частоту, тип памяти модуля оперативной памяти:\n");
			new_entry(dynamic_array, &number_of_dynArray_elements);
			output(dynamic_array, &number_of_dynArray_elements);
			break;
		case 4:

			printf("Введите номер редактируемой записи: ");
			scanf("%d", &point);
			printf("Введите название, объем, напряжение питания, тактовую частоту, тип памяти модуля оперативной памяти:\n");
			edit_entry(dynamic_array, point);
			output(dynamic_array, &number_of_dynArray_elements);
			writing(dynamic_array, &number_of_dynArray_elements);
			break;
		case 5:
			writing(dynamic_array, &number_of_dynArray_elements);
			break;
		case 6:
			while (point != 2)
			{
				new_entry(dynamic_array, &number_of_dynArray_elements);
				printf("Ввести еще одну запись? - 1/2\nВы ввели: ");
				scanf("%d", &point);
			}
			output(dynamic_array, &number_of_dynArray_elements);
			writing(dynamic_array, &number_of_dynArray_elements);
			break;
		default:
			printf("Введено неправильное значение.\n");
		}
	}



	return 2;
}

//FUNCTIONS
//------------редактировать запись в динамическом массиве структур
struct ram* edit_entry(struct ram* dynamic_array, int i)
{
	scanf("%s", dynamic_array[i - 1].name);
	scanf("%d", &dynamic_array[i - 1].amount);
	scanf("%f", &dynamic_array[i - 1].supply_voltage);
	scanf("%d", &dynamic_array[i - 1].clock_frequency);
	scanf("%s", dynamic_array[i - 1].type);

	return dynamic_array;
}

//------------запись данных из динамического массива структур в файл
void writing(struct ram* dynamic_array, int* ptr_to_number_of_elements)
{
	FILE* file;

	file = fopen("entries.txt", "w");

	for (int i = 0; i < *ptr_to_number_of_elements; i++)
	{
		fprintf(file, "%d. %8s %d %f %d %s\n", i + 1, dynamic_array[i].name, dynamic_array[i].amount, dynamic_array[i].supply_voltage, dynamic_array[i].clock_frequency, dynamic_array[i].type);
	}

	fclose(file);
}

//------------Чтение записей из файла 
struct ram* reading(int* ptr_to_number_of_elements)
{

	FILE* file;
	struct ram* dynamic_array = NULL;
	int i = 0;
	file = fopen("entries.txt", "r");
	if (file == NULL)
	{
		puts("Файл не может быть открыт.");
	}
	else
	{
		while (!feof(file))
		{
			*ptr_to_number_of_elements += 1;
			dynamic_array = (struct ram*)realloc(dynamic_array, *ptr_to_number_of_elements * sizeof(struct ram));
			fscanf(file, "%d.%s%d%f%d%s\n", &i, &dynamic_array[i].name, &dynamic_array[i].amount, &dynamic_array[i].supply_voltage, &dynamic_array[i].clock_frequency, &dynamic_array[i].type);
		}

	}

	fclose(file);

	return dynamic_array;
}

//------------Создать новую запись
struct ram* new_entry(struct ram* dynamic_array, int* ptr_to_number_of_elements)
{
	*ptr_to_number_of_elements += 1;

	dynamic_array = (struct ram*)realloc(dynamic_array, *ptr_to_number_of_elements * sizeof(struct ram));
	scanf("%s", dynamic_array[*ptr_to_number_of_elements - 1].name);
	scanf("%d", &dynamic_array[*ptr_to_number_of_elements - 1].amount);
	scanf("%f", &dynamic_array[*ptr_to_number_of_elements - 1].supply_voltage);
	scanf("%d", &dynamic_array[*ptr_to_number_of_elements - 1].clock_frequency);
	scanf("%s", dynamic_array[*ptr_to_number_of_elements - 1].type);

	return dynamic_array;
}


//------------Вывод элементов(записей) динамического массива структур 
void output(struct ram* dynamic_array, int* ptr_to_number_of_elements)
{


	for (int i = 0; i < *ptr_to_number_of_elements; i++)
	{
		printf("%d. Название:%11s, Объем: %2d ГБ, Напряжение питания: %.1f В, Тактовая чистота: %d МГц, Тип памяти: %s;\n", i + 1, dynamic_array[i].name,
			dynamic_array[i].amount, dynamic_array[i].supply_voltage, dynamic_array[i].clock_frequency, dynamic_array[i].type);
	}


}

//------------Найти записи по критериям: Объем памяти/Тактовая частота
struct ram* find_entry(struct ram* dynamic_array, int i, int point, int first_value_of_range, int second_value_of_range, int first_value_of_range2, int second_value_of_range2)
{
	switch (point)
	{
	case 1:
		if ((dynamic_array[i].amount >= first_value_of_range) && (dynamic_array[i].amount <= second_value_of_range)) return i;
		else return -1;
	case 2:
		if ((dynamic_array[i].clock_frequency >= first_value_of_range) && (dynamic_array[i].clock_frequency <= second_value_of_range)) return i;
		else return -1;
	case 3:
		if (((dynamic_array[i].amount >= first_value_of_range) && (dynamic_array[i].amount <= second_value_of_range)) &&
			((dynamic_array[i].clock_frequency >= first_value_of_range2) && (dynamic_array[i].clock_frequency <= second_value_of_range2)))   return i;
		else return -1;
	}
}

//------------Сортировка динамического массива структур выбором по возрастанию/убыванию
struct ram* sort(struct ram* dynamic_array, int* ptr_to_number_of_elements, int point)
{
	int maxPosition, minPosition;

	//Структура для временного хранения записей
	struct temp {
		int amount;
		char name[9];
		float supply_voltage;
		int clock_frequency;
		char type[5];
	}tmp;


	if (point == 1)
	{
		for (int i = 0; i < *ptr_to_number_of_elements; i++)
		{
			maxPosition = i;
			for (int j = i + 1; j < *ptr_to_number_of_elements; j++)
				if (dynamic_array[maxPosition].amount < dynamic_array[j].amount)
					maxPosition = j;

			for (int k = 0; k < 9; k++)
			{
				tmp.name[k] = dynamic_array[maxPosition].name[k];
				dynamic_array[maxPosition].name[k] = dynamic_array[i].name[k];
				dynamic_array[i].name[k] = tmp.name[k];
			}

			for (int k = 0; k < 5; k++)
			{
				tmp.type[k] = dynamic_array[maxPosition].type[k];
				dynamic_array[maxPosition].type[k] = dynamic_array[i].type[k];
				dynamic_array[i].type[k] = tmp.type[k];
			}

			tmp.amount = dynamic_array[maxPosition].amount;
			tmp.supply_voltage = dynamic_array[maxPosition].supply_voltage;
			tmp.clock_frequency = dynamic_array[maxPosition].clock_frequency;
			dynamic_array[maxPosition].amount = dynamic_array[i].amount;
			dynamic_array[maxPosition].supply_voltage = dynamic_array[i].supply_voltage;
			dynamic_array[maxPosition].clock_frequency = dynamic_array[i].clock_frequency;
			dynamic_array[i].amount = tmp.amount;
			dynamic_array[i].supply_voltage = tmp.supply_voltage;
			dynamic_array[i].clock_frequency = tmp.clock_frequency;
		}
	}
	else if (point == 2)
	{
		for (int i = 0; i < *ptr_to_number_of_elements; i++)
		{
			minPosition = i;
			for (int j = i + 1; j < *ptr_to_number_of_elements; j++)
				if (dynamic_array[minPosition].amount > dynamic_array[j].amount)
					minPosition = j;

			for (int k = 0; k < 9; k++)
			{
				tmp.name[k] = dynamic_array[minPosition].name[k];
				dynamic_array[minPosition].name[k] = dynamic_array[i].name[k];
				dynamic_array[i].name[k] = tmp.name[k];
			}

			for (int k = 0; k < 5; k++)
			{
				tmp.type[k] = dynamic_array[minPosition].type[k];
				dynamic_array[minPosition].type[k] = dynamic_array[i].type[k];
				dynamic_array[i].type[k] = tmp.type[k];
			}

			tmp.amount = dynamic_array[minPosition].amount;
			tmp.supply_voltage = dynamic_array[minPosition].supply_voltage;
			tmp.clock_frequency = dynamic_array[minPosition].clock_frequency;
			dynamic_array[minPosition].amount = dynamic_array[i].amount;
			dynamic_array[minPosition].supply_voltage = dynamic_array[i].supply_voltage;
			dynamic_array[minPosition].clock_frequency = dynamic_array[i].clock_frequency;
			dynamic_array[i].amount = tmp.amount;
			dynamic_array[i].supply_voltage = tmp.supply_voltage;
			dynamic_array[i].clock_frequency = tmp.clock_frequency;
		}
	}



	return dynamic_array;
}
