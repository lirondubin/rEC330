#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <typeinfo>

using namespace std;

int main()
{
    /*Got rid of the std:: in these decalrations for clarity */
    vector<string> A = {"A", "Q", "B", "CDR"};
    vector<string> B = {"Q", "A", "CDR", "B"};

    /* You used brackets [] insteas of parenthesis () here when specifying the size */
    vector<int> Bint(B.size());

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

    cout << endl;
    for (int i = 0; i < B.size(); i++)
    {
        string temp = B[i];
        
        cout << typeid(songMap[temp]).name() << endl;
        cout << "songMap[temp] = " << songMap[temp] << endl;

        /*
         *A general debugging tip - if a line is breaking the code, try to simplify it to see what is breaking it
         *For example, I changed the line  to Bint[0] = 1; just to see if that'd still break it (it did)
         *This was a sign that the declaration was incorrect 
        */
        Bint[i] = songMap.at(temp);
        cout << "Bint[i] = " << Bint[i] << endl;
    }

    //devb@bu.edu


    return 0;
}