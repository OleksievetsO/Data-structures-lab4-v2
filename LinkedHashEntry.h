//
// Метод цепочек - открытое хеширование
//

#ifndef DICTIONARY_LINKEDHASHENTRY_H
#define DICTIONARY_LINKEDHASHENTRY_H

using namespace std;

class LinkedHashEntry {
    private:
        string key;
        long value;

        LinkedHashEntry *next;
//        int length;

    public:
        LinkedHashEntry(const string& key, const long value) {
            this->key = key;

            this->value = value;
            this->next = NULL;
//            this->length = 0;
    }

    string getKey() {
        return this->key;
    }

    long getValue() {
        return this->value;
    }

    void setValue(long value) {
        this->value = value;
    }

    LinkedHashEntry *getNext() {
        return next;
    }

    void setNext(LinkedHashEntry *next) {
        this->next = next;
    }

};
#endif //DICTIONARY_LINKEDHASHENTRY_H
