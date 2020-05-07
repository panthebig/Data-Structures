#ifndef MENUFUNCTIONS_H_INCLUDED
#define MENUFUNCTIONS_H_INCLUDED


#include "menuFunctions.h"
#include "Hashmap.h"

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;

bool fileExists(string);
string getFilename();
void runHashing(HashMap &,string* &,int &);


bool fileExists(string filename)
{
    std::ifstream file(filename.c_str());
    if(file.is_open() )
    {
        file.close();
        return true;
    }
    return false;
}


string getFilename()
{
    string defaultFilename = "inputfile.txt";
    string inputFilename;
    cout<<"Give the name of the file you want to load"<<endl;
    cout<<"if nothing is given the program will load inputfile.txt"<<endl;
    getline(cin,inputFilename);

    if(inputFilename.empty())
    {
        return defaultFilename;

    }
    else
    {
        if(fileExists(inputFilename))
            return inputFilename;
        else
        {
            cout<<"The file cant be found default will be loaded"<<endl;
            return defaultFilename;
        }
    }
}

void runHashing(HashMap &a,string* &wrd,int &wordsInFile)
{
    random_device rd;

    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);


    for(int i=0 ;i<1000;i++)
    {
        int random = rd()%wordsInFile;
        a.AddElement(wrd[random]);
    }


    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Hashing took : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;

}

#endif
