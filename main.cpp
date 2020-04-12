#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <vector>

#include "BinaryTree.h"

using namespace std;

int main()
{
    string *wrd=new string[8000000];
    int m,i;

    BinaryTree BiTree; //create new tree object in BinaryTree Class


    ifstream infile("inputfile.txt");   //opens the file named inputfile.txt
    std::string linestr;
    vector<string> word;

    m=0;
    while( infile >> linestr)
    {
            linestr.erase(remove_if(linestr.begin(), linestr.end(), ::ispunct), linestr.end());
            wrd[m]=linestr;
            word.push_back(linestr);
            m++;
    }

    for(i=0;i<m;i++)
    {
        cout<<wrd[i]<<"--TEST--"<<endl; //edo tha bei to BiTree.CreateBinaryTree(wrd[i]);
    }

    cout<<"Number of words:"<<m;



    return 0;
}
