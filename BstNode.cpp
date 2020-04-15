#include <iostream>
#include "BstNode.h"

using namespace std;






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
