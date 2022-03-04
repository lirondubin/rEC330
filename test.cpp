#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
    std::vector<std::string> A = {"A", "Q", "B", "CDR"};
    std::vector<std::string> B = {"Q", "A", "CDR", "B"};
    vector<int> Bint[B.size()];
    // std::vector<int> Bint[];
    map<string, int> songMap;
    for (int i = 0; i < A.size(); i++)
    {
        songMap.insert(pair<string, int>(A[i], i + 1));
    }

    map<string, int>::iterator itr;
    cout << "\nThe map songMap is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = songMap.begin(); itr != songMap.end(); ++itr)
    {
        cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }

    // cout << typeid(songMap[B[2]]).name() << endl;
    //(St6vectorIiSaIiEE)songMap[B[2]];
    // cout << typeid(songMap[B[2]]).name() << endl;

    cout << typeid(Bint[2]).name() << endl;

    cout << endl;
    for (int i = 0; i < B.size(); i++)
    {
        string temp = B[i];
        // cout << temp << endl;
        // cout << typeid(songMap[A[i]]).name() << endl;
        // cout << typeid(songMap[temp]).name() << endl;
        // cout << "songMap[temp] = " << songMap[temp] << endl;
        // Bint[i] = songMap[temp];
        //  cout << "Bint[i] = " << Bint[i] << endl;
    }
    // map<string, int>

    // devb@bu.edu

    /*
     std::vector<int> Aint;
     for (int i = 0; i < A.size(); i++)
     {
         cout << "A[i] = " << A[i] << endl;
     }
     for (int i = 1; i <= A.size(); i++)
     {
         i;
         makeVariable("convert ascii val", A[i]);
         cout << "Aint[i] = " << A[i] << endl;
     }
 */
    return 0;
}

/*
1) convert string to a int variable
2) assign a num to each int variable


*/