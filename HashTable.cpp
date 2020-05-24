#include "HashTable.h"

HashTable::HashTable()
{
    word = string();
    repeat = 0;
}
HashTable::HashTable(string word,int repeat)
{
    this->word = word;
    this->repeat = repeat;
}
