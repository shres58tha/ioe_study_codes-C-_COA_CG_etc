#include "Dictionary.h"
#include "SpellChecker.h"

#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>

using namespace std;

Dictionary ::Dictionary() {}

Dictionary ::Dictionary(const string &filename)
{
    ifstream fin;
    fin.open(filename);
    SpellChecker spellchecker;

    if (fin.is_open())
    {
        string word;
        //using ifstream's extraction operator to read word
        // (fin >> word) returns false if 'eof' reached
        while (fin >> word)
        {
            spellchecker.to_lower_case(word);
            //changes any word to lowercase
            wordDictionary.emplace(word, word);
            //puts every word in the dictionary in unordered_map
            //with the word it self as the key so that
            //when we search for the word we can just
            //enter the word as the key and get the word in O(n) time.
        }
    }
    else
    {
        cout << "Error opening the file" << filename << endl;
    }
}

void Dictionary ::check_inputFile(const string &filename)
{
    ifstream fin;
    fin.open(filename);
    SpellChecker spellchecker;

    if (fin.is_open())
    {
        string word;
        //using ifstream's extraction operator to read word
        // (fin >> word) returns false if 'eof' reached
        while (fin >> word)
        {
            spellchecker.to_lower_case(word);
            //changes any word to lowercase

            spellchecker.remove_unnecessary_characters(word);
            //removes fullstops, exlamation marks and question marks
            //at the end of the word.

            //for each word we have three possibilities,
            // 1. Found in the dictionary so we assume correct.
            // 2. not found, but no sugesstions.
            // 3. not found, but we do find sugesstions.
            cout << word;
            if (wordDictionary.find(word) != wordDictionary.end())
            {
                //case 1: found
                cout << ": ok" << endl;
            }
            else
            {
                // look for alternative spellings of the word.
                vector<string> alternative_word_list =
                    spellchecker.get_suggestions(word);

                spellchecker.clear_suggestion_list();

                if (alternative_word_list.empty())
                {
                    //case 2: not found, but no sugesstions.
                    cout << ": mispelled? no suggestions" << endl;
                }
                else
                {
                    //case 3: word not found, but we have suggestions.
                    cout << ": mispelled? suggestions -> ";
                    for (auto alternative_word : alternative_word_list)
                    {
                        cout << alternative_word << ", ";
                    }
                    cout << endl;
                }
            }
        }
    }
    else
    {
        cout << "Error opening the file" << filename << endl;
    }
}