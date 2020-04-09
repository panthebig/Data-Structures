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
    int i,m,n;

    /*char **wrd;         //Two dimensional array that has the words of string line(each word is in a different row)
    wrd=new char*[1000];
    for(i=0;i<1000;i++)
        wrd[i]=new char[100];*/
    char wrd[1000][100];

    m=0;
    n=0;
    for(i=0;i<strlen(line.c_str());i++) //m shows the row and n the collum of raw m
    {
        if(line[i]!=' ')
        {
            wrd[m][n]=line[i];
            n++;
        }
        else
        {
            wrd[m][n]='\0';
            n=0;
            m++;
        }
    }
    int j;
    cout<<"--"<<endl;
    for(i=0;i<=m;i++)
    {
        for(j=0;wrd[i][j]!='\0';j++)
            cout<<wrd[i][j];
        cout<<endl;
    }

    //delete wrd;


}
