#include "Dictionary.h"
#include "SpellChecker.h"

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    Dictionary dictionary("Words.txt");
    SpellChecker spellchecker;

    dictionary.check_inputFile("input.txt");

    return 0;
}


