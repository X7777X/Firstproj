#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void task1()
{
	char name[10];
	char snew[41] = "HELLO, ";

	printf("Введите ваше имя:");
	gets(name);
	strcat(snew, name);
	printf("%s", snew);

	for (int i = 0; i < 40; i++) { //Заполнение ! через цикл до 40
		if (strlen(snew) < 40) {
			printf("!");
			strcat(snew, "!");
		}
		else 
			break;
	}
}
void task2()
{
	char name[10];
	char snew[41] = "HELLO, ";
	char pere;

	printf("Введите ваше имя:");
	gets(name);
	pere = name[0];
	name[0] = name[1];
	name[1] = pere;

	strcat(snew, name);
	printf("%s", snew);
}
void task3()
{
	char S[100];
	int k = 0, k1 = 0;

	fgets(S, 101, stdin);
	puts(S);
	for (int i = 0; i < strlen(S); i++) {
		if (S[i] == ' ') {
			if (k1 <= 3) {
				k += 1;
				k1 = 0;
			}
			k1 = 0;
		}
		else {
			k1 += 1;
		}
	}
	printf("Кол-во слов, длина которых не превышает 3, равно %d", k);
}
int main()
{

	setlocale(LC_ALL, "RUS");
	task1();
	//task2();
	//task3();

	return 0;
}
