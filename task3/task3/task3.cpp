#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;


const int N = 100;
int qq = 0;



void input_arr(int n, vector <int> &arr) {
    int num;
    cout << "Введите элементы массива" << endl;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[i] = num;
    }
}

void input_rand(vector <int> &arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = 1 + rand();
    }
}

void output_arr(vector <int> arr) {
    for (int item : arr)
    {
        cout << item << " ";
    }
    cout << endl;
}



bool del(int a) {
    int summ = 0;
    for (int i = 1; i <= a; i++) {
        int qs = a % i;
        if (qs == 0) {
            summ += 1;
        }
    }
    if (summ > 3) {
        return true;
    }
    else {
        return false;
    }
}

bool simpl(int a) {
    if (a == 0 or a == 1 or a == 4) {
        return false;
    }
    else {
        for (int i = 2; i < a / 2; i++) {
            if (a % i == 0) {
                return false;
            }
        }
    }
    return true;
}



void sortin(vector <int> &arr) {
    sort(arr.begin(), arr.end());
}

void fun_arr(vector <int> &arr, vector <int> &new_arr) {
    sortin(arr);
    for (int i = 0; i < arr.size(); i++) {
        if (simpl(arr[i])) {
            new_arr.push_back(arr[i]);
        }
    }
}

void remov(vector <int> &arr) {
    arr.erase(arr.begin());
}

void countf(vector <int> arr, int n) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (del(arr[i])) {
            sum += 1;
            cout << arr[i] << " " << endl;
        }
    }
    cout << "Количество чисел имеющих более трех делителей: " << sum << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");   
    int n, k;
    bool answer = true;
    srand(time(NULL));
    while (answer) {
        cout << "Группа ИНБО-06-21 студент Шерри Г.Д. вариант 28" << endl;
        cout << "Как заполнить массив:вручную или случайными числами?" << endl;
        cout << "1) Заполнить вручную " << endl;
        cout << "2) Заполнить случайными цифрами" << endl;
        cin >> k;
        cout << "Введите размер массива" << endl;
        cin >> n;
        vector <int> arr(n);
        vector <int> new_arr;
        switch (k) {
        case 1:
            input_arr(n, arr);
            break;

        case 2:
            input_rand(arr, n);
            break;

        default:
            cout << "Некорректное значение ";
            system("pause");
            break;
        }
        cout << endl;
        k = 0;
        cout << "Что нужно выполнить с массивом?" << endl;
        cout << "1) Сформировать новый массив из простых чисел исходного массива так, чтобы числа образовали в результате возрастающую последовательность." << endl;
        cout << "2) Удалить минимальное число нового массива" << endl;
        cout << "3) Определить у скольких чисел исходных исходного массива кол-во делителей больше трех" << endl;
        cin >> k;
        switch (k) {

        case 1:
            cout << "Массив:" << endl;
            output_arr(arr);
            cout << endl;
            fun_arr(arr, new_arr);
            cout << "Новый массив:" << endl;
            output_arr(new_arr);
            break;

        case 2:
            cout << "Массив:" << endl;
            output_arr(arr);
            cout << endl;
            fun_arr(arr, new_arr);
            remov(new_arr);
            cout << "Новый массив:" << endl;
            output_arr(new_arr);
            break;

        case 3:
            cout << "Массив:" << endl;
            output_arr(arr);
            cout << endl;
            countf(arr, n);
            break;

        default:
            cout << "Некорректный ввод данных " << endl;
            system("pause");
            break;
        }
        qq = 0;
        arr.clear();
        new_arr.clear();
    }
    return 0;
}
