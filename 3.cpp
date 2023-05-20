#include<iostream>
#include<cmath>

#define EXP 2.71828182
using namespace std;

double fun(double x) {
	return sin(x) + 2 * pow(x, 2) - 5;
}
double fun1(double x) {
	return cos(x) + 4 * x;
}
double fun2(double x) {
	return -sin(x) + 4;
}

double DivSegmentHalf(double a, double b, double eps) {
	if (fun(a) * fun(b) >= 0) throw false;
	while (true) {
		double c = (a + b) / 2;
		double a_values = fun(a);
		double b_values = fun(b);
		double c_values = fun(c);
		if (fabs(c_values) < eps) return c;
		if (a_values * c_values < 0) b = c;
		else a = c;
	}
}

double DivHord(double a, double b, double eps) {
	if (fun(a) * fun(b) >= 0) throw false;
	double c = 0;
	while (fabs(fun(b) - fun(a)) > eps) {
		c = (fun(b) * a - fun(a) * b) / (fun(b) - fun(a));
		if ((fun(a) * fun(c)) > 0) a = c;
		else b = c;
	}
	return c;
}

double DivNuton(double a, double b, double eps) {
	if (fun(a) * fun(b) >= 0) throw false;
	int n = 0;
	double x = 0;
	if (fun(a) * fun1(a) < 0) x = a;
	else x = b;
	double counter = 0;
	counter = fabs(fun1(x));
	while (counter > eps)
	{
		x = x - (fun(x) / fun1(x));
		n += 1;
		counter--;
	}
	return x;
}

double DivSucApp(double a, double b, double eps) {
	if (fun(a) * fun(b) >= 0) throw false;
	double x = a;
	for (double iter = 1; eps < fabs(fun(x)); ++iter)
	{
		if (fun(x) * fun(fun1(x)) > 0) x = fun1(x);
		else break;
	}
	return x;
}

double DivHordKos(double a, double b, double eps) {
	if (fun(a) * fun(b) >= 0) throw false;
	do {
		if (fun(a) * fun2(a) < 0) a += (b - a) / (fun(a) - fun(b)) * fun(a);
		else a -= fun(a) / fun1(a);
		if (fun(b) * fun2(b) < 0) b += (a - b) / (fun(b) - fun(a)) * fun(b);
		else b -= fun(b) / fun1(b);
	} while (fabs(a - b) > 2 * eps);
	return (a + b) / 2.0;
}

double DivSek(double a, double b, double eps) {
	if (fun(a) * fun(b) >= 0) throw false;
	double res = 0, y = 0;
	do
	{
		y = res;
		res = b - ((b - a) / (fun(b) - fun(a))) * fun(b);
		a = b;
		b = res;
	} while (fabs(y - res) >= eps);
	return res;
}

int main() {
	setlocale(LC_ALL, "RUS");

	cout << "Task 1\n" << endl;

	bool flag = true;
	while (flag) {
		int button = 0;
		cout << "1. Метод деления отрезка пополам (дихотомии)" << endl;
		cout << "2. Метод хорд" << endl;
		cout << "3. Метод Ньютона (метод касательных)" << endl;
		cout << "4. Метод последовательных приближений (метод простых итераций)" << endl;
		cout << "5. Метод секущих" << endl;
		cout << "6. Комбинированный метод хорд и касательных" << endl;
		cout << "0. Выход" << endl;
		cout << "Выбор: ";
		cin >> button;
		cout << endl;

		double (*fcnPtr)(double, double, double) = nullptr;

		switch (button) {
		case 1: fcnPtr = DivSegmentHalf; break;
		case 2: fcnPtr = DivHord; break;
		case 3: fcnPtr = DivNuton; break;
		case 4: fcnPtr = DivSucApp; break;
		case 5: fcnPtr = DivSek; break;
		case 6: fcnPtr = DivHordKos; break;
		default: flag = false; break;
		}

		if (!flag) break;

		double a_1 = 0, b_1 = 0, err_1 = 0, y_1 = 0, h_1 = 0.1;
		cout << "Enter a: ";
		cin >> a_1;
		cout << "Enter b: ";
		cin >> b_1;
		cout << "Enter err: ";
		cin >> err_1;

		double min_1 = 0, max_1 = 0;

		if (a_1 < b_1) {
			min_1 = a_1;
			max_1 = b_1;
		}
		else {
			min_1 = b_1;
			max_1 = a_1;
		}

		cout << endl << "-------------------------------------" << endl;
		printf("| %15s | %15s |\n", "x", "f(x)");
		cout << "-------------------------------------" << endl;
		for (; min_1 < max_1; ) {
			min_1 += h_1;
			try
			{
				y_1 = fcnPtr(min_1, min_1 + h_1, err_1);
				printf("| %15e | %15e |\n", y_1, fun(y_1));
				cout << "-------------------------------------" << endl;
			}
			catch (bool flag)
			{
				if (!flag) continue;
			}
		}
		cout << endl;
	}
	return 0;
}
