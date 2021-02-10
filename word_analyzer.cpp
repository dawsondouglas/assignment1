#include "word_analyzer.h"
#include <string>

using namespace std;

int countLetters(string word)
{
    int count = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] >= 'A' && word[i] <= 'z')
        {
            count++;
        }
    }
    return count;
}

int countLettersInRange(string word, char lower, char upper)
{
    int count = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] >= lower && word[i] <= upper)
        {
            count++;
        }
    }
    return count;
}

int countUpperCaseLetters(string word)
{
    int count = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            count++;
        }
    }
    return count;
}