#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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
   
        ofstream outF(filename, ios::out | ios::binary);

        if (!outF)
            return false;

     
        outF << a.word.size();
        outF << '\n';
        
        for (int i = 0; i < a.word.size(); i++)
        {
            outF << a.word[i];
            outF << '\n';
        }
        outF << b.word.size();
        outF << '\n';
    
        for (int i = 0; i < b.word.size(); i++)
        {
            outF << b.word[i];
            outF << '\n';
        }
        outF << c.word.size();
        outF << '\n';

        for (int i = 0; i < c.word.size(); i++)
        {
            outF << c.word[i];
            outF << '\n';
        }
    
        outF.close();

 
        return true;
    }
    bool ReadFromFile(const char* filename)
    {
  
        ifstream inF(filename, ios::in | ios::binary);

        if (!inF)
            return false;

    
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
     
        inF.close();
        cout << "Данные восстановлены" << endl;
     
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