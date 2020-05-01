#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <vector>


#include "BstNode.h"
//#include "BinaryTree.h"
//#include "Node.h"

using namespace std;

int main()
{
    string *wrd=new string[8000000];
    int m,i;
    //int l;


    //BinaryTree BiTree; //create new tree object in BinaryTree Class


    ifstream infile("test.txt");   //opens the file named inputfile.txt
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

    cout<<"Total words : "<<m<<endl<<endl;

    BstNode *root=NULL;
    //l=0;

    cout<<"Creating Binary Search Tree..."<<endl;
    for(i=0;i<m;i++)
    {
        root = Insert(root,wrd[i]);

    }
    cout<<"Binary Search Tree has been created!"<<endl;


    std::string searchword;
    cin>>searchword;

    if(BstSearch(root,searchword)==true)
        cout<<"The word : "<<searchword<<" has been successfully Found!"<<endl;
    else
        cout<<"The word : "<<searchword<<" has NOT been Found!"<<endl;


    std::string searchword1;
    cin>>searchword1;

    DeleteEllement(root,searchword1,0);
    cout<<"The word : "<<searchword1<<" has been DELETED"<<endl;

    std::string searchword3;
    cin>>searchword3;

    if(BstSearch(root,searchword3)==true)
        cout<<"The word : "<<searchword3<<" has been successfully Found!"<<endl;
    else
        cout<<"The word : "<<searchword3<<" has NOT been Found!"<<endl;

    return 0;
}
