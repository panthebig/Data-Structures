#include "AvlTree.h"

#include <iostream>
#include <fstream>
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

bool AvlSearch(AvlTreeNode *root,std::string word , int  &counter)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data == word)
    {
        counter=root->n;
        //cout<<root->n<<endl;
        return true;
    }
    else if(root->data > word)
    {
        return AvlSearch(root->left,word,counter);
    }
    else
        return AvlSearch(root->right,word,counter);
}

AvlTreeNode *AvlSearchNode(AvlTreeNode *root,std::string word)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->data == word)
    {
        cout<<root->n<<endl;
        return root;
    }
    else if(root->data > word)
    {
        return AvlSearchNode(root->left,word);
    }
    else
        return AvlSearchNode(root->right,word);
}

AvlTreeNode *AVLdelete(AvlTreeNode *root,std::string word,int i)
{
    struct AvlTreeNode* temp;
    if(i==0) //checks one time how many times idata is in the text
    {
        temp=AvlSearchNode(root,word);
        i++;
    }

    if(temp->n>=2)
    {
        cout<<"Before :  "<<temp->n<<endl;
        temp->n--;
        cout<<"after :  "<<temp->n<<endl;
        return root;
    }
    else
    {
        if(root == NULL)
        {
            return root;
        }
        else if(root->data > word)
        {
            root->left = AVLdelete(root->left,word,i);
        }
        else if(root->data < word)
        {
            root->right = AVLdelete(root->right,word,i);
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
                struct AvlTreeNode *temp2 = root;//to temp deixnei ekei opou deixnei kai to root
                root=root->right;
                delete temp2;
            }
            else if(root->right==NULL)//Den exei deksi paidi
            {
                struct AvlTreeNode *temp2 = root;//to temp deixnei ekei opou deixnei kai to root
                root=root->left;
                delete temp2;
            }
            else//exei duo paidia
            {
                struct AvlTreeNode* temp2 = AVLFindMIN(root->right);
                root->data=temp2->data;//to node pou thelw na diagrapsw pairnei tin timi tou elaxistou node tou deksia ypodendrou
                root->right= AVLdelete(root->right,temp2->data,i);
            }

            //checks if rotation is needed
            //if the avl is not balanced, then the needed rotation will take place,balancing the tree

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

        }

        return root;
    }
}

AvlTreeNode *AVLFindMIN(AvlTreeNode *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

void preorder(AvlTreeNode *root)
{
    if(root != NULL)
    {
        cout << root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(AvlTreeNode *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data<<" , ";
    }
}

void inorder(AvlTreeNode *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data<<" , ";
        inorder(root->right);
    }
}
