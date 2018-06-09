//
// Created by OLE on 27.04.2018.
//

#ifndef DICTIONARY_READDICTIONARY_H
#define DICTIONARY_READDICTIONARY_H
#include <fstream>
#include <string>

const int BUFF_SIZE = 50;
using namespace std;

class ReadDictionary {
private:
    ifstream file;
public:
//Конструктор, открывающий файл
    ReadDictionary(const char *FileName){

    file.open(FileName, ios_base::in | ios::binary); // відкрили файл для зчитування

    if (!file.is_open()) // якщо файл не відкрито
            cout << "Warning! Файл не відкрито" << endl;
    }

    //Метод чтения строки символов-байт с указанной позиции
    //который возвращает эту строку

    string read( long position ) {

        string dict_str;        // сюда буде кластися зчитаний рядок з фала

        if (!file.is_open()) return 0;

        file.seekg(position);   //встановлення позиції для зчитування рядка

        if (file.eof()) return 0;   //кінець файлу

//        char *memblock = new char[BUFF_SIZE];       // виділяєм блок памяті

//        file.getline(memblock, BUFF_SIZE, ';');     //зчитуэм до першого символа - пропускаєм слово пошуку

        getline(file, dict_str);   // зчитуєм рядок із файлу

//        delete[] memblock;          // звільняєм память

        return dict_str;
    }

//Деструктор, закрывающий файл
    ~ReadDictionary(){
        file.close();
    }
};

#endif //DICTIONARY_READDICTIONARY_H
