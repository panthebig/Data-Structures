#include "menuFunctions.h"
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;


bool fileExists(string filename)
{
    fstream file(filename.c_str());
    if(file.is_open() )
    {
        file.close();
        return true;
    }
    return false;
}




string getFilename()
{
    string defaultFilename = "small-file.txt";
    string inputFilename;
    cout<<"Give the name of the file you want to load"<<endl;
    cout<<"if nothing is given the program will load small-file.txt"<<endl;
    getline(cin,inputFilename);

    if(inputFilename.empty())
    {
        return defaultFilename;

    }
    else
    {
        if(fileExists(inputFilename))
            return inputFilename;
        else
        {
            cout<<"The file cant be found default will be loaded"<<endl;
            return defaultFilename;
        }
    }
}



void runHashing(HashMap &a,string* &wrd,int &wordsInFile)
{
    cout<<"Started hashing"<<endl<<endl;


    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    int inserted=0;
    for(int i = 0; i < wordsInFile; i++)
    {
        if(a.AddElement(wrd[i]))
            inserted++;
        //else
            //cout<<"Failed to insert word "<<wrd[i]<<endl;
    }

    cout<<"Total words inserted "<<inserted<<endl;


    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Hashing took : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;


    cout<<"Ended hashing"<<endl<<endl;

}

void runAVL(AvlTreeNode *AVLroot,string* &wrd,int &wordsInFile)
{
    cout<<"Started AVL Tree"<<endl<<endl;


    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);


    cout<<"Creating Avl Tree..."<<endl;
    for(int i=0;i<wordsInFile;i++)
    {
        AVLroot = AvlInsertion(AVLroot,wrd[i]);

    }
    cout<<"AVL Tree has been created!"<<endl;

    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "AVL Tree Took : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;


    cout<<"Ended AVL Tree"<<endl<<endl;


}

void runBstNode(BstNode *BSTroot,string* &wrd,int &wordsInFile)
{
    cout<<"Started Binary Tree"<<endl<<endl;

    cout<<"Creating Binary Search Tree..."<<endl;


    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);


    for(int i=0;i<wordsInFile;i++)
    {
        BSTroot = Insert(BSTroot,wrd[i]);

    }
    cout<<"Binary Search Tree has been created!"<<endl;

    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Binary Tree Took : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;
    cout<<"Ended Binary Tree"<<endl<<endl;


}

void searchRandom(HashMap &a,BstNode *BSTroot,AvlTreeNode *AVLroot,int randomWordsIndex,string* & randomWords)
{
    int hashfound = 0;
    int bstfound = 0;
    int avlfound = 0;
    int counter = 0;





    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    ofstream outfile("Output.txt");//, std::ios_base::app);

    for(int i=0;i<randomWordsIndex;i++)
    {
        if(addin(randomWords[i]) < 0)
            continue;
        if(BstSearch(BSTroot,randomWords[i],counter))
        {
            outfile<<"Binary:"<<randomWords[i]<<" "<<counter<<endl;

            bstfound++;
        }
    }



    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_takenBin = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_takenBin *= 1e-9;

    cout << "Binary Tree Search Took : " << fixed
         << time_takenBin ;//<< setprecision(9);
    cout << " sec" << endl;
    outfile<<endl<<endl<<endl;
    outfile << "Binary Tree Search Took : " << fixed
         << time_takenBin ;//<< setprecision(9);
    outfile << " sec" << endl;
    outfile<<endl<<endl<<endl;



    start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);


    for(int i=0;i<randomWordsIndex;i++)
    {
        if(addin(randomWords[i]) < 0)
            continue;
        if(AvlSearch(AVLroot,randomWords[i],counter))
        {
            outfile<<"Avl:"<<randomWords[i]<<" "<<counter<<endl;

            avlfound++;
        }
    }


    end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_takenAVL = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_takenAVL *= 1e-9;

    cout << "AVL Tree Search Took : " << fixed
         << time_takenAVL ;//<< setprecision(9);
    cout << " sec" << endl;
    outfile<<endl<<endl<<endl;
    outfile << "AVL Tree Search Took : " << fixed
         << time_takenAVL ;//<< setprecision(9);
    outfile << " sec" << endl;
    outfile<<endl<<endl<<endl;


    start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);


    for(int i=0;i<randomWordsIndex;i++)
    {
        if(addin(randomWords[i]) < 0)
            continue;
        if(a.FindElement(randomWords[i],counter))
        {
            outfile<<"Hash:"<<randomWords[i]<<" "<<counter<<endl;
            hashfound++;
        }
    }



    end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    double time_takenHash = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_takenHash *= 1e-9;

    cout << "Hash Search Took : " << fixed
         << time_takenHash;// << setprecision(9);
    cout << " sec" << endl;
    outfile<<endl<<endl<<endl;
    outfile << "Hash Search Took : " << fixed
         << time_takenHash;// << setprecision(9);
    outfile << " sec" << endl;

    outfile << endl << hashfound << " "<<bstfound<< " "<<avlfound<<endl;

    outfile.close();
}

