#pragma once
#include <iostream>
#include <vector>
#include <string>
class Base {
public:
    vector <string> word;
    virtual void turn_on() {}
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
        
        ofstream outF(filename, ios::out | ios::binary);

        if (!outF)
            return false;

      
        outF << word.size();
        outF << '\n';
       
        for (int i = 0; i < word.size(); i++)
        {
            outF << word[i];
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

        
        for (int i = 0; i < word.size(); i++)
        {
            word.pop_back();
        }
        
        inF.read((char*)word.size(), sizeof(int));

        char* x;
        for (int i = 0; i < word.size(); i++)
        {
            inF.read((char*)&x, sizeof(char*)); // прочитать 1 элемент типа double
            word[i] = x;
        }

       
        inF.close();

       
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
