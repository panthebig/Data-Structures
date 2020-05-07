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
        const int Mapsize = 1000;
};

#endif // HASHMAP_H
