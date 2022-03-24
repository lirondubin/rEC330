// https://stackoverflow.com/questions/41456245/is-it-possible-to-iterate-through-a-text-file-lines-and-use-stringstream-to-pars

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

vector<string> convertLink(string s, ifstream &testFile)
{
    string line;
    vector<string> linksVec_string;
    int tot_links = 0;
    int link_length = 0;
    int max_length = 0;
    while (getline(testFile, line))
    {
        string temp_numString = "";
        int link_length = line.size();
        for (int i = 2; i < link_length + 2; i++)
        {
            int indNum_num = int(line[i]);
            string indNum_str = to_string(indNum_num);
            temp_numString += indNum_str;
                        
            // if (temp_numString[18] == 5 && &temp_numString[i - 1] == "99" && &temp_numString[i] == "111" && &temp_numString == "109") // .com
            // {
            //     cout << "hello" << endl;
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "99" && temp_numString[i] == "99") // .cc
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "116" && temp_numString[i] == "119") // .tw
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "109" && temp_numString[i] == "108") // .ml
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "111" && temp_numString[i] == "114" && temp_numString[i] == "103") // .org
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "101" && temp_numString[i] == "100" && temp_numString[i] == "117") // .edu
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "110" && temp_numString[i] == "101" && temp_numString[i] == "116") // .net
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "112" && temp_numString[i] == "112") // .pp
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "112" && temp_numString[i] == "114" && temp_numString[i] == "111") // .pro
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "115" && temp_numString[i] == "117") // .su
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "98" && temp_numString[i] == "105" && temp_numString[i] == "122") // .biz
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "105" && temp_numString[i] == "116") // .it
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "105" && temp_numString[i] == "111") // .io
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "116" && temp_numString[i] == 111 && temp_numString[i] == 112) // .top
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "103" && temp_numString[i] == "112") // .gp
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "99" && temp_numString[i] == "122") // .cz
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "114" && temp_numString[i] == "117") // .ru
            // {
            //     break;
            // }
            // else if (temp_numString[i - 2] == "46" && temp_numString[i - 1] == "99" && temp_numString[i] == "102") // .cf
            // {
            //     break;
            // }
        }
        linksVec_string.push_back(temp_numString);
    }
    return linksVec_string;
}
// vector<int> string_to_int(vector<string> linksVec_string)
// {
//     vector<int> linksVec_int;
//     for (int i = 0; i < linksVec_string.size(); i++)
//     {
//         int theNum = stoi(linksVec_string[i]);
//         linksVec_int.push_back(theNum);
//     }
//     return linksVec_int;
// }
void print_numVec(int tot_links, vector<string> linksVec)
{
    int i = 0;
    for (i = 0; i < tot_links; i++)
    {
        cout << "[LINK] " << linksVec[i] << endl;
    }
    cout << endl
         << "[INFO] Total Links: " << i << endl;
    return;
}

int main()
{
    ifstream testFile("phishing-links-ACTIVE.txt");
    vector<string> linksVec_string = convertLink("phishing-links-INACTIVE.txt", testFile);
    int tot_links = linksVec_string.size();
    // vector<int> linksVec_int = string_to_int(linksVec_string);
    // print_numVec(tot_links, linksVec_string);

    if (linksVec_string[0] == "0")
    {
        cout << "hello" << endl;
    }

    // cout << linksVec_string[1] << endl;
    // int theNum = stoi(linksVec_string[1]);
    // int val = stoi("123");
    // cout << "val is " << val << endl;
    // unsigned long long int num = 104116116112584747484851575757469999;
    // cout << "[INFO] " <<  num << endl;
    // sscanf(linksVec[1], "%d", &theNum);
    // stringsteam theNum(linksVec[1]);
    return 0;
}