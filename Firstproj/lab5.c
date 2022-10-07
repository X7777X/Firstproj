#include <stdio.h>
#include <locale.h>
#include <math.h>
#define _USE_MATH_DEFINES 
#define M_PI 3.14159265358979323846

void task1()
{
	float gr;

	puts("Введите значения угла в градусах");
	scanf("%f", &gr);

	//перевод в радианы
	gr = gr * M_PI / 180;

	printf("%f", sin(gr));

}

void task2()
{
	//Вариант 3
	double x, a, b, p, y;
	p = 0.5;

	puts("Введите значения параметра x: ");
	scanf("%lf", &x);

	a = log(pow(p, 2) + pow(x, 3));
	b = exp(pow(fabs(x), 1/2.f));
	y = pow(a, 3) / pow(b, 2);

	printf("Значение функции Y при параметре X = %f равно %.4lf", x, y);

}

void task3()
{
	double x, a, b, p, y;
	int A, B, C;
	p = 0.5;

	puts("Введите значения параметра x: ");
	scanf("%lf", &x);

	a = log(pow(p, 2) + pow(x, 3));
	b = exp(pow(fabs(x), 1 / 2.f));
	y = pow(a, 3) / pow(b, 2);
	A = (int)a;
	B = (int)b;
	C = (int)y;
	printf("%d%d%d\n", A, B, C);

	if ((A % 2 == 0 && B % 2 != 0) || (A % 2 != 0 && B % 2 == 0)) {
		puts("3А) 1");
		printf("Если одно число четное, а другое - нечетное, тогда их сумма нечетна. Проверка:%d(A) + %d(B) = %d(A + B)\n", A, B, A + B);
	}
	else
		puts("3А) 0");
	if (A % 3 == 0 && B % 3 == 0 && C % 3 == 0)
		printf("3Б) 1");
	else
		printf("3Б) 0");
}

void DZ()
{
	float x, y, z, v;

	x = 3.74 * pow(10, -2);
	y = -0.825;
	z = 0.16 * pow(10, 2);
	
	 
	v = ((1 + pow(sin(x + y), 2)) / fabs(x - (2 * y / 1 + pow(x, 2) * pow(y, 2))) * pow(x, fabs(y)) + pow(cos(atan(1 / z)), 2));
	printf("%.4f", v);



}

int main()
{
	setlocale(LC_ALL, "RUS");
	task1();
	//task2();
	//task3();
	//DZ();


	return 0;
}
