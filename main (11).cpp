// Вариант 2
#include <iostream>
#include <bitset>
using namespace std;
#include <cmath>
#include <algorithm>


const int Number_maximum = 100000;

bool is_all_digits_differ(int n) {
    int m[Number_maximum] = {0};
    int i = 0;
    while (n > 0) {
        m[i] = n % 10;
        n = n / 10;
        i = i + 1;
    }
    for (int j = 0; j < i; j = j + 1) {
        for (int k = j + 1; k < i; k = k + 1) {
            if (m[j] == m[k]) 
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int matrix[Number_maximum] = {0};
    int n;
    cout << "Введите количество элементво - n" << endl;
    cin >> n;
    
    for (int i = 0; i < n; i = i + 1) {
            cin >> matrix[i];
    }
    
    for (int i = 0; i < n; i = i + 1) {
        if (not is_all_digits_differ(matrix[i])) 
        {
            matrix[i] = 0;
        }
    }
    
    for (int i = 0; i < n; i = i + 1) {
        for (int j = i + 1; j < n; j = j + 1) {
            if (matrix[i] != 0 & matrix[j] != 0) 
            {
                break;
            }
            if (matrix[i] == 0 & matrix[j] != 0) 
            {
                matrix[i] = matrix[j];
                matrix[j] = 0;
            }
        }
    }
    
    for (int i = 0; i < n; i = i + 1) {
        if (matrix[i] == 0) 
        {
            n = i;
            break;
        }
    }
    
    int n_copy = n;
    for (int i = 0; i < n_copy; i = i + 1) 
    {
        for (int j = i + 1; j < n_copy; j = j + 1)
        {
                if ((matrix[i] * matrix[j]) % 14 == 0) 
                {
                matrix[n] = matrix[i];
                matrix[n + 1] = matrix[j];
                n += 2;
                } 
        }
    }
    
    for (int i = 0; i < n; i = i + 1) 
    {
            cout << matrix[i] << " ";
    }
    return 0;
}