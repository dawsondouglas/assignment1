#include "word_analyzer.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int getWords(int arraySize, string words[], string filename)
{
    int count = 0;
    fstream file;

    file.open(filename);
    if (file.fail())
    {
        return -1;
    }
    else
    {
        string temp;
        while (file >> temp )
        {
            words[count] = temp;
            temp = "";
            count++;
        }
    }

    return count;
}

string findLongestWord(int size, string words[])
{
    string longest = "";
    string temp;

    for (int i = 0; i < size; i++)
    {
        temp = words[i];
        if (temp.length() > longest.length())
        {
            longest = temp;
        }
    }

    return longest;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Correct usage:\n./text_analyzer filename";
        return -1;
    }
    string filename = argv[1];
    string words[100];
    string longestWord;
    int wordCount = getWords(100, words, filename);
    int fileLetters = 0;
    int upperCaseLetters = 0;
    int lettersBetween = 0;

    if (wordCount == -1)
    {
        cout << "The file " + filename + " could not be opened";
        return -1;
    }


    longestWord = findLongestWord(wordCount, words);
    for (int i = 0; i < wordCount; i++)
    {
        fileLetters += countLetters(words[i]);
        upperCaseLetters += countUpperCaseLetters(words[i]);
        lettersBetween += countLettersInRange(words[i], 'a', 'f');
    }

    cout << "There are " << fileLetters << " letters in your file.\n";
    cout << "There are " << upperCaseLetters << " upper case letters in your file.\n";
    cout << "There are " << lettersBetween << " letters between 'a' and 'f'.\n";
    cout << "The longest word in this file is \"" << longestWord << \"";

    return 0;
}