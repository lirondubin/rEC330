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

    string yeet = "phishing-links-INACTIVE.txt";
    int string_length = yeet.size();
    string temp_numString = "";
    for(int i = 0; i < string_length; i++){
        int indNum_num = int(yeet[i]);
        string indNum_str = to_string(indNum_num);
        temp_numString += indNum_str;
    }
    cout << temp_numString << endl;

    // ifstream testFile("phishing-links-INACTIVE.txt");
    // string line;
    // vector<int> linkVec;
    // int tot_links = 0;
    // int link_length = 0;
    // int max_length = 0;
    // int i = 0;
    // int j = 0;
    // while (getline(testFile, line))
    // {
    //     tot_links++;
    //     link_length = line.size();
    //     if (link_length > max_length)
    //     {
    //         max_length = link_length;
    //     }
    // }
    // int intArr[tot_links][max_length]; // sizeof(arr)/sizeof(arr[0])

    // i = 0;
    // testFile.clear();
    // testFile.seekg(0, ios::beg);
    // while (getline(testFile, line))
    // {
    //     link_length = line.size();
    //     vector<int> intVec(0, link_length);
    //     for (int j = 0; j < link_length; j++)
    //     {
    //         intArr[i][j] = int(line[j]);
    //     }
    //     i++;
    // }
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