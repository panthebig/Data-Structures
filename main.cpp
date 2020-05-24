#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>

#include <chrono>
#include <bits/stdc++.h>

#include "HashMap.h"
#include "BstNode.h"
#include "AvlTree.h"

#include "menuFunctions.h"

#define RANDOMWORDS 300000



using namespace std;


int main(){

    string *randomWords=new string[RANDOMWORDS];
    int randomWordsIndex=0;
    random_device rd;


    string filename = getFilename();
    ifstream infile(filename);
    cout<<filename<<" loaded"<<endl;

    BstNode *BSTroot=NULL;
    AvlTreeNode *AVLroot=NULL;
    HashMap a;

    string linestr;
    int wordsInFile=0;
    while( infile >> linestr)
    {
            linestr.erase(remove_if(linestr.begin(), linestr.end(), ::ispunct), linestr.end());
            if(!(rd()%10))
            {
                randomWords[randomWordsIndex] = linestr;
                randomWordsIndex++;
                //cout<<wordsInFile<<" "<<linestr;
            }


            BSTroot = Insert(BSTroot,linestr);
            AVLroot = AvlInsertion(AVLroot,linestr);
            a.AddElement(linestr);

            wordsInFile++;
    }

    infile.close();
    cout<<"Total words in file : "<<wordsInFile<<endl<<endl;


    searchRandom(a,BSTroot,AVLroot,randomWordsIndex,randomWords);

    //Binary Tree
    //runBstNode(BSTroot,wrd,wordsInFile);



    //AVL TREE
    //runAVL(AVLroot,wrd,wordsInFile);


    //Hash
    //runHashing(a,wrd,wordsInFile);

    return 0;
}
