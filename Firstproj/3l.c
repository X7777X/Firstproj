#include <iostream>
#include <windows.h>
using namespace std;

double ** spiral_matrix(double** matrix, int n) {
	


	int row = 0, col = 0; // начальные значения для строки и столбца
	string direction = "right"; // начальное направление движения

	// заполнение матрицы
	for (int i = 1; i <= n * n; i++) {
		matrix[row][col] = i; // присваивание значения текущему элементу матрицы

		// изменение значения строки и столбца в зависимости от направления движения
		if (direction == "right") {
			if (col == n - 1 || matrix[row][col + 1] != 0) {
				direction = "down";
				row++;
			}
			else {
				col++;
			}
		}
		else if (direction == "down") {
			if (row == n - 1 || matrix[row + 1][col] != 0) {
				direction = "left";
				col--;
			}
			else {
				row++;
			}
		}
		else if (direction == "left") {
			if (col == 0 || matrix[row][col - 1] != 0) {
				direction = "up";
				row--;
			}
			else {
				col--;
			}
		}
		else if (direction == "up") {
			if (row == 0 || matrix[row - 1][col] != 0) {
				direction = "right";
				col++;
			}
			else {
				row--;
			}
		}
	}

	return matrix;
}
void output(double** matrix, int n)
{
	// вывод матрицы на экран
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout.width(10);
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
}

double ** inverseMatrix(double ** matrix, int n) {
	double** inv = new double* [n];
	for (int i = 0; i < n; i++) {
		inv[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			inv[i][j] = 0;
		}
	}

	// заполнение диагонали единицами
	for (int i = 0; i < n; i++) {
		inv[i][i] = 1;
	}

	// применение метода Гаусса-Жордана
	for (int i = 0; i < n; i++) {
		double temp = matrix[i][i];
		for (int j = 0; j < n; j++) {
			matrix[i][j] /= temp;
			inv[i][j] /= temp;
		}
		for (int j = 0; j < n; j++) {
			if (j != i) {
				double temp = matrix[j][i];
				for (int k = 0; k < n; k++) {
					matrix[j][k] -= matrix[i][k] * temp;
					inv[j][k] -= inv[i][k] * temp;
				}
			}
		}
	}

	// печать результата
	cout << "Inverse matrix:" << endl;
	output(inv, n);
	return inv;
}
double** matrix_multiplication(double ** matrix, double **inv, int n)
{
	double** e = new double* [n];
	for (int i = 0; i < n; i++) {
		e[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			e[i][j] = 0;
			for (int k = 0; k < n; k++) {
				e[i][j] += matrix[i][k] * inv[k][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			e[i][j] = 0;
			for (int k = 0; k < n; k++) {
				e[i][j] += matrix[i][k] * inv[k][j];
			}
		}
	}
	output(e, n);
	return e;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "Введите размер квадратной матрицы: ";
	cin >> n;
	double** matrix = new double* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
		}
	}

	spiral_matrix(matrix, n);
	output(matrix, n);
	cout << endl;
	inverseMatrix(matrix, n);
	matrix_multiplication(matrix, inverseMatrix(matrix, n), n);
	return 2;
}
