#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    std::vector<std::string> A = {"A", "Q", "B", "CDR"};
    std::vector<std::string> B = {"Q", "A", "CDR", "B"};
    std::vector<int> Bint = {0 0 0 0}
    // std::vector<int> Bint[];
    map<string, int> songMap;
    for (int i = 0; i < A.size(); i++)
    {
        songMap.insert(pair<string, int>(A[i], i+1));
    }

    map<string, int>::iterator itr;
    cout << "\nThe map songMap is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = songMap.begin(); itr != songMap.end(); ++itr)
    {
        cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }

    cout << endl;
    for (itr2 = songMap.begin(); itr2 != songMap.end(); ++itr)
    {
        cout << '\t' << itr2->first << '\t' << itr2->second << '\n';
    }
    // map<string, int>
    

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