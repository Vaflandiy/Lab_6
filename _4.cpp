// Вариант 2
#include <iostream>
#include <bitset>
using namespace std;
#include <cmath>
#include <algorithm>


int main()
{
    const int Number_Maximum = 100;
    int matrix[Number_Maximum][Number_Maximum];
    int n, m;
    cout << "Введите строки и столбцы для матрицы" << endl;
    cin >> n >> m;
    
    for (int i = 0; i < n; i = i + 1) {
        for (int j = 0; j < m; j = j + 1) {
            cin >> matrix[i][j];
        }
    }
    
    matrix[0][0] = matrix[1][2] = matrix[2][3] = matrix[3][1] = 0;
    
    matrix[0][1] = matrix[1][0] = matrix[1][1];
    
    for (int i = 0; i < n; i = i + 1) {
        for (int j = 0; j < m; j = j + 1) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
