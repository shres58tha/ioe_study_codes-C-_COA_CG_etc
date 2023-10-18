#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "SpellChecker.h"

#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Dictionary
{
private:
    vector<string> suggestions;

    SpellChecker spell_checker;

public:
    unordered_map<string, string> wordDictionary;
    Dictionary();
    Dictionary(const string &filename);

    void check_inputFile(const string &filename);
};

#endif

