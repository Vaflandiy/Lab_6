// Вариант 2
#include <iostream>
#include <bitset>
using namespace std;
#include <cmath>
#include <algorithm>


int find_first_digit_of_number(int number) {
    while (number > 9) {
        number = number / 10;
    }
    return number;
}

int get_digit_multiplication(int number) {
    int m = 1;
    while (number > 0) {
        m = m * (number % 10);
        number = number / 10;
    }
    return m;
}

bool what_to_sort(int mi, int mj, int first_digit_i, int first_digit_j, int digits_multiplication_i, int digits_multiplication_j) 
{
                    if ((first_digit_j == first_digit_j) && (digits_multiplication_j == digits_multiplication_i) && (mj < mi)) 
                    {
                        return true;
                    }
                    if ((first_digit_j == first_digit_i) && (digits_multiplication_j < digits_multiplication_i)) 
                    {
                        return true;
                    }
                    if (first_digit_j < first_digit_i) 
                    {
                        return true;
                    }
                    return false; // Ну, если нечего сортировать...
}


int main() {
     
    const int Number_Maximum = 10000;
    int first_digits[Number_Maximum];
    int digits_multiplication[Number_Maximum];
    
    int m[Number_Maximum] = {11, 12, 21, 22, 123, 132};
    int number = 8;
    for (int i = 0; i < number; i = i + 1) {
        cin >> m[i];
    }
    
    for (int i = 0; i < number; i = i + 1) {
        first_digits[i] = find_first_digit_of_number(m[i]);
        digits_multiplication[i] = get_digit_multiplication(m[i]);
    }
    
    for (int i = 0; i < number; i = i + 1) {
        for (int j = i + 1; j < number; j = j + 1) {
            if (what_to_sort(m[i], m[j], first_digits[i], first_digits[j], digits_multiplication[i], digits_multiplication[j])) {
                swap(m[i], m[j]);
                swap(first_digits[i], first_digits[j]);
                swap(digits_multiplication[i], digits_multiplication[j]);
            }
        }
    }
    for (int i = 0; i < number; i = i + 1) {
        cout << m[i] << " " << first_digits[i] << " " << digits_multiplication[i] << endl;
    }
    
    return 0;
}
