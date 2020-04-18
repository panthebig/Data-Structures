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
        //cout<<"einai mesa"<<endl;
    }
    return root;

}

bool BstSearch(BstNode* root,std::string idata)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data == idata)
    {
        return true;
    }
    else if(root->data > idata)
    {
        return BstSearch(root->left,idata);
    }
    else
        return BstSearch(root->right,idata);
}

BstNode* DeleteEllement(BstNode* root,std::string idata)
{
    if(root == NULL)
    {
        return root;
    }
    else if(root->data > idata)
    {
        root->left = DeleteEllement(root->left,idata);
    }
    else if(root->data < idata)
    {
        root->right = DeleteEllement(root->right,idata);
    }
    else
    {
        if( (root->left==NULL) && (root->right==NULL) ) //To node den exei kanena paidi
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)//Den exei aristero paidi
        {
            struct BstNode *temp = root;//to temp deixnei ekei opou deixnei kai to root
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)//Den exei deksi paidi
        {
            struct BstNode *temp = root;//to temp deixnei ekei opou deixnei kai to root
            root=root->left;
            delete temp;
        }
        else//exei duo paidia
        {
            struct BstNode* temp = FindMin(root->right);
            root->data=temp->data;//to node pou thelw na diagrapsw pairnei tin timi tou elaxistou node tou deksia ypodendrou
            root->right= DeleteEllement(root->right,temp->data);
        }

    }
    return root;
}


BstNode* FindMin(BstNode* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
