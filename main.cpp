#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <vector>

#include "BinaryTree.h"
//#include "Node.h"

using namespace std;
int l;
int all;

struct BstNode
{
    std::string data;
    BstNode *left;
    BstNode *right;
};

BstNode* GetNewNode(std::string idata)
{
    BstNode* newNode=new BstNode();
    newNode->data=idata;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

BstNode* Insert(BstNode* root,std::string data)
{
    if(root==NULL)
    {
        root=GetNewNode(data);
        //cout<<data<<": -inserted"<<endl;
        //return root;
        l++;
    }
    else if(data < root->data)
    {
        root->left=Insert(root->left,data);
        //return root;
    }
    else if(data > root->data)
    {
        root->right=Insert(root->right,data);
        //return root;
    }
    else
    {
    }
    return root;

}


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

    cout<<"Total words : "<<m<<endl;

    BstNode *root=NULL;
    l=0;

    cout<<"Creating tree..."<<endl;
    for(i=0;i<m;i++)
    {
        root = Insert(root,wrd[i]);
    }
    cout<<"Tree has been created with "<<l<<" different words"<<endl;



    return 0;
}
