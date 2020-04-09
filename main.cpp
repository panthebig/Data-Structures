#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cstring>

#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree BiTree; //create new tree object in BinaryTree Class


    ifstream infile("inputfile.txt");   //opens the file named inputfile.txt
    std::string linestr;

    while(getline(infile,linestr))
    {
        //use the remove_if to check if there are any punctuation marks in each lane and if there are any , remove them using .erase
        linestr.erase(remove_if(linestr.begin(), linestr.end(), ::ispunct), linestr.end());
        //cout<<linestr<<endl;

        BiTree.CreateBinaryTree(linestr);
    }


    return 0;
}
