#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

struct nalog {
    long long int inn;
    string surname = "-";
    string phone = "-";
    bool operator<(const nalog& a) const
    {
        return inn < a.inn;
    }
};

vector <nalog> arr;

long Random(int min, int max) {
    return min + rand() % (max - min);
}

void sorts() {
    sort(arr.begin(), arr.end());
}

bool proverka(long long int inn) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].inn == inn) {
            return true;
        }
    }
    return false;
}

void vvod() {
    int n, inn;
    string sur, ph;
    cout << "Введите размер массива" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Введите инн, фамилию и номер телефона" << endl;
        cin >> inn >> sur >> ph;
        nalog h = { inn, sur, ph };
        arr.push_back(h);
    }
}

void vvod_random() {
    int n;
    long long int inn;
    srand(time(NULL));
    cout << "Введите размер массива" << endl;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        inn = Random(10000,99999)*10000 + Random(10000,99999);
        while (proverka(inn)) {
            inn = Random(10000, 99999) * 10000 + Random(10000, 99999);
        }
        nalog h = { inn, "Калачинова", "+135352048"};
        arr.push_back(h);
        inn = 0;
    }
}

void lin_poisk(long long int key) {
    long long int cf = 0;
    auto start_time = chrono::steady_clock::now();
    int i = 0;
    while (i < arr.size()-1 and arr[i].inn != key) {
        cf++;
        i++;
    }
    auto end_time = chrono::steady_clock::now();
    auto time_spent = chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    if (i == arr.size()-1) {
        cout << "Элемент не найден" << endl;
    }
    else {
        cout<< arr[i].inn << " "<< arr[i].phone << " " << arr[i].surname << endl;
        cout << "cf = " << cf << "  time = " << time_spent.count() << endl;
    }
}

void lin_poisk_extra(long long int key) {
    long long int cf = 0;
    auto start_time = chrono::steady_clock::now();
    nalog t = { key, "-", "-" };
    arr.push_back(t);
    int i = 0;
    while (arr[i].inn != key) {
        cf++;
        i++;
    }
    auto end_time = chrono::steady_clock::now();
    auto time_spent = chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    if (i == arr.size()-1) {
        cout << "Элемент не найден" << endl;
    }
    else {
        cout << arr[i].inn << " " << arr[i].phone << " " << arr[i].surname << endl;
        cout << "cf = " << cf << "  time = " << time_spent.count() << endl;
    }
}

void interpol_find(long long int key) {
    sorts();
    long long int cf = 0;
    auto start_time = chrono::steady_clock::now();
    long int mid, left = 0, right = arr.size() - 1;
    while (arr[left].inn <= key && arr[right].inn >= key)
    {
        cf++;
        mid = left + ((key - arr[left].inn) * (right - left)) / (arr[right].inn - arr[left].inn);
        if (arr[mid].inn < key) { 
            left = mid + 1; 
        }
        else if (arr[mid].inn > key) { 
            right = mid - 1; 
        }
        else {
            auto end_time = chrono::steady_clock::now();
            auto time_spent = chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
            cout << arr[mid].inn << " " << arr[mid].phone << " " << arr[mid].surname << endl;
            cout << "cf = " << cf << "  time = " << time_spent.count() << endl;
            break; 
        }
    }
    if (arr[left].inn == key) {
        auto end_time = chrono::steady_clock::now();
        auto time_spent = chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
        cout << arr[left].inn << " " << arr[left].phone << " " << arr[left].surname << endl;
        cout << "cf = " << cf << "  time = " << time_spent.count() << endl;
    }
    else {
        cout << "Элемент не найден" << endl;
    }
}


int main()
{   
    setlocale(LC_ALL, "Rus");
    int q,l = 0;
    nalog s;
    cout << sizeof(s) << endl;
    while (true) {
        cout <<"Какой алгоритм использовать 1 - линейный 2 - линейный с барьером 3 - интерполяционный 4 - все" << endl;
        cin >> q;
        switch (q) {
        case 1:
            cout <<"Как ввести массив 1- вручную 2 - рандомом" << endl;
            cin >> l;
            if (l == 1) {
                vvod();
                cout << "Примерный ключ: " << arr[arr.size()/3 * 2].inn << endl;
                cout << "Введите ключ" << endl;
                long long int key;
                cin >> key;
                lin_poisk(key);
            }
            else {
                vvod_random();
                cout << "Примерный ключ: " << arr[arr.size() / 3 * 2].inn << endl;
                cout << "Введите ключ" << endl;
                long long int key;
                cin >> key;
                lin_poisk(key);
            }
            break;
        case 2:
            cout << "Как ввести массив 1- вручную 2 - рандомом" << endl;
            cin >> l;
            if (l == 1) {
                vvod();
                cout << "Примерный ключ: " << arr[arr.size() / 3 * 2].inn << endl;
                cout << "Введите ключ" << endl;
                long long int key;
                cin >> key;
                lin_poisk_extra(key);
            }
            else {
                vvod_random();
                cout << "Примерный ключ: " << arr[arr.size() / 3 * 2].inn << endl;
                cout << "Введите ключ" << endl;
                long long int key;
                cin >> key;
                lin_poisk_extra(key);
            }
            break;
        case 3:
            cout << "Как ввести массив 1- вручную 2 - рандомом" << endl;
            cin >> l;
            if (l == 1) {
                vvod();
                cout << "Примерный ключ: " << arr[arr.size() / 3 * 2].inn << endl;
                cout << "Введите ключ" << endl;
                long long int key;
                cin >> key;
                interpol_find(key);
            }
            else {
                vvod_random();
                cout << "Примерный ключ: " << arr[arr.size() / 3 * 2].inn << endl;
                cout << "Введите ключ" << endl;
                long long int key;
                cin >> key;
                interpol_find(key);
            }
            break;
        case 4:
            cout << "Как ввести массив 1- вручную 2 - рандомом" << endl;
            cin >> l;
            if (l == 1) {
                vvod();
                cout << "Примерный ключ: " << arr[arr.size() / 3 * 2].inn << endl;
                cout << "Введите ключ" << endl;
                long long int key;
                cin >> key;
                cout << "Линейный  ";
                lin_poisk(key);
                cout << "Линейный с барьером";
                lin_poisk_extra(key);
                cout << "Интерполяционной";
                interpol_find(key);
            }
            else {
                vvod_random();
                cout << "Примерный ключ: " << arr[arr.size() / 3 * 2].inn << endl;
                cout << "Введите ключ" << endl;
                long long int key;
                cin >> key;
                cout << "Линейный  ";
                lin_poisk(key);
                cout << "Линейный с барьером   ";
                lin_poisk_extra(key);
                cout << "Интерполяционной    ";
                interpol_find(key);
            }
            break;
        }
        arr.clear();
    }
}