#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int n = 3;
vector<vector<double>> matrix(n, vector<double>(n));
vector<double> b(n), x(n);


// Function to get cofactor of A[p][q] in temp[][]
void getCofactor(vector<vector<double>>& A, vector<vector<double>>& temp, int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = A[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}


// Recursive function for finding determinant
double determinant(vector<vector<double>>& A, int N) {
    double D = 0;
    if (N == 1)
        return A[0][0];

    vector<vector<double>> temp(N, vector<double>(N));
    int sign = 1;

    for (int i = 0; i < N; i++) {
        getCofactor(A, temp, 0, i, N);
        D += sign * A[0][i] * determinant(temp, N - 1);
        sign = -sign;
    }

    return D;
}

// Function to get adjoint of A[N][N] in adj[N][N]
void adjoint(vector<vector<double>>& A, vector<vector<double>>& adj) {
    int N = A.size();
    if (N == 1) {
        adj[0][0] = 1;
        return;
    }

    int sign = 1;
    vector<vector<double>> temp(N, vector<double>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            getCofactor(A, temp, i, j, N);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, N - 1));
        }
    }
}




// Function to calculate and store inverse
vector<vector<double>> inverse(vector<vector<double>>& A)
{
    int N = A.size();
    double det = determinant(A, N);
    if (det == 0) {
        cout << "Singular matrix, can't find its inverse";
        return {};
    }

    vector<vector<double>> adj(N, vector<double>(N));
    vector<vector<double>> inv(N, vector<double>(N));

    // Find adjoint
    adjoint(A, adj);

    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            inv[i][j] = adj[i][j] / float(det);

    return inv;
}

void gauss() {
    // прямой ход
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double r = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++)
                matrix[j][k] -= matrix[i][k] * r;
            b[j] -= b[i] * r;
        }
    }

    // обратный ход
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++)
            b[i] -= matrix[i][j] * x[j];
        x[i] = b[i] / matrix[i][i];
    }
}


int main() {
    matrix = { {3.7, -2.3, 4.5},
              {2.5, 4.7, -7.8},
              {1.6, 5.3, 1.3} };
    b = { 2.4, 3.5, -2.4 };

   /* gauss();

    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }*/


    //vector<vector<double>> inv = inverse(matrix);

    //for (int i = 0; i < n; i++) {
    //    x[i] = 0;
    //    for (int j = 0; j < n; j++) {
    //        x[i] += inv[i][j] * b[j];
    //    }
    //}

    //for (int i = 0; i < n; i++) {
    //    cout << "x" << i + 1 << " = " << x[i] << endl;
    //}

    return 0;
}
