#include "Dictionary.h"
#include "SpellChecker.h"

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

Dictionary dictionary("Words.txt");

void SpellChecker ::CreateWordList_bySwappingAdjCharacters(string word)
{

    // try to find some alternating spellings
    //for each position in word up to 2nd to last
    for (int i = 0; i < word.size() - 1; i++)
    {
        //create copy of word
        string newWord = word;

        //swap adjecent letters at i and i+1
        swap(newWord[i], newWord[i + 1]);

        // if new word is in dictionary, then add it to list of possible
        // corrections
        if (contains(newWord))
        {
            suggestion_list.push_back(newWord);
        }
    }
}

void SpellChecker::CreateWordList_byDeletingCharacters(string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        string newWord = word;
        newWord.erase(newWord.begin() + i);

        if (contains(newWord))
        {
            suggestion_list.push_back(newWord);
        }
    }
}

void SpellChecker::CreateWordList_byReplacingCharacters(string word)
{

    for (int i = 0; i < word.size(); i++)
    {
        char ch = 'a';
        for (int j = 0; j < 26; j++)
        {
            string newWord = word;
            newWord[i] = ch;

            if (contains(newWord))
            {
                suggestion_list.push_back(newWord);
            }

            ch++;
        }
    }
}

void SpellChecker::to_lower_case(string &word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
}

void SpellChecker::remove_unnecessary_characters(string &word)
{
    int last_letter = word.length() - 1;
    if (word[last_letter] == '.' || word[last_letter] == '!' || word[last_letter] == '?')
    {
        word.erase(last_letter);
    }
}

vector<string> SpellChecker::get_suggestions(const string &word)
{
    CreateWordList_byDeletingCharacters(word);
    CreateWordList_byReplacingCharacters(word);
    CreateWordList_bySwappingAdjCharacters(word);

    return suggestion_list;
}

void SpellChecker::clear_suggestion_list()
{
    suggestion_list.clear();
}

bool SpellChecker::contains(const string &word)
{
    if (dictionary.wordDictionary[word] == word)
    {
        return true;
    }
    return false;
}
