#include "AvlTree.h"

#include <iostream>
using namespace std;


AvlTreeNode *AVLnewNode(std::string word)
{
    AvlTreeNode* newAVLNode=new AvlTreeNode();
    newAVLNode->data=word;
    newAVLNode->left=NULL;
    newAVLNode->right=NULL;
    newAVLNode->n=1;
    newAVLNode->height=1;
    return newAVLNode;
}

int getHeight(AvlTreeNode *root)
{
    if(root==NULL)
        return 0; //if the root is a leaf, then it's height is 0
    else
        return root->height;
}

int HeightDiff(AvlTreeNode *root)
{
    if(root==NULL)
        return 0; // root is a leaf
    else
        return (getHeight(root->left) - getHeight(root->right));
}

int MaxOfTwoHeights(int X,int Y)
{
    if(X>Y)
        return X;
    else
        return Y;
}

AvlTreeNode *RightRot(AvlTreeNode *grandp)//grandp = grandparent node (named for easier understanding)
{
    AvlTreeNode *temp = grandp->left;
    grandp->left = temp->right;
    temp->right=grandp;

    // >updating the heights of both the grandp node and the temp node
    grandp->height = MaxOfTwoHeights(getHeight(grandp->left),getHeight(grandp->right))+1; // +1 is for the node itself
    temp->height = MaxOfTwoHeights(getHeight(temp->left),getHeight(temp->right))+1; //+1 is for the node itself

    return temp;
}

AvlTreeNode *LeftRot(AvlTreeNode *grandp)// >grandp = grandparent node (named for easier understanding)
{
    AvlTreeNode *temp=grandp->right;
    grandp->right=temp->left;
    temp->left=grandp;

    grandp->height=MaxOfTwoHeights(getHeight(grandp->left),getHeight(grandp->right))+1;
    temp->height=MaxOfTwoHeights(getHeight(temp->left),getHeight(temp->right))+1;

    return temp;
}

AvlTreeNode *AvlInsertion(AvlTreeNode *root,std::string word)
{
    if(root==NULL)
    {
        root=AVLnewNode(word);
    }
    else if(word < root->data)
    {
        root->left=AvlInsertion(root->left,word);
    }
    else if(word > root->data)
    {
        root->right=AvlInsertion(root->right,word);
    }
    else
    {
        root->n++;
    }

    root->height=MaxOfTwoHeights(getHeight(root->left),getHeight(root->right))+1; //Calculates the height of the node "root"

    int diff;
    diff=HeightDiff(root);

    //double left rotation needed Case
    if (diff > 1 && word < root->left->data)
        return RightRot(root);

    //double Right rotation needed Case
    if (diff < -1 && word > root->right->data)
        return LeftRot(root);

    // Left Right rotation needed Case
    if (diff > 1 && word > root->left->data)
    {
        root->left = LeftRot(root->left);
        return RightRot(root);
    }

    // Right Left rotation needed Case
    if (diff < -1 && word < root->right->data)
    {
        root->right = RightRot(root->right);
        return LeftRot(root);
    }

    return root;

}

void preorder(AvlTreeNode *root)
{
if(root != NULL)
    {
        cout << root->data<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}
