#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cstring>



#include "BstNode.h"
#include "AvlTree.h"

using namespace std;

int main()
{
    string *wrd=new string[8000000];
    int m,i;


    ifstream infile("test.txt");   //opens the file named inputfile.txt
    std::string linestr;


    m=0;
    while( infile >> linestr)
    {
            linestr.erase(remove_if(linestr.begin(), linestr.end(), ::ispunct), linestr.end());
            wrd[m]=linestr;
            m++;

    }

    cout<<"Total words : "<<m<<endl<<endl;

    //BS Tree

    BstNode *BSTroot=NULL;
    //l=0;

    cout<<"Creating Binary Search Tree..."<<endl;
    for(i=0;i<m;i++)
    {
        BSTroot = Insert(BSTroot,wrd[i]);

    }
    cout<<"Binary Search Tree has been created!"<<endl;
/*
    PreOrder(BSTroot);
    cout<<endl;
    InOrder(BSTroot);
    cout<<endl;
    PostOrder(BSTroot);
    cout<<endl;
*/

    std::string searchword;
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
        cout<<"The word : "<<searchword3<<" has NOT been Found!"<<endl;



    //AVL TREE

    AvlTreeNode *AVLroot=NULL;

    cout<<"Creating Avl Tree..."<<endl;
    for(i=0;i<m;i++)
    {
        AVLroot = AvlInsertion(AVLroot,wrd[i]);

    }
    cout<<"AVL Tree has been created!"<<endl;
/*
    preorder(AVLroot); //Gia test kai epalitheush oti to avl insertion leitourgei mono!
    cout<<endl;
    postorder(AVLroot);
    cout<<endl;
    inorder(AVLroot);
    cout<<endl;
*/
    std::string searchword4;
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
        cout<<"The word : "<<searchword6<<" has NOT been Found!"<<endl;

    return 0;
}
