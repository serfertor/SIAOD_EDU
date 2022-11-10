#ifndef SIAOD_H
#define SIAOD_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct car {
    char number[9];
    char model[11];
    char colour[11];
    char man[30];
    char data[11];
};

/*a199aa97
mersedes
black
Gena Bukin Alexandrovich
14.02.2003
g567fg89
bmw
black
Anna Rasputina Markovna
31.02.2004*/

int createBinFile(string filename) {
    ifstream itf(filename);
    if (!itf) {
        return 1;
    }
    string newFile;
    cout << "Enter the name of new binary file" << endl;
    cin >> newFile;
    ofstream obf(newFile, ios::binary | ios::out);
    car b;
   while (!itf.eof()) {
        itf.getline(b.number, 9);
        itf.getline(b.model, 11);
        itf.getline(b.colour, 11);
        itf.getline(b.man, 30);
        itf.getline(b.data, 11);
        obf.write((char*)&b, sizeof(car));
    }
    itf.close();
    obf.close();
    itf.clear();
    obf.clear();
    if (!itf.good() and !obf.good()) {
        return 1;
    }
    else {
        return 0;
    }
}

int outBinFile(string filename) {
    ifstream obf(filename, ios::binary | ios::in);
    if (!obf) {
        return 1;
    }
    car b;
    int len = sizeof(car);
    obf.read((char*)&b, len);
    while (!obf.eof()) {
        cout << b.number << endl << b.model << endl << b.colour << endl << b.man << endl << b.data << endl;
        obf.read((char*)&b, len);
    } 
    obf.close();
    obf.clear();
    if (!obf.good()) {
        return 1;
    }
    else {
        return 0;
    }
}

int BinToTxt(string filename) {
    ifstream itf(filename, ios :: binary | ios::in);
    if (!itf) {
        return 1;
    }
    string newFile;
    cout << "Enter the name of new txt file" << endl;
    cin >> newFile;
    ofstream obf(newFile, ios::out);
    car b;
    itf.read((char*)&b, sizeof(car));
    while (!itf.eof()) {
        obf << b.number << endl << b.model << endl << b.colour << endl << b.man << endl << b.data << endl;
        itf.read((char*)&b, sizeof(car));
    }
    itf.close();
    obf.close();
    itf.clear();
    obf.clear();
    if (!itf.good() and !obf.good()) {
        return 1;
    }
    else {
        return 0;
    }
}

int directAccess(string filename) {
    fstream bf(filename, ios::binary | ios::in);
    cout << "Enter the number of entry" << endl;
    int k;
    cin >> k;
    car r;
    int i, kod;
    if (bf) {
        int offset = k * sizeof(car);
        bf.seekg(offset, ios::beg); 
        if (!bf.bad()) {
            bf.read((char*)&r, sizeof(car));
            kod = 0;
        }
        else {
            kod = 2;
        }
    }
    else {
        kod = 1;
    }
    return kod;
}

int removeFrom(string filename){
    cout << "Enter the key" << endl;
    string key;
    cin >> key;
    fstream obf(filename, ios::binary | ios::in);
    if (!obf) {
        return 1;
    }
    car b;
    int del = 0;
    obf.read((char*)&b, sizeof(car));
    while (!obf.eof()) {
        if (b.number == key) {
            break;
        }
        obf.read((char*)&b, sizeof(car));
        del ++;
    }
    obf.close();
    ifstream fi(filename, ios::binary);
    if (!fi) {
        return 1;
    } else {
        fi.seekg(0, ios::end);
        int size = fi.tellg();
        size = size / sizeof(car);
        car* mass = new car[size];
        fi.seekg(0, ios::beg);
        fi.read((char*)mass, sizeof(car) * size);
        fi.close();
        ofstream fo(filename, ios::binary | ios :: trunc);
        for (int i = 0; i < size; i++)
        {
            if (i != del)
                fo.write((char*)&mass[i], sizeof(car));
        }
        fo.close();
        fi.clear();
        fo.clear();
        if (!fi.good() and !fo.good()) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

int changeBinFile(string filename) {
    fstream f(filename, ios::in | ios::out | ios::binary);
    car x;
    string num;
    char newdate[11];
    if (!f) {
        return 1;
    }
    cout << "Enter the number of the car, which date need to replace" << endl;
    cin >> num;
    cout << "Enter new date" << endl;
    cin >> newdate;
    int i = 0;
    do
    {
        f.read((char*)&x, sizeof(car));
        if (x.number == num) {
            strcpy_s(x.data, newdate);
            f.seekg(sizeof(car) * i, ios::beg);
            f.write((char*)&x, sizeof(car));
            break;
        }
        i++;
    } while (!f.eof());
    f.close();
    f.clear();
    if (!f.good()) {
        return 1;
    }
    else {
        return 0;
    }
}

int formingList(string filename, vector <car>& list) {
    ifstream f(filename, ios::binary | ios::in);
    string model, date;
    car x;
    cout << "Enter the model of car" << endl;
    cin >> model;
    cout << "Enter the date" << endl;
    cin >> date;
    if (!f) {
        return 1;
    }
    do {
        f.read((char*)&x, sizeof(car));
        if (x.model == model and x.data == date) {
            list.push_back(x);
        }
    } while (!f.eof());
    f.close();
    f.clear();
    if (!f.good()) {
        return 1;
    }
    else {
        return 0;
    }
}

#endif