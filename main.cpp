#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>


using namespace std;


int main()
{
    cout << "Welcome to the 23andme DNA comparator." << endl << endl;
    ifstream fileA ("PersonA.txt");
    ifstream fileB ("PersonB.txt");

    string strA;
    string strB;

    map<string, string> m;



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

    while(!(fileA.eof())){
        string a1 = strA;
        fileA >> strA;
        fileA >> strA;
        fileA >> strA;
        string a2 = strA;
        //cout << a1 << " and " << a2 << endl;
        m.insert(pair<string, string>(a1, a2));
        fileA >> strA;
    }



    fileB >> strB;

    std::map<string, string>::iterator it;

    while(!(fileB.eof())){
        it = m.find(strB);
        if(it != m.end()){
            dataComps += 1;
            string copyStr = strB;
            fileB >> strB;
            fileB >> strB;
            fileB >> strB;
            if( strB == m.at(copyStr)){
                dataShared += 1;
            }
            fileB >> strB;
        }else{
            fileB >> strB;
            fileB >> strB;
            fileB >> strB;
            fileB >> strB;
        }

    }


    cout << endl <<"Done!" << endl << endl;

    float percShared = dataShared / dataComps;

    cout << "Here is number of compared data points " << dataComps << endl << endl;

    cout << "Here is number of shared data points " << dataShared << endl << endl;

    cout << "These two files share " << percShared*100 << " percent of data points" << endl;



    fileA.close();
    fileB.close();


    return 0;
}
