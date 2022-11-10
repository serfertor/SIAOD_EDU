#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;


void coutp(unsigned int x)
{
	int n = sizeof(int) * 8;
	unsigned  maska = (1 << (n - 1));
	for (int i = 1; i <= n; i++)
	{
		cout << ((x & maska) >> (n - i));
		maska = maska >> 1;
	}
	cout << endl;
}

void upr1() {
	cout << "Upr 1" << endl;
	unsigned int vvod = 0x66;
	unsigned int maska = 137;
	cout << "start digit" << endl;
	coutp(vvod);
	vvod = vvod | ((maska << 2));
	cout << "end digit" << endl;
	coutp(vvod);
}

void upr2() {
	cout << "Upr 2" << endl;
	unsigned int vvod;
	unsigned int maska = 137;
	cin >> vvod;
	vvod = vvod & (~((maska << 2)));
	coutp(vvod);
}

void upr3() {
	cout << "Upr 3" << endl;
	unsigned int vvod;
	cin >> vvod;
	vvod = vvod << 4;
	cout << vvod << endl;
}

void upr4() {
	cout << "Upr 4" << endl;
	unsigned int vvod;
	cin >> vvod;
	vvod = vvod >> 5;
	cout << vvod << endl;
}

void upr5() {
	cout << "Upr 5" << endl;
	unsigned int vvod;
	unsigned int maska = 1;
	unsigned int n;
	cout << "Changeble digit" << endl;
	cin >> vvod;
	cout << "position" << endl;
	cin >> n;
	vvod = vvod | ((maska << n));
	coutp(vvod);
}

void sort (){
	clock_t t1, t2, t3;
	int* mass = new int[312500];
	unsigned int maska = 1;
	unsigned int vvod;
	unsigned long int kop = 0;
	t1 = clock();
	for (int i = 0; i < 312500; i++) {
		mass[i] = 0;
	}
	for (int i = 0; i < 100; i++){
		cin >> vvod;
		kop = (vvod - 1000000)/ 32;
		mass[kop] = mass[kop] | (maska << ((vvod - 1000000) %32));
	}
	for (int i = 0; i < 312500; i++){
		for (int j = 0; j < 32; j++){
			if (mass[i] & (1 << j)) {
				cout << (i * 32 + j)+ 1000000 << "\t";
			}
		}
	}
	t2 = clock();
	t3 = t2 - t1;
	cout << ((double)(t3) / CLOCKS_PER_SEC) << " sec." << endl;
	delete[] mass;
}
int main()
{
	sort();
	return 0;
}

