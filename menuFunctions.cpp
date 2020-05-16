#ifndef MENUFUNCTIONS_H_INCLUDED
#define MENUFUNCTIONS_H_INCLUDED

/*
#include "Hashmap.h"
#include "BstNode.h"
#include "AvlTree.h"*/

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

    int inserted=0;
    for(int i = 0; i < wordsInFile; i++)
    {
        if(a.AddElement(wrd[i]))
            inserted++;
        //else
            //cout<<"Failed to insert word "<<wrd[i]<<endl;
    }

    cout<<"Total words inserted "<<inserted<<endl;


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


    cout<<"Creating Avl Tree..."<<endl;
    for(int i=0;i<wordsInFile;i++)
    {
        AVLroot = AvlInsertion(AVLroot,wrd[i]);

    }
    cout<<"AVL Tree has been created!"<<endl;

    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "AVL Tree Took : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;


    cout<<"Ended AVL Tree"<<endl<<endl;

/*
    preorder(AVLroot); //Gia test kai epalitheush oti to avl insertion leitourgei mono!
    cout<<endl;
    postorder(AVLroot);
    cout<<endl;
    inorder(AVLroot);
    cout<<endl;
*/
    /*std::string searchword4;
    cin>>searchword4;

    if(AvlSearch(AVLroot,searchword4)==true)
        cout<<"The word : "<<searchword4<<" has been successfully Found!"<<endl;
    else
        cout<<"The word : "<<searchword4<<" has NOT been Found!"<<endl;

    std::string searchword5;
    cin>>searchword5;

    AVLdelete(AVLroot,searchword5,0);
    cout<<"The word : "<<searchword5<<" has been DELETED"<<endl;



    std::string searchword6;
    cin>>searchword6;

    if(AvlSearch(AVLroot,searchword6)==true)
        cout<<"The word : "<<searchword6<<" has been successfully Found!"<<endl;
    else
        cout<<"The word : "<<searchword6<<" has NOT been Found!"<<endl;*/

}

void runBstNode(BstNode *BSTroot,string* &wrd,int &wordsInFile)
{
    cout<<"Started Binary Tree"<<endl<<endl;

    cout<<"Creating Binary Search Tree..."<<endl;

    random_device rd;

    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);


    for(int i=0;i<wordsInFile;i++)
    {
        BSTroot = Insert(BSTroot,wrd[i]);

    }
    cout<<"Binary Search Tree has been created!"<<endl;

    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Binary Tree Took : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;
    cout<<"Ended Binary Tree"<<endl<<endl;


/*
    PreOrder(BSTroot);
    cout<<endl;
    InOrder(BSTroot);
    cout<<endl;
    PostOrder(BSTroot);
    cout<<endl;
*/

    /*std::string searchword;
    cin>>searchword;

    if(BstSearch(BSTroot,searchword)==true)
        cout<<"The word : "<<searchword<<" has been successfully Found!"<<endl;
    else
        cout<<"The word : "<<searchword<<" has NOT been Found!"<<endl;


    std::string searchword1;
    cin>>searchword1;

    DeleteEllement(BSTroot,searchword1,0);
    cout<<"The word : "<<searchword1<<" has been DELETED"<<endl;

    std::string searchword3;
    cin>>searchword3;

    if(BstSearch(BSTroot,searchword3)==true)
        cout<<"The word : "<<searchword3<<" has been successfully Found!"<<endl;
    else
        cout<<"The word : "<<searchword3<<" has NOT been Found!"<<endl;*/


}

#endif
