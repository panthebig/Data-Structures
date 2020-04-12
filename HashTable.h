#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>

using namespace std;

class HashTable
{
    public:
        HashTable();
        HashTable(string,int);

        string Getword()const  { return word; }
        void Setword(string val) { word = val; }
        int Getrepeat()const {return repeat; }
        void Setrepeat(int val) {repeat = val; }

    protected:

    private:
        string word;
        int repeat;
};

#endif // HASHTABLE_H
