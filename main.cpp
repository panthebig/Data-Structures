#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>

#include <chrono>
#include <bits/stdc++.h>



#include "HashMap.h"

using namespace std;


int main()
{
    auto start = chrono::high_resolution_clock::now();

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    string *wrd=new string[1000];
    int m,i;


    ifstream infile("inputfile.txt");   //opens the file named inputfile.txt
    std::string linestr;

    m=0;
    while( infile >> linestr && m<1000)
    {
            linestr.erase(remove_if(linestr.begin(), linestr.end(), ::ispunct), linestr.end());
            wrd[m]=linestr;
            m++;
    }



    HashMap a;

    for(i=0 ;i<m;i++)
        a.AddElement(wrd[i]);

    a.print();

    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;

    return 0;
}
