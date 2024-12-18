// Вариант 2
#include <iostream>
#include <bitset>
using namespace std;
#include <cmath>
#include <algorithm>


int main()
{
    const int Number_Maximum = 100;
    int min_sum, index;
    min_sum = index = 1000000;
    int sum_for_columns[Number_Maximum] = {0};
    int matrix[Number_Maximum][Number_Maximum];
    int n, m;
    cout << "Введите размер матрицы n(строки) x m(столбцы)" << endl; 
    cin >> n >> m;
    
    for (int i = 0; i < n; i = i + 1) 
    {
        for (int j = 0; j < m; j = j + 1) 
        {
            cin >> matrix[i][j];
        }
    }
    
    for (int i = 0; i < n; i = i + 1) 
    {
        for (int j = 0; j < m; j = j + 1) 
        {
            sum_for_columns[j] = sum_for_columns[j] + matrix[i][j];
        }
    }
    
    for (int i = 0; i < m; i = i + 1) 
    {
        if (sum_for_columns[i] < min_sum) 
        {
            min_sum = sum_for_columns[i];
            index = i;
        };
    }
    
    for (int i = 0; i < n; i = i + 1) 
    {
        matrix[i][index] = matrix[i][index] + 3;
    }

    for (int i = 0; i < n; i = i + 1) 
    {
        for (int j = 0; j < m; j = j + 1) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
