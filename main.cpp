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
    string wrd[1000];
    string word="";
    int m,i;

    BinaryTree BiTree; //create new tree object in BinaryTree Class


    ifstream infile("inputfile.txt");   //opens the file named inputfile.txt
    std::string linestr;

    m=0;

    while(getline(infile,linestr))
    {
        //use the remove_if to check if there are any punctuation marks in each lane and if there are any , remove them using .erase
        linestr.erase(remove_if(linestr.begin(), linestr.end(), ::ispunct), linestr.end());

        /*for(i=0;i<=strlen(linestr.c_str());i++)   //allos tropos pou skeftika monos gia thn aferesh...
        {
            if(std::ispunct(linestr[i]))
                linestr[i]=' ';
        }*/



        if(!(linestr.empty()))//if the line is not empty ,then and only then will the program try to saperate the words.
        {


            word="";//clears/resets string

            for(i=0;i<=strlen(linestr.c_str());i++) //m shows the row
            {
                if(linestr[i]!='\t')//checking for tabs
                {

                    if(linestr[i]!=' ')
                    {
                        word=word+linestr[i];
                    }
                    else
                    {
                        wrd[m]=word;
                        m++;
                        word="";
                    }

                }
            }
            wrd[m]=word;
            m++;

        }
    }




    for(i=0;i<=m;i++)
    {
        if((!wrd[i].empty()))//words with 0 length will not be eligible for any data stracture!
            cout<<wrd[i]<<endl; //edo tha bei to BiTree.CreateBinaryTree(wrd[i]);
    }



    return 0;
}
