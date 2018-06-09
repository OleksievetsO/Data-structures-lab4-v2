
// Открытая индексация (или закрытое хеширование)


#ifndef DICTIONARY_HASHENTRY_H
#define DICTIONARY_HASHENTRY_H


class HashEntry {

private:
    int key;
    int value;

public:
    HashEntry(int key, int value) {
        this->key = key;
        this->value = value;
    }

    int getKey() {
        return key;
    }

    int getValue() {
        return value;
    }

};
#endif //DICTIONARY_HASHENTRY_H
