#include <string>
#include "fraction.h"

#ifndef _DICTIONARY_H
#define _DICTIONARY_H

const int SIZE = 100;

class Dictionary {
private:
    std::string *keys;
    Fraction *values;
    int length;
public:
    Dictionary();
    // ~Dictionary();
    
    void clear();
    bool isEmpty();
    int size();

    void insert(std::string k, Fraction v);
    void remove(std::string);
    Fraction search(std::string);
    void update(std::string k, Fraction v);

    void forceUpdate(std::string k, Fraction v);
    bool getFirstKey(std::string &k);
    bool getNextKey(std::string &k);
};

#endif