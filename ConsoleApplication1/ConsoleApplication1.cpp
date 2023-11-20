#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Header.h"
#include "Source.cpp"
using namespace std;

int main()
{
    const char* filename = "save.txt";
    setlocale(LC_ALL, "Ru");
    Car c;
    Fabric f;
    // Отображение меню

    // Считывание ввода пользователя
    char choice;
    int menu = 0;
    // Обработка ввода пользователя
    while (menu != 1) {
        cout << "Выберите один из вариантов:\n";
        cout << "1. Добавить мебель\n";
        cout << "2. Добавить работников\n";
        cout << "3. Добавить машины\n";
        cout << "4. Очистить элементы и записать их в файл\n";
        cout << "5. Восстановить элементы из файла\n";
        cout << "6. Вывести текущие элементы\n";
        cout << "7. Выход\n";
        cin >> choice;
        switch (choice) {
        case '1':
            cout << "Выбран вариант 1\n";
            f.addFurniture();
            break;
        case '2':
            cout << "Выбран вариант 2\n";
            f.addWorker();
            break;
        case '3':
            cout << "Выбран вариант 3\n";
            f.addCar();
            break;
        case '4':
            cout << "Выбран вариант 4\n";
            f.Del(filename);
            break;
        case '5':
            f.ReadFromFile(filename);
            break;
        case '6':
            f.Print();
            break;
        case '7':
            cout << "Выход\n";
            menu = 1;
            break;
        default:
            cout << "Неверный выбор\n";
            break;
        }
    }
}