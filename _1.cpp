// Вариант 2
#include <iostream>
#include <bitset>
using namespace std;
#include <cmath>
#include <algorithm>


bool is_last_digit_less(int n1, int n2) {
    if ((n1 % 10) < (n2 % 10))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main() {    
    const int Number_maximum = 10000;
    int array[Number_maximum]  {2, 999, 99, 0, 8, 11, 13, 12, 14};
    int M[Number_maximum];
    copy(begin(array), end(array), begin(M));

    bool flag = false;
    int number = 10;
    
    for (int i = 0; i < Number_maximum; i = i + 1) 
    {
        for (int j = i; j < Number_maximum; j = j + 1) 
        {
            if (not flag) 
            {
                if (i == 0 & array[i] == array[j] & i != j) 
                {
                    flag = true;
                }
            }
            if (is_last_digit_less(array[i], array[j])) 
            {
                swap(array[i], array[j]);
            }
        }
        if (not flag) 
        {
            break;
        }
    }
    
    if (flag) {
        for (int i = 0; i < number; i = i + 1) 
        {
            cout << array[i] << " ";
        }
    }
    else {
        for (int i = 0; i < number; i = i + 1) 
        {
            cout << M[i] << " ";
        }
    }
    
    return 0;
}
