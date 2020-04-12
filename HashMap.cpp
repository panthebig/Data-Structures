#include "HashMap.h"

int addin(string s)
{
    int sum=0;
    for(unsigned int i =0;i<s.length();i++)
    {
        sum += s[i];
    }
    return sum;
}

HashMap::HashMap()
{
    table = new HashTable[Mapsize];
}

HashMap::~HashMap()
{
    delete[] table;
}

bool HashMap::AddElement(string word)
{
    int sum = addin(word);
    int i=1;
    while (1)
    {
        int temp = (sum +(i*i))%Mapsize;                    //new element addition based on the sum of ASCII sum of character
        if(table[temp].Getword() == word )                  //Quadratic Hash table
        {
            table[temp].Setrepeat(table[temp].Getrepeat()+1);
            return true;
        }
        else if(table[temp].Getword().empty())
        {
            table[temp].Setword(word);
            table[temp].Setrepeat(1);
            return true;
        }
        else
        {
            i++;
        }
    }

}
bool HashMap::FindElement(string word)
{
    int sum = addin(word);
    int i=1;
    while (1)
    {
        int temp = (sum +(i*i))%Mapsize;                    //Search Function
        if(table[temp].Getword() == word )                  //Quadratic Hash table
        {
            return true;
        }
        else if(table[temp].Getword().empty())
        {
            return false;
        }
        else
        {
            i++;
        }
    }

}


void HashMap::print()
{
    for(int i =0;i<1000;i++)
    {
        if(!(table[i].Getword().empty()))
            cout<<table[i].Getword()<<" "<<table[i].Getrepeat()<<endl;
    }
}
