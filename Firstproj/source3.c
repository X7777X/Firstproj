#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define D 2.54
#define SD 2.32
#define M 1.852


void main()
{
	setlocale(LC_ALL, "RUS");
	//Задание 1
	/*int num, num2;
	puts("Введите число:");
	scanf("%d", &num);
	printf("Введено число %d\n", num);
	puts("Введите второе число:");
	scanf("%d", &num2);
	printf("Введено число %d\n", num2);
	printf("Сумма двух чисел равна %d, разность двух чисел по модулю равна %d\, произведение двух чисел равно %d, частное двух чисел равно %d, остаток от деления второго числа на первое равен %d", num + num2, abs(num - num2), num * num2, num / num2, num2%num);*/
	//Задание 2
	/*int dym;
	float result1, result2;
	puts("Введите значения");
	scanf("%d", &dym);
	result1 = dym * D;
	result2 = dym * SD;
	printf("%d английских дюймов – это %.2f см\n%d испанских дюймов это %.2f см", dym, result1, dym, result2);*/
	//Задание 2А
	/*int mili;
	scanf("%d", &mili);
	printf("%d миль равно %.3f км", mili, mili * M);*/
	//Задание для самостоятельной работы
	/*int H, m;
	printf("Введите значения высоты и массы падающего тела\n");
	scanf("%d%d", &H, &m);
	printf("Работа силы тяжести(A = mgh) при падении тела массы %d с высоты %d равна %f", m, H, m * g * H);*/
	
}
