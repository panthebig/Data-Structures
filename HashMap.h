#ifndef HASHMAP_H
#define HASHMAP_H

#include "HashTable.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class HashMap
{
    public:
        HashMap();
        ~HashMap();
        bool AddElement(string);
        bool FindElement(string);




        void print();


    protected:

    private:
        HashTable *table;
        const int Mapsize = 25000;     //size of hash data structure
        int uniqueWords = 0;
};
        int addin(string);

#endif // HASHMAP_H
