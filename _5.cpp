// Вариант 2
#include <iostream>
#include <bitset>
using namespace std;
#include <cmath>
#include <algorithm>


const int Number_maximum = 100000;

bool are_all_numbers_different(int n) 
{
    int m[Number_maximum] = {0};
    int i = 0;
    while (n > 0) 
    {
        m[i] = n % 10;
        n = n / 10;
        i = i + 1;
    }
    for (int j = 0; j < i; j = j + 1) 
    {
        for (int k = j + 1; k < i; k = k + 1) 
        {
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
    int number_of_elements;
    cout << "Введите количество элементвов" << endl;
    cin >> number_of_elements;
    
    for (int i = 0; i < number_of_elements; i = i + 1) {
            cin >> matrix[i];
    }
    
    for (int i = 0; i < number_of_elements; i = i + 1) {
        if (not are_all_numbers_different(matrix[i])) 
        {
            matrix[i] = 0;
        }
    }
    
    for (int i = 0; i < number_of_elements; i = i + 1) 
    {
        for (int j = i + 1; j < number_of_elements; j = j + 1) 
        {
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
    
    for (int i = 0; i < number_of_elements; i = i + 1) 
    {
        if (matrix[i] == 0) 
        {
            number_of_elements = i;
            break;
        }
    }
    
    int n_copy = number_of_elements;
    for (int i = 0; i < n_copy; i = i + 1) 
    {
        for (int j = i + 1; j < n_copy; j = j + 1)
        {
                if ((matrix[i] * matrix[j]) % 14 == 0) 
                {
                matrix[number_of_elements] = matrix[i];
                matrix[number_of_elements + 1] = matrix[j];
                number_of_elements += 2;
                } 
        }
    }
    
    for (int i = 0; i < number_of_elements; i = i + 1) 
    {
        cout << matrix[i] << " ";
    }
    return 0;
}
