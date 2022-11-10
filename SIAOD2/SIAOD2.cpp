#include "siaod.h"

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Группа ИНБО-03-21 Шерри Г.Д. Вариант 27" << endl;
    int k;
    string namefile;
    int test;
    vector <car> list;
    cout << "Размер структуры составляет " << sizeof(car) << " байт" << endl;
    while (true) {
        cout << "Введите что вы хотите сделать 1 - Создать файл 2 - Посмотреть файл 3 - Скопировать бинарный файл в текстовый 4 - Прямой доступ к элементу файла 5 - Удаление по ключу 6 - Заменить дату 7 - Сформировать список" << endl;
        cin >> k;
        switch (k)
        {
        case 1:
            cin.get();
            cout << "Введите название файла" << endl;
            getline(cin, namefile);
            test = createBinFile(namefile);
            if (test == 1) {
                cout << "Ошибка" << endl;
            }
            else {
                cout << "Файл создан" << endl;
            }
            break;
        case 2:
            cout << "Введите название файла" << endl;
            cin >> namefile;
            test = outBinFile(namefile);
            if (test == 1) {
                cout << "Ошибка" << endl;
            }
            else {
                cout << "Файл успешно выведен" << endl;
            }
            break;
        case 3:
            cout << "Введите название файла" << endl;
            cin >> namefile;
            test = BinToTxt(namefile);
            if (test == 1) {
                cout << "Ошибка" << endl;
            }
            else {
                cout << "Новый файл успешно создан" << endl;
            }
            break;
        case 4:
            cout << "Введите название файла" << endl;
            cin >> namefile;
            test = directAccess(namefile);
            if (test == 1) {
                cout << "Ошибка" << endl;
            }
            else if (test == 0){
                cout << "Элемент найден" << endl;
            }
            else {
                cout << "Элемент не найден" << endl;
            }
            break;
        case  5:
            cout << "Введите название файла" << endl;
            cin >> namefile;
            test = removeFrom(namefile);
            if (test == 1) {
                cout << "Ошибка" << endl;
            }
            else {
                cout << "Удаление успешно сделанно" << endl;
            }
            break;
        case 6:
            cout << "Введите название файла" << endl;
            cin >> namefile;
            test = changeBinFile(namefile);
            if (test == 1) {
                cout << "Ошибка" << endl;
            }
            else {
                cout << "Замена успешно сделанна" << endl;
            }
            break;
        case 7:
            list.clear();
            cout << "Введите название файла" << endl;
            cin >> namefile;
            test = formingList(namefile, list);
            if (test == 1) {
                cout << "Ошибка" << endl;
            }
            else {
                cout << "Список сформирован успешно" << endl;
            }
            cout << "Ваш список: " << endl;
            for (int i = 0; i < list.size(); i++) {
                cout << list[i].number << endl << list[i].model << endl << list[i].colour << endl << list[i].man << endl << list[i].data << endl;
            }
            break;
        default:
            cout << "Неверные данные, повторите попытку" << endl;
            break;
        }
    }
    return 0;
}