#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <ctime>

#include "BinaryTree.h"
#include "HashMap.h"

using namespace std;



int main()
{
    clock_t now = clock();
    string name = "mynameis";
    HashMap a;

    a.AddElement(name);
    a.AddElement("ou ro");
    a.AddElement("ou bro");
    a.AddElement("eh");
    a.AddElement("fg");
    cout<<a.FindElement("asda");
    cout<<a.FindElement("ou bro")<<endl;
    a.print();
    cout<<(float)(clock()-now)/CLOCKS_PER_SEC;
    /*BinaryTree BiTree; //create new tree object in BinaryTree Class


    ifstream infile("inputfile.txt");   //opens the file named inputfile.txt
    std::string linestr;

    while(getline(infile,linestr))
    {
        //use the remove_if to check if there are any punctuation marks in each lane and if there are any , remove them using .erase
        linestr.erase(remove_if(linestr.begin(), linestr.end(), ::ispunct), linestr.end());
        //cout<<linestr<<endl;

        BiTree.CreateBinaryTree(linestr);
    }*/


    return 0;
}
