#include <iostream>
#include <fstream>
#include <string>

#include "HashMap.h";
#include "ReadDictionary.h";

using namespace std;

int main() {

    const char *FileName = "E:\\WEB\\CLion 2018.1\\CLionProjects\\Dictionary lab4 v2\\dict_processed.txt";
    const char *FileName = "dict_processed.txt";

    char buff[BUFF_SIZE]; // буфер промежуточного хранения считываемого из файла текста
    string src_str; // сюда будем класть считанные строки
    long position;  //поточна позиція

    HashMap hashMap;

    ifstream file(FileName, ios_base::in | ios::binary); // открыли файл для чтения

    if (!file.is_open()) // якщо файл не відкритий
        cout << "Warning! The file is not open" << endl;
    else {
        position = 0;       // початкова позиція рядка 1
        cout << endl << "Please wait. Build a  hesh table... " << endl;

        while (!file.eof()) {
//        for (int i = 0; i < 10; i++) {
            file.getline(buff, BUFF_SIZE, ';');     //зчитуэм до першого символа ;

            hashMap.put(string(buff), position);    // записуєм ключ/значення в таблицю

            getline(file, src_str);   // зчитали рядок із файла
            position = long(file.tellg());

//            system("pause");
        }
        file.close(); // закриваєм файл, щоб не пошкодити його
    }

    ReadDictionary dictionary(FileName);     //клас для виборки данних з файлу по покажчику вводу
    char choice;
    bool run = true;
    string word;

    while (run)  //працюємо, поки Yes
    {
        cout << endl << "Enter the word to define?";
//        cin >> word;
        getline(cin, word);        //стандартний   cin >> word; не спрацьовує на key = "A B C"
        for (auto &c : word) c = toupper(c);        // робимо все прописними
        cout << "\nword " << word;

        position = hashMap.get(word);

        cout << "\nType a word to get definition: hash [Enter] " << word
             << "\n\tfound position in the file: " << position << endl;

        cout << "\ndefine [Enter]" << word << endl;
        if (position < 0)
            cout << endl << "There was nothing found\n"
                            "\ton your request: ";
        else {
            cout << dictionary.read(position) << endl;
        }
            do {
                cout << "\nYou want to continue?(Y/N)" << endl;
                cin >> choice;
                choice = tolower(choice);   //Put your letter to its lower case
            } while (choice != 'n' && choice != 'y');
            cin.ignore();       // ігнорує \ n, що cin >> str залишив (якщо користувач натиснув клавішу Enter)
            if (choice == 'n') {
                run = false;
            }
    }


    return 0;
}


