#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

void task0()
{
	int k;
	char c, c1;

	puts("Введите кол-во символов и их вид: ");
	scanf("%d%c%c", &k, &c, &c1);

	//putchar('+');
	for (int start = 1; start <= k; start++)
		if (start <= (k / 2)) {
			printf("%c", c);
			putchar('!');
		}
		else {
			printf("%c", c1);
			putchar('!');
		}
}

void task1()
{
	int n, m;

	puts("Введите значения ограничений повторений: ");
	scanf("%d%d", &n, &m);
	printf("%d %d\n", n, m);

	for (int i = m, s = 0; i >= n; i--) {
		s += i;
		printf("выполнено %d раз\n", i);
		if (i == n)
			printf("%d", s);
	} 
}

void task2()
{
	float t;

	puts("Табулирование функции y = 1.8x^2 - sin10x на [0.2;2.2]. Введите шаг табуляции: ");
	scanf("%f", &t);

	for (float i = 0.2; i <= 2.2; i += t) {
		puts("________________________");
		printf("%f   |   %f\n", i, 1.8 * pow(i, 2) - sin(10 * i));
	}
}

void indiv3dz() //3 вариант
{
	int n;
	float a;
	float p, s = 0;
	puts("Введите значение n(кол-во дробей) и значение a: ");
	scanf("%d %f", &n, &a);

	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			s += 1 / a;
			p = 1 / a;
		}
		else {
			s += p * 1 / (a + i);
			p = p * 1 / (a + i);

		}
			
	}
	printf("%f", s);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	task0();
	//task1();
	//task2();
	//indiv3dz();

	return 0;
}
