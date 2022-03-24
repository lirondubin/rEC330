// https://stackoverflow.com/questions/41456245/is-it-possible-to-iterate-through-a-text-file-lines-and-use-stringstream-to-pars

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main()
{
    ifstream testFile("phishing-links-INACTIVE.txt");
    string line;
    vector<string> linksVec;
    int tot_links = 0;
    int link_length = 0;
    int max_length = 0;
    while (getline(testFile, line))
    {
        string temp_numString = "";
        int link_length = line.size();
        for(int i = 0; i < link_length; i++){
            int indNum_num = int(line[i]);
            string indNum_str = to_string(indNum_num);
            temp_numString += indNum_str;
        }
        linksVec.push_back(temp_numString);
    }
    tot_links = linksVec.size();
    for (int i = 0; i < tot_links; i++){
        cout << "[LINK] " << linksVec[i] << endl;
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