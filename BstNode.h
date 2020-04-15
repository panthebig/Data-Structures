#ifndef BSTNODE_H_INCLUDED
#define BSTNODE_H_INCLUDED

#include <iostream>


using namespace std;



struct BstNode
{
    std::string data;
    BstNode *left;
    BstNode *right;
};

BstNode* GetNewNode(std::string idata);

BstNode* Insert(BstNode* root,std::string data);

#endif // BSTNODE_H_INCLUDED
