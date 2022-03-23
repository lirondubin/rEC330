// https://stackoverflow.com/questions/41456245/is-it-possible-to-iterate-through-a-text-file-lines-and-use-stringstream-to-pars

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ifstream testFile("phishing-links-INACTIVE.txt");
    string line;
    vector<int> linkVec;
    int tot_links = 0;
    int link_length = 0;
    int max_length = 0;
    int i = 0;
    int j = 0;
    while (getline(testFile, line))
    {
        tot_links++;
        link_length = line.size();
        if (link_length > max_length)
        {
            max_length = link_length;
        }
    }
    int intArr[tot_links][max_length]; // sizeof(arr)/sizeof(arr[0])

    // for (int i = 0; i < tot_links; i++)
    i = 0;
    testFile.clear();
    testFile.seekg(0, ios::beg);
    while (getline(testFile, line))
    {
        link_length = line.size();
        vector<int> intVec(0, link_length);
        for (int j = 0; j < link_length; j++)
        {
            intArr[i][j] = int(line[j]);
        }
        i++;
    }
}

// // this block prints intArr
// i = 0;
// j = 0;
// testFile.clear();
// testFile.seekg(0, ios::beg);
// while (getline(testFile, line))
// {
//     link_length = line.size();
//     for (int j = 0; j < link_length; j++)
//     {
//         cout << intArr[i][j];
//     }
//     cout << endl;
//     i++;
// }