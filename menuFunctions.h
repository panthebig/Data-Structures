#ifndef MENUFUNCTIONS_H_INCLUDED
#define MENUFUNCTIONS_H_INCLUDED


#include "Hashmap.h"
#include "BstNode.h"
#include "AvlTree.h"
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;

bool fileExists(string);
string getFilename();
void runHashing(HashMap &,string* &,int &);
void runAVL(AvlTreeNode *,string* &,int &);
void runBstNode(BstNode *,string* &,int &);
void searchRandom(HashMap &,BstNode *,AvlTreeNode *,int, string*&);


#endif // MENUFUNCTIONS_H_INCLUDED
