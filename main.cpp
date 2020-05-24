#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <ctime>

#include <chrono>
#include <bits/stdc++.h>

#include "HashMap.h"
#include "BstNode.h"
#include "AvlTree.h"

#include "menuFunctions.h"

#define MAXWORDS 300000
#define RANDOMWORDS 5000

using namespace std;


int main(){

    string *wrd=new string[MAXWORDS];
    string *Q=new string[RANDOMWORDS];


    string filename = getFilename();
    ifstream infile(filename);
    cout<<filename<<" loaded"<<endl;


    BstNode *BSTroot=NULL;
    AvlTreeNode *AVLroot=NULL;
    HashMap a;

    string linestr;
    int wordsInFile=0;
    while( infile >> linestr && wordsInFile<MAXWORDS)
    {
            linestr.erase(remove_if(linestr.begin(), linestr.end(), ::ispunct), linestr.end());
            wrd[wordsInFile]=linestr;

            BSTroot = Insert(BSTroot,linestr);
            AVLroot = AvlInsertion(AVLroot,linestr);
            a.AddElement(linestr);

            wordsInFile++;
    }

    infile.close();
    cout<<"Total words in file : "<<wordsInFile<<endl;
    cout<<"All three data structurs have been created successfully !"<<endl<<endl;

    srand(time(0));
    int i,randIndex;
    for(i=0;i<5000;i++)
    {
        randIndex = rand() %wordsInFile;
        Q[i]=wrd[randIndex];
    }

    //Binary Tree
    runBstNode(BSTroot,Q,wordsInFile);



    //AVL TREE
    runAVL(AVLroot,Q,wordsInFile);


    //Hash

    //HashMap a;
    //runHashing(a,wrd,wordsInFile);
    //a.print();

    return 0;
}
