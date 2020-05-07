#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>

#include <chrono>
#include <bits/stdc++.h>

#include "HashMap.h"
#include "menuFunctions.cpp"

#define MAXWORDS 300000

using namespace std;


int main(){

    string *wrd=new string[MAXWORDS];


    string filename = getFilename();
    ifstream infile(filename);
    cout<<filename<<" loaded"<<endl;


    std::string linestr;
    int wordsInFile=0;
    while( infile >> linestr && wordsInFile<MAXWORDS)
    {
            linestr.erase(remove_if(linestr.begin(), linestr.end(), ::ispunct), linestr.end());
            wrd[wordsInFile]=linestr;
            wordsInFile++;
    }
    infile.close();
    cout<<"Total words in file : "<<wordsInFile<<endl;

    HashMap a;
    runHashing(a,wrd,wordsInFile);
    a.print();





    return 0;
}
