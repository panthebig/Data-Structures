#ifndef MENUFUNCTIONS_H_INCLUDED
#define MENUFUNCTIONS_H_INCLUDED


#include "Hashmap.h"
#include "BstNode.h"
#include "AvlTree.h"

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;

bool fileExists(string);
string getFilename();
void runHashing(HashMap &,string* &,int &);
void runAVL(AvlTreeNode *,string* &,int &);
void runBstNode(BstNode *,string* &,int &);






bool fileExists(string filename)
{
    fstream file(filename.c_str());
    if(file.is_open() )
    {
        file.close();
        return true;
    }
    return false;
}




string getFilename()
{
    string defaultFilename = "small-file.txt";
    string inputFilename;
    cout<<"Give the name of the file you want to load"<<endl;
    cout<<"if nothing is given the program will load small-file.txt"<<endl;
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
    cout<<"Started hashing"<<endl<<endl;

    random_device rd;

    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

   /* int inserted=0;
    for(int i = 0; i < wordsInFile; i++)
    {
        if(a.AddElement(wrd[i]))
            inserted++;
        //else
            //cout<<"Failed to insert word "<<wrd[i]<<endl;
    }

    cout<<"Total words inserted "<<inserted<<endl;*/


    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Hashing took : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;


    cout<<"Ended hashing"<<endl<<endl;

}

void runAVL(AvlTreeNode *AVLroot,string* &wrd,int &wordsInFile)
{
    cout<<"Started AVL Tree"<<endl<<endl;

    random_device rd;

    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);


    //cout<<"Creating Avl Tree..."<<endl;
    cout<<"Searching Avl Tree..."<<endl;

    int b;
    for(int i=0;i<5000;i++)
    {
        //AVLroot = AvlInsertion(AVLroot,wrd[i]);
        if(AvlSearch(AVLroot,wrd[i],b))
        {
            cout<<wrd[i]<<","<<b<<"   ";
        }

    }
    //cout<<"AVL Tree has been created!"<<endl;

    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "AVL Tree Took : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;


    cout<<"Ended AVL Tree"<<endl<<endl;

}

void runBstNode(BstNode *BSTroot,string* &wrd,int &wordsInFile)
{
    cout<<"Started Binary Tree"<<endl<<endl;

    //cout<<"Creating Binary Search Tree..."<<endl;

    random_device rd;

    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    int a;
    for(int i=0;i<5000;i++)
    {
        //BSTroot = Insert(BSTroot,wrd[i]);
        if(BstSearch(BSTroot,wrd[i],a))
        {
            cout<<wrd[i]<<","<<a<<"   ";
        }

    }
    //cout<<"Binary Search Tree has been created!"<<endl;*/

    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Binary Tree Took : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;
    cout<<"Ended Binary Tree"<<endl<<endl;

}

#endif
