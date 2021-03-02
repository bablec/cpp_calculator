#include "fraction.h"
#include "dictionary.h"

Dictionary::Dictionary() {
    keys = new std::string[SIZE];
    values = new Fraction[SIZE];
    length = 0;
}

void Dictionary::clear() {
    keys = new std::string[SIZE];
    values = new Fraction[SIZE];
    length = 0;
}

bool Dictionary::isEmpty() {
    return length == 0;
}

int Dictionary::size() {
    return length;
}

void Dictionary::insert(std::string k, Fraction v) {
    //first must check if key exists anywhere in array
    for (int i = 0; i < SIZE; i++) {
        if (k == keys[i]) {
            throw std::domain_error("Cannot insert - Key already exists");
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (keys[i].empty()) {
            keys[i] = k;
            values[i] = v;
            length++;
            return;
        }
    }
    throw std::overflow_error("Cannot insert - Dictionary is full");
}

void Dictionary::remove(std::string k) {
    for (int i = 0; i < SIZE; i++) {
        if (k == keys[i]) {
            keys[i] = std::string();
            values[i] = Fraction();
            length--;
            return;
        }
    }
    throw std::domain_error("Cannot remove - Key does not exist");
}

Fraction Dictionary::search(std::string k) {
    for (int i = 0; i < SIZE; i++) {
        if (k == keys[i]) {
            return values[i];
        }
    }
    throw std::domain_error("Seach - Key does not exist");
}

void Dictionary::update(std::string k, Fraction v) {
    for (int i = 0; i < SIZE; i++) {
        if (k == keys[i]) {
            values[i] = v;
            return;
        }
    }
    throw std::domain_error("Cannot update - Key does not exist");
}

void Dictionary::forceUpdate(std::string k, Fraction v) {
    // first must check if key exists anywhere in array before inserting
    for (int i = 0; i < SIZE; i++) {
        if (k == keys[i]) {
            values[i] = v;
            return;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (keys[i].empty()) {
            keys[i] = k;
            values[i] = v;
            length++;
            return;
        }
    }
}

bool Dictionary::getFirstKey(std::string &k) {
    for (int i = 0; i < SIZE; i++) {
        if (!keys[i].empty()) {
            k = keys[i];
            return true;
        } 
    }
    return false;
}

bool Dictionary::getNextKey(std::string &k) {
    for (int i = 0; i < SIZE-1; i++) {
        if (k == keys[i]) {
            for (int j = i+1; j < SIZE; j++) {
                if (!keys[j].empty()) {
                    k = keys[j];
                    return true;
                }
            }
        }
    }
    return false;
}