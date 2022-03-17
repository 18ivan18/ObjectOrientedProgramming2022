#include <iostream>
#include <cstring>
#include "Record.h"

void Record::init(const char *word, const char *meaning)
{
    this->word = new char[strlen(word) + 1];
    strcpy(this->word, word);

    this->meaning = new char[strlen(meaning) + 1];
    strcpy(this->meaning, meaning);
}

Record Record::copy() const
{
    Record result;
    result.init(this->word, this->meaning);
    return result;
}

void Record::print() const
{
    std::cout << this->word << " - " << this->meaning << '\n';
}

void Record::deleteDynamic()
{
    delete[] this->word;
    delete[] this->meaning;
}

char *Record::getWord() const
{
    return this->word;
}

char *Record::getMeaning() const
{
    return this->meaning;
}