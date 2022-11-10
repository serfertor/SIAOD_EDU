#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <cstdio>
#include <fstream>

using namespace std;


struct node {
    node* next[26];     //Массив указателей на следующие вершины
                        //next[i] - указатель на следующую вершину, соответствующую символу ('a' + i)
                        //(предполагается, что используются только строчные латинские буквы)
    int strings;        //Количество строк, заканчивающихся в этой вершине.
    node() {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        strings = 0;
    }
};

node* root = new node();

void lin_poisk(string key, string arr) {
    int cf=0;
    auto start_time = chrono::steady_clock::now();
    bool q = false;
    for (int i = 0; i < arr.length(); i++) {
        cf++;
        if (arr[i] == key[0]) {
            if (key.length() == 1){
                auto end_time = chrono::steady_clock::now();
                auto time_spent = chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
                cout << "cf = " << cf << "  time = " << time_spent.count() << endl;
                cout << "Номер первого вхождения в строку:  " << i  << endl;
                return;
            }
            for (int j = 0; j < key.length(); j++) {
                cf++;
                if (key[j] == arr[i + j]) {
                    q = true;
                } else {
                    q = false;
                    break;
                }
            }
            if (q){
                auto end_time = chrono::steady_clock::now();
                auto time_spent = chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
                cout << "cf = " << cf << "  time = " << time_spent.count() << endl;
                cout << "Номер первого вхождения в строку:  " << i  << endl;
                return;
            }
        }
    }
    auto end_time = chrono::steady_clock::now();
    auto time_spent = chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    cout << "cf = " << cf << "  time = " << time_spent.count() << endl;
    cout << "Элемент не найден" << endl;
}




void mas_char(string str, int size, int chat[256]) {
    int i;
    for (i = 0; i < 256; i++)
        chat[i] = -1;
    for (i = 0; i < size; i++)
        chat[(int)str[i]] = i;
}

void search(string txt, string pat) {
    int k = 0;
    int m = pat.size();
    int n = txt.size();
    int chat[256];
    int cf = 0;
    int mf = 0;
    mas_char(pat, m, chat);
    int s = 0;
    auto start_time = chrono::steady_clock::now();
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j])
            j--;
            cf++;
        if (j < 0) {
            auto end_time = chrono::steady_clock::now();
            auto time_spent = chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
            cout << "cf = " << cf << "mf = " << mf << "  time = " << time_spent.count() << endl;
            cout << "Номер первого вхождения в строку:  " << s << endl;
            s += (s + m < n) ? m - chat[txt[s + m]] : 1;
            return;
        } else {
            mf++;
            s += max(1, j - chat[txt[s + j]]);
        }
    }
    auto end_time = chrono::steady_clock::now();
    auto time_spent = chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    cout << "cf = " << cf << "mf = " << mf << "  time = " << time_spent.count() << endl;
    cout << "Элемент не найден" << endl;
}

void add(const string& s) {
    node* cur_v = root;     
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (cur_v->next[c - 'a'] == nullptr) {
            cur_v->next[c - 'a'] = new node();
        }
        cur_v = cur_v->next[c - 'a'];
    }
    cur_v->strings++;
}

bool has(const string& s) {
    int cf = 0;
    int mf = 0;
    auto start_time = chrono::steady_clock::now();
    node* cur_v = root;
    for (int i = 0; i < s.length(); i++) {
        cur_v = cur_v->next[s[i] - 'a'];
        cf++;
        if (cur_v == nullptr) {
            add(s);
            cout << "Слово не найдено, но добавлено" << endl;
            auto end_time = chrono::steady_clock::now();
            auto time_spent = chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
            cout << "cf = " << cf << "mf = " << mf << "  time = " << time_spent.count() << endl;
            return false;
        }
        mf++;
    }
    auto end_time = chrono::steady_clock::now();
    auto time_spent = chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    cout << "cf = " << cf << "mf = " << mf << "  time = " << time_spent.count() << endl;
    return cur_v->strings > 0;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    int q, n;
    string s, key;
    while (cin >> s) {
        if (has(s)) {
            cout << "Слово найдено" << endl;
        }
    }
    return (0);
}
