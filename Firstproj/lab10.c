#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#define Pi 3,14



double fa(double x)
{
	double y;

	if (x <= 3)
		y = pow(x, 2) - 3 * x + 9;
	else
		y = 1 / (pow(x, 3) + 3);

	return y;
}

double fb(double x)
{
	double y;

	y = x * exp(sin(pow(x, 2)));

	return y;
}


void task1()
{
	double x;

	puts("Введите значение аргумента x");
	scanf("%lf", &x);

	printf("Произведение: %lf Разность квадратов: %lf Удвоенная сумма: %lf", fa(x) * fb(x), pow(fa(x), 2) - pow(fb(x), 2), 2 * (fa(x) + fb(x)));
}

double sin_n(double x, int N)
{
	float s = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 2 == 1)
			s += pow(x, 2 * i - 1) / factorial(2 * i - 1);
		else
			s -= pow(x, 2 * i - 1) / factorial(2 * i - 1);
	}
	return s;
}

long int factorial(long int n)
{
	if (n == 0 || n == 1) return 1;
	return n * factorial(n - 1);
}

double sin_eps(double x, double eps)
{
	float s = 0;
	int i = 1;
	while ((pow(x, 2 * i - 1) / factorial(2 * i - 1)) >= eps) {
		if (i % 2 == 1)
			s += pow(x, 2 * i - 1) / factorial(2 * i - 1);
		else
			s -= pow(x, 2 * i - 1) / factorial(2 * i - 1);
		i += 1;
	}
	return s;
}

double cos_eps(double x, double eps)
{
	float s = 0;
	int i = 0;
	while ((pow(x, 2 * i) / factorial(2 * i)) >= eps) {
		if (i == 0)
			s += 1;
		else if (i == 1)
			s -= pow(x, i + 1) / factorial(i + 1);
		else if (i % 2 == 1)
			s -= pow(x, 2 * i) / factorial(2 * i);
		else
			s += pow(x, 2 * i) / factorial(2 * i);
		i += 1;
	}
	return s;
}

void task2()
{
	double x, eps;
	int N;
	
	puts("Введите значения аргумента x, кол-ва элементов в степенном ряде и точность вычисления: ");
	scanf("%lf%d%lf", &x, &N, &eps);

	//для sin
	printf("%lf\n", sin(x));
	printf("%.3f\n", sin_n(x, N));
	printf("%.3f\n", sin_eps(x, eps));
	
	//для cos
	printf("%lf\n", cos(x));
	printf("%lf", cos_eps(x, eps));

}
float area_round(float a)
{
	return Pi * pow(a, 2);
}

float area_rectangle(float a, float b)
{
	return a * b;
}

float area_triangle(float a, float b, float c)
{
	float p = a + b + c;
	return pow((p * (p - a) * (p - b) * (p - c)), (float) 1 / 2);
}
void draw_rectangle()
{
	puts("__________");
	puts("|        |");
	puts("|        |");
	puts("|________|");
}

void draw_triangle()
{
	puts("     /\\ ");
	puts("    /  \\");
	puts("   /    \\");
	puts("  /      \\");
	puts(" /        \\");
	puts("/__________\\");



}

void draw_round()
{
	puts("  ------ ");
	puts("-        -");
	puts("-        -");
	puts("-        -");
	puts("  ------");
}
void name(int a)
{
	if (a == 1)
		puts("Вы ввели круг");
	else if (a == 2)
		puts("Вы ввели прямоугольник");
	else if (a == 3)
		puts("Вы ввели треугольник");

}

void task3()
{
	char fig, op;
	float a, b, c;
	int A, B;
	printf("1) Прямоугольник;\n2) Треугольник;\n3) Круг.\n");
	printf("1) рассчитать площадь;\n2) вывести определение фигуры;\n3) нарисовать фигуру.\n");
	puts("Введите цифру фигуры и цифру опции:");
	scanf("%c %c", &fig, &op);

	switch (fig)
	{
	case '1':
		if (op == '1') {
			puts("Введите стороны прямоугольника: ");
			scanf("%f%f", &a, &b);
			printf("Площадь прямоугольника равна %f", area_rectangle(a, b));
		}
		if (op == '2') {
			printf("Прямоугольник — четырёхугольник, у которого все углы прямые.");
			break;
		}
		if (op == '3') {
			draw_rectangle();
			break;
		}
	case '2':
		if (op == '1') {
			puts("Введите стороны треугольника: ");
			scanf("%f%f%f", &a, &b, &c);
			printf("Площадь треугольника равна %f", area_triangle(a, b, c));
			break;
		}
		if (op == '2') {
			printf("Треугольник - геометрическая фигура, образованная тремя отрезками, которые соединяют три точки, не лежащие на одной прямой.");
			break;
			}
		if (op == '3') {
			draw_triangle();
			break;
		}
	case '3':
		if (op == '1') {
			puts("Введите радиус круга: ");
			scanf("%f", a);
			printf("Площадь круга равна %f", area_round(a));
		}
		if (op == '2') {
			puts("Круг - это геометрическое место точек плоскости, расстояние от которых до заданной точки, называемой центром круга, не превышает заданного неотрицательного числа R.");
			break;
		}
		if (op == '3') {
			draw_round();
			break;
		}
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
