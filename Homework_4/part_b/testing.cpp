// https://stackoverflow.com/questions/41456245/is-it-possible-to-iterate-through-a-text-file-lines-and-use-stringstream-to-pars

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

vector<string> convertLink(string s, ifstream &testFile)
{
    string line;
    vector<string> linksVec;
    int tot_links = 0;
    int link_length = 0;
    int max_length = 0;
    while (getline(testFile, line))
    {
        string temp_numString = "";
        int link_length = line.size();
        for (int i = 0; i < link_length; i++)
        {
            int indNum_num = int(line[i]);
            string indNum_str = to_string(indNum_num);
            temp_numString += indNum_str;
        }
        linksVec.push_back(temp_numString);
    }
    return linksVec;
}
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
    ifstream testFile("phishing-links-INACTIVE.txt");
    vector<string> linksVec = convertLink("phishing-links-INACTIVE.txt", testFile);
    int tot_links = linksVec.size();
    print_numVec(tot_links, linksVec);
    return 0;
}