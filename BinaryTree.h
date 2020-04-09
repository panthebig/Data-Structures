#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;


class BinaryTree
{
    public:
        BinaryTree();
        char BiTree[10000];
        int NUM[10000];

        struct treenode
        {
            string info;
            struct treenode *left;
            struct treenode *right;
        }root;
        treenode a;

         // number of times a word has been read until now

        void CreateBinaryTree(std::string line); // Creates the binary Tree by accepting one line each time


    protected:

    private:
};

#endif // BINARYTREE_H
