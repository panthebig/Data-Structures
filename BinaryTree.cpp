#include "BinaryTree.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

BinaryTree::BinaryTree()
{

}

void BinaryTree::CreateBinaryTree(std::string line)
{
    int i,m;

    string wrd[1000];
    string word="";

    m=0;

    for(i=0;i<=strlen(line.c_str());i++) //m shows the row and n the collum of raw m
    {
        if(line[i]!=' ')
        {
            word=word+line[i];
        }
        else
        {
            wrd[m]=word;
            m++;
            word="";
        }
    }
    wrd[m]=word;

   if(a.info.empty())
        cout<<"NAII   ";




    /*
    cout<<"--"<<endl;
    for(i=0;i<=m+1;i++)
    {
        cout<<wrd[i]<<endl;
    }*/



}

