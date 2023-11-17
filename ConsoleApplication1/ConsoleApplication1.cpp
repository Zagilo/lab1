#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Base {
public:
    vector<string> word;

    virtual void turn_on() {}
    //virtual bool save(const char* filename) {}
    virtual void recovery() {}
    virtual ~Base() = 0 {}
};
class Furniture : public Base {
public:
    void turn_on() {}
    bool save(const char* filename) {}
    void recovery() {}
};
class Worker : public Base {
public:
    void turn_on() {}
    bool save(const char* filename) {}
    void recovery() {}
};
class Car : public Base {
public:
    void turn_on() {}
    bool save(const char* filename) {
        // 1. Создать экземпляр класса ofstream
        ofstream outF(filename, ios::out | ios::binary);

        if (!outF)
            return false;

        // 2. Записать количество элементов в массиве
        outF << word.size();
        outF << '\n';
        // 3. Записать непосредственно массив
        for (int i = 0; i < word.size(); i++)
        {
            outF << word[i];
            outF << '\n';
        }
        // 4. Закрыть файл
        outF.close();

        // 5. Вернуть true
        return true;
    }
    bool ReadFromFile(const char* filename)
    {
        // 1. Создать экземпляр класса ifstream, попытка открытия файла
        ifstream inF(filename, ios::in | ios::binary);

        if (!inF)
            return false;

        // 2. Сначала освободить предварительно выделенную память для массива
        for (int i = 0; i < word.size(); i++)
        {
            word.pop_back();
        }
        /*if (count > 0)
            delete[] A;*/

            // 3. Считать количество элементов в массиве
        inF.read((char*)word.size(), sizeof(int));

        //try
        //{
        //    // 4. Попытка выделить память для элементов массива
        //    A = new double[count];
        //}
        //catch (bad_alloc e)
        //{
        //    // 5. Если попытка неудачная, то выйти из функции
        //    cout << e.what();
        //    inF.close(); // закрыть файл
        //    return false;
        //}

        // 6. Прочитать массив поэлементно
        char* x;
        for (int i = 0; i < word.size(); i++)
        {
            inF.read((char*)&x, sizeof(char*)); // прочитать 1 элемент типа double
            word[i] = x;
        }

        // 7. Закрыть файловый поток
        inF.close();

        // 8. Выход с кодом true - файл прочитан
        return true;
    }
    void recovery() {}

    void Print()
    {
        for (int i = 0; i < word.size(); i++)
        {
            cout << word[i] << endl;
        }
    }
};
class Fabric : public Base {
public:
    Furniture a;
    Worker b;
    Car c;
    void turn_on() {}
    void recovery() {}
    void addFurniture() {
        string w;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Напишите тип мебели: " << endl;
        getline(cin, w);
        a.word.push_back(w);
        cout << "Напишите габариты (высота/ширина/глубина): " << endl;
        getline(cin, w);
        a.word.push_back(w);
        cout << "Напишите цвет: " << endl;
        getline(cin, w);
        a.word.push_back(w);
        cout << "Напишите материал: " << endl;
        getline(cin, w);
        a.word.push_back(w);
        cout << "Напишите стоимость: " << endl;
        getline(cin, w);
        a.word.push_back(w);
    }
    void addWorker() {
        string w;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Напишите ФИО: " << endl;
        getline(cin, w);
        b.word.push_back(w);
        cout << "Напишите Должность: " << endl;
        getline(cin, w);
        b.word.push_back(w);
        cout << "Напишите заработную плату: " << endl;
        getline(cin, w);
        b.word.push_back(w);
        cout << "Напишите адрес проживания: " << endl;
        getline(cin, w);
        b.word.push_back(w);
        cout << "Напишите телефон: " << endl;
        getline(cin, w);
        b.word.push_back(w);
    }
    void addCar() {
        string w;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Напишите марку машины: " << endl;
        getline(cin, w);
        c.word.push_back(w);
        cout << "Напишите модель машины: " << endl;
        getline(cin, w);
        c.word.push_back(w);
        cout << "Напишите гос номер машины: " << endl;
        getline(cin, w);
        c.word.push_back(w);
    }
    void Print()
    {
        for (int i = 0; i < a.word.size(); i++)
        {
            cout << a.word[i] << endl;
        }
        cout << ' ' << endl;
        for (int i = 0; i < b.word.size(); i++)
        {
            cout << b.word[i] << endl;
        }
        cout << ' ' << endl;
        for (int i = 0; i < c.word.size(); i++)
        {
            cout << c.word[i] << endl;
        }
        cout << ' ' << endl;
    }
    bool save(const char* filename) {
        // 1. Создать экземпляр класса ofstream
        ofstream outF(filename, ios::out | ios::binary);

        if (!outF)
            return false;

        // 2. Записать количество элементов в массиве
        outF << a.word.size();
        outF << '\n';
        // 3. Записать непосредственно массив
        for (int i = 0; i < a.word.size(); i++)
        {
            outF << a.word[i];
            outF << '\n';
        }
        outF << b.word.size();
        outF << '\n';
        // 3. Записать непосредственно массив
        for (int i = 0; i < b.word.size(); i++)
        {
            outF << b.word[i];
            outF << '\n';
        }
        outF << c.word.size();
        outF << '\n';
        // 3. Записать непосредственно массив
        for (int i = 0; i < c.word.size(); i++)
        {
            outF << c.word[i];
            outF << '\n';
        }
        // 4. Закрыть файл
        outF.close();

        // 5. Вернуть true
        return true;
    }
    bool ReadFromFile(const char* filename)
    {
        // 1. Создать экземпляр класса ifstream, попытка открытия файла
        ifstream inF(filename, ios::in | ios::binary);

        if (!inF)
            return false;

        // 2. Сначала освободить предварительно выделенную память для массива
        for (int i = 0; i < a.word.size(); i++)
        {
            a.word.pop_back();
        }
        for (int i = 0; i < b.word.size(); i++)
        {
            b.word.pop_back();
        }
        for (int i = 0; i < c.word.size(); i++)
        {
            c.word.pop_back();
        }
        int count = 0;
        string w;
        // 3. Считать количество элементов в массиве
        inF >> count;
        for (int i = 0; i < count; i++)
        {
            inF >> w;
            a.word.push_back(w);
        }
        inF >> count;
        for (int i = 0; i < count; i++)
        {
            inF >> w;
            b.word.push_back(w);
        }
        inF >> count;
        for (int i = 0; i < count; i++)
        {
            inF >> w;
            c.word.push_back(w);
        }
        // 7. Закрыть файловый поток
        inF.close();
        cout << "Данные восстановлены" << endl;
        // 8. Выход с кодом true - файл прочитан
        return true;
    }
    void Del(const char* filename) {
        save(filename);
        for (int i = 0; i < a.word.size(); i++)
        {
            a.word.pop_back();
        }
        for (int i = 0; i < b.word.size(); i++)
        {
            b.word.pop_back();
        }
        for (int i = 0; i < c.word.size(); i++)
        {
            c.word.pop_back();
        }
        cout << "Данные очищены и сохранены в файл" << endl;
    }
};


class Computer : public Base {};
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
