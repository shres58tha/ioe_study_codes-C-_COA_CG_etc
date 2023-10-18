#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <iostream>
#include <vector>
using namespace std;

class SpellChecker
{
private:
    vector<string> suggestion_list;

    void CreateWordList_bySwappingAdjCharacters(const string word);

    void CreateWordList_byDeletingCharacters(const string word);

    void CreateWordList_byReplacingCharacters(const string word);

public:
    void to_lower_case(string &word);
    void remove_unnecessary_characters(string &word);
    bool contains(const string &word);
    vector<string> get_suggestions(const string &word);
    void clear_suggestion_list();
};

#endif