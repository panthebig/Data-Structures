#ifndef BSTNODE_H_INCLUDED
#define BSTNODE_H_INCLUDED

#include <iostream>


using namespace std;




struct BstNode
{
    std::string data;
    BstNode *left;
    BstNode *right;
    int counter;
};

BstNode* GetNewNode(std::string idata); //creates a new node, which will be later added in the BS tree

BstNode* Insert(BstNode* root,std::string data); //adds a node in the BS tree, in the correct place

bool BstSearch(BstNode* root,std::string data); //returns whether or not the word has been found

BstNode* DeleteEllement(BstNode* root,std::string data,int); //deletes an element/node from the BS tree

BstNode* FindMin(BstNode* root); //finds min of a tree/subtree

BstNode* BstSearchNode(BstNode* root,std::string data); //returns the node's adress in which belongs the word

#endif // BSTNODE_H_INCLUDED
