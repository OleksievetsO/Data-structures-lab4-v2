//
// Created by OLE on 27.04.2018.
//

#ifndef DICTIONARY_HASHMAP_H
#define DICTIONARY_HASHMAP_H

#include <string>

#include "LinkedHashEntry.h";

using namespace std;

const int TABLE_SIZE = 128;

class HashMap {
private:
    LinkedHashEntry **table;


public:
    HashMap() {
        table = new LinkedHashEntry*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }

    long get(string key) {
        int hash = hashFun(key);

        if (table[hash] == NULL)
            return -1;
        else {
            LinkedHashEntry *entry = table[hash];
//            while (entry != NULL && (key.compare(entry->getKey()) != 0)) {
            while (entry != NULL && entry->getKey() != key) {
                entry = entry->getNext();
            }
            if (entry == NULL)
                return -1;
            else
                return entry->getValue();
        }
    }

//hash function- приклад з курсу прінстонського університету
    int hashFun(const string& s) {
        int hash = 0;
        for (auto &ch : s)  hash = (31 * hash + ch ) % TABLE_SIZE;
        return hash;
    }

// Returns an array location for a given item key.
//    int hashFun( const string itemKey )
//    {
//        int value = 0;
//        for ( int i = 0; i < itemKey.length(); i++ )
//            value += itemKey[i];
//        return (value * itemKey.length() ) % length;
//    }

    void put(const string& key, const long value) {

        int hash = hashFun(key);

//        cout << "put -> key: " << key << " | hash: " << hash << " | value: " <<  value << endl;

        if (table[hash] == NULL)
            table[hash] = new LinkedHashEntry(key, value);
        else {
            LinkedHashEntry *entry = table[hash];
            while (entry->getNext() != NULL)
                entry = entry->getNext();
//            if (entry->getKey() == key)
//                entry->setValue(value);
//            else
                entry->setNext(new LinkedHashEntry(key, value));
        }
    }

//    void remove(int key) {
//        int hash = (key % TABLE_SIZE);
//        if (table[hash] != NULL) {
//            LinkedHashEntry *prevEntry = NULL;
//            LinkedHashEntry *entry = table[hash];
//
//            while (entry->getNext() != NULL && entry->getKey() != key) {
//                prevEntry = entry;
//                entry = entry->getNext();
//            }
//
//            if (entry->getKey() == key) {
//                if (prevEntry == NULL) {
//                    LinkedHashEntry *nextEntry = entry->getNext();
//                    delete entry;
//                    table[hash] = nextEntry;
//                } else {
//                    LinkedHashEntry *next = entry->getNext();
//                    delete entry;
//
//                    prevEntry->setNext(next);
//                }
//            }
//        }
//    }

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++)
            if (table[i] != NULL) {
                LinkedHashEntry *prevEntry = NULL;
                LinkedHashEntry *entry = table[i];
                while (entry != NULL) {
                    prevEntry = entry;
                    entry = entry->getNext();
                    delete prevEntry;
                }
            }
        delete[] table;
    }
};


#endif //DICTIONARY_HASHMAP_H
