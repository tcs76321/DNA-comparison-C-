#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Welcome to the 23andme DNA comparator." << endl << endl;
    ifstream fileA ("PersonA.txt");
    ifstream fileB ("PersonA2.txt");

    string strA;
    string strB;

    float dataComps = 0.0;
    float dataShared = 0.0;

    if (!(fileA.is_open())){
        cout << "fileA not open!" << endl;
        return 0;
    }
    if (!(fileB.is_open())){
        cout << "fileB not open!" << endl;
        return 0;
    }
    cout << "Files are open!" << endl << endl;

    cout << "Beginning computations..." << endl;

    fileA >> strA;
    fileB >> strB;


    cout << strA << " and " << strB << endl;


/*
    if(strA.compare(strB) == 0){
        fileA >> strA;
        fileB >> strB;
        fileA >> strA;
        fileB >> strB;
        fileA >> strA;
        fileB >> strB;//compare DNA
        if(strA.compare(strB) == 0){
            dataComps += 1;
            dataShared += 1;
        }else{
            dataComps += 1;
        }
    }
*/


/*

    while(!(fileA.eof())){
        reItB:
        //cout << "Comparing " << strA << " and " << strB << endl;
        while((strA.compare(strB) != 0) && !(fileB.eof())){
            fileB >> strB;
            fileB >> strB;
            fileB >> strB;
            fileB >> strB;
            //cout << "Comparing " << strA << " and " << strB << endl;
        }
        if(fileB.eof()){
            fileB.close();
            ifstream fileB ("PersonB.txt");
            fileB >> strB;
            fileA >> strA;
            fileA >> strA;
            fileA >> strA;
            fileA >> strA;
            if(fileA.eof()){
                goto donePoint;
            }
            goto reItB;
        }
        if(strA.compare(strB) == 0){
            //cout << "Comparing " << strA << " and " << strB << endl;
            fileA >> strA;
            fileB >> strB;
            fileA >> strA;
            fileB >> strB;
            fileA >> strA;
            fileB >> strB;//compare DNA
           // cout << "With " << strA << " and " << strB << endl;

            if(strA.compare(strB) == 0){
                dataComps += 1;
                dataShared += 1;
            }else{
                dataComps += 1;
            }
            fileA >> strA;
            fileB >> strB;
        }
        fileA >> strA;
        fileA >> strA;
        fileA >> strA;
        fileA >> strA;
    }


donePoint:
    */

    cout << endl <<"Done!" << endl << endl;

    float percShared = dataShared / dataComps;

    cout << "Here is number of compared data points " << dataComps << endl << endl;

    cout << "Here is number of shared data points " << dataShared << endl << endl;

    cout << "These two files share " << percShared*100 << " percent of data points" << endl;



    fileA.close();
    fileB.close();

    return 0;
}
