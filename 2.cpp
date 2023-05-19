#include <iostream>
#include <math.h>
#include <iomanip>
#include <limits>

typedef std::numeric_limits< double > dbl;
using namespace std;


int factorial(int i)
{
	if (i == 0) return 1;
	else return i * factorial(i - 1);
}

double Func(double x, double eps, int* i) {

	double lastresult, result;

	lastresult = 0;

	do {
		result = lastresult;
		if((* i / 2) % 2 != 0)
			lastresult = -(pow(x, *i) / factorial(*i));
		else lastresult = (pow(x, *i) / factorial(*i));
		(*i)+=2;
	} while (fabs(lastresult - result) >= eps);

	return lastresult;
}





void Task1() {
	long double func1 = 0, func2 = 0;          
	double x = (-0.90), dx = 0.1, eps1 = 0.1, eps2 = 0.000001;
	int iter1 = 0, iter2 = 0;         

	cout << "|         X         |        f1        |      count1    |       eps1     |        f2        |       count2   |      eps2      |\n";
	while (x <= 0.9) {
		if (x < 0.1 && x >(-0.1)) x = 0;
		iter1 = 0;
		iter2 = 0;
		func1 = Func(x, eps1, &iter1);
		func2 = Func(x, eps2, &iter2);
		printf("| %18.1lf| %17.7lf| %15d| %14.1lf | %16.7e | %14d | %15.7lf|\n", x, func1, iter1/2, eps1, func2, iter2/2, eps2);

		x += dx;
	}
	system("pause");
}
void Task2() {
	double a, eps = 0.01;
	cout << "Введите значение a = ";
	cin >> a;
	a = pow(a, (double)1 / 3);
	double x = a / 3.0;
	int iteration = 0;
	while (fabs(x - a) < eps)
	{
		iteration++;
		cout << "x[" << iteration << "] = " << x << endl;
		x = (2.0 * (x + a / (2 * x * x))) / 3.0;
	}
}




void Task3() {
	int n;
	float res[100], min = 100000000;
	cout << "Введите значение n = ";
	cin >> n;
	for (int k = 1; k <= n; k++)
	{
		res[k] = pow(k, 3) * sin(n + k / n);
	}
	for (int k = 1; k <= n; k++)
	{
		if (res[k] < min)
		{
			min = res[k];
		}
	}
	cout << min << " - Наименьшее значение." << endl;
}



void Task4() {
	int n;
	cout << "Введите значение n = ";
	cin >> n;
	double sum = 0.0, ac = 1.0, bc = 1.0;
	while (n--)
	{
		sum += ac * bc;
		double anext = 0.5 * (sqrt(bc) + 0.5 * ac);
		double bnext = 2 * ac * ac + bc;
		ac = anext;
		bc = bnext;
	}
	cout << sum << endl;
}



void Task5() {
	double x1 = 1, x2 = 0, eps = 0, iteration = 2, n = 1, e = 2.7, func1 = 1, func2 = 0;
	cout << "Введите значение eps = ";
	cin >> eps;
	while (fabs(func1 - func2) > eps) {
		func2 = func1;
		func1 = (sin(x1)) / x1;
		x1 = 1 / iteration;
		iteration = iteration * 2;
		cout << x1 << endl;
	}
	cout << "Введите значение eps = ";
	cin >> eps;
	double a = pow((1 + (1 / n)), n);
	while (fabs(a - e) > eps) {
		n++;
		a = pow((1 + (1 / n)), n);
		cout << "n = " << n << " e = " << a << endl;
	}
}
int main() {

	int cycle = 1, button = 0;

	system("chcp 1251");

	while (cycle) {
		system("cls");

		cout << "Лабораторная работа №1"s << endl;
		cout << "Выполнил: Зубков Н.Р"s << endl;
		cout << "Вариант 8"s << endl << endl;

		cout << "Выберите задание (1-5)"s << endl << endl;

		cin >> button;

		switch (button) {
		case 1:
			Task1();
			system("pause");
			break;
		case 2:
			Task2();
			system("pause");
			break;

		case 3:
			Task3();
			system("pause");
			system("pause");
			break;
		case 4:
			Task4();
			system("pause");
		case 5:
			Task5();
			system("pause");
		default:
			cycle = 0;
			system("pause");
			break;

		}
	}
	return 0;

}
