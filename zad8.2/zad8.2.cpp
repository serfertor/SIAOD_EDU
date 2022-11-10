#include <iostream> 
using namespace std;

struct host
{
	int val; //вводимое значение
	host* next; //указатель на следующий элемент
	host(int a) : val(a), next(nullptr) {} //конструктор значения
};

struct list /*указатели на первый и последний элементы в списке*/
{
	host* start; host* end;
	list() : start(nullptr), end(nullptr) {}

	bool is_empty()	//пустой ли список на данный момент?
	{
		return start == nullptr;
	}

	void push_back(int a)
	{
		host* point = new host(a); 
		if (is_empty())
		{
			start = point; 
			end = point; 
			return;
		}
		end->next = point; 
		end = point;
	}

	void print()
	{
		if (is_empty()) return; host* point = start;

		while (point) {
			cout << point->val << " "; 
			point = point->next;
		}
		cout << endl;
	}

	host* findeNode(host* L, int choic)
	{
		int ccounter = 1; 
		host* link = L;
		while (link != 0 && ccounter < choic) {
			ccounter++; 
			link = link->next;
		}
		return link;
	}

	int size()
	{
		int counter = 0;
		if (is_empty()) return 0; 
		host* point = start; 
		while (point) {
			counter++;
			point = point->next;
		}
		return counter;
	}

	void deleting(host* hostik, list* llist)
	{
		if (hostik == NULL) return;
		if ((hostik == llist->start) and (hostik->val == 0))
		{
			host* linkk = llist->start; 
			host* linkkk = linkk->next; 
			linkk->next = nullptr;
			start = linkkk; 
			hostik = linkkk;
			deleting(hostik, llist);
		}
		if ((hostik == llist->end) and (hostik->val == 0))
		{
			host* mnogo_link = findeNode(llist->start, llist->size() - 1);
			mnogo_link->next = 0; 
			end = mnogo_link;
		}
		else if ((hostik->next != nullptr) and (hostik->next->val == 0))
		{
			host* tmp = hostik->next; // удаляемый элемент hostik->next = tmp->next;
			delete tmp;
			deleting(hostik->next, llist);
		}
		else { 
			deleting(hostik->next, llist); 
		}
	}
};

int main()
{
	setlocale(LC_ALL, "RUS"); list object1;
	int digit, number; 
	int counter = 0;
	cout << "Введите количество элементов в Вашем списке." << endl; 
	cin >> digit;
	while (counter != digit)
	{
		cout << "Введите значение элемента списка. Двузначное или однозначное число:" << endl;
		cin >> number; object1.push_back(number); counter++;
	}
	cout << "Ваш список:" << endl; 
	object1.print();
	object1.deleting(object1.start, &object1); 
	cout << "После удаления нулей:" << endl; 
	object1.print();
}
