#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
using namespace std;

struct AvlTreeNode
{
    std::string data;
    AvlTreeNode *right;
    AvlTreeNode *left;
    int n; //counter for same words
    int height; //height
};

AvlTreeNode *AVLnewNode(std::string word); //Creates new node

int getHeight(AvlTreeNode *);

int MaxOfTwoHeights(int,int); // Used to get the max height of the two subtrees heights

int HeightDiff(AvlTreeNode *);// finds the difference between the two subtrees of a node

AvlTreeNode *RightRot(AvlTreeNode *); //performs a right rotation

AvlTreeNode *LeftRot(AvlTreeNode *); //performs a left rotation

AvlTreeNode *AvlInsertion(AvlTreeNode *,std::string word);//inserts a new element in the Avl Tree

void preorder(AvlTreeNode *);

bool AvlSearch(AvlTreeNode *,std::string word);//returns weather or not a word has been found

AvlTreeNode *AvlSearchNode(AvlTreeNode *,std::string word);//returns the node at which the node has been found

AvlTreeNode *AVLdelete(AvlTreeNode *,std::string word,int);//deletes-subtracts a word from the AVL tree

AvlTreeNode *AVLFindMIN(AvlTreeNode *);

#endif // AVLTREE_H
