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
    string line = "http://185.183.98.199/online/CI/b39580e3b5d7e2e988332c23e4f293fb";
    cout << "string: " << line << endl;
    vector<int> intVec(0,0);
    vector<int> arr_vectors[2];
    int length = line.size();
    for (int i = 0; i < length; i++)
    {
        intVec.push_back(line[i]);
    }
    cout << "intVec: " << endl;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
            cout << intVec[i];
    }
    cout << endl;
    // int i = 0;
    // ifstream testFile("phishing-links-INACTIVE.txt");
    // string line;
    // vector<int> linkVec;
    // while(getline(testFile, line)){
    //     int length = line.size();
    //     for(i = 0; i < length; i++){

    //     }
    //     cout << length << endl;
    //     // cout << line[7] << endl;
    //     // linkVec.push_back(int(line));
    //     i++;

    //     // string date;
    //     // int time;
    //     // float amount;

    //     // std::replace(line.begin(), line.end(), ',', ' ');

    //     // stringstream ss(line);

    //     // ss >> date;
    //     // ss >> time;
    //     // ss >> amount;

    //     // cout << "Date: " << date << " ";
    //     // cout << "Time: " << std::setfill('0') << std::setw(4) << time << " ";
    //     // cout << "Amount: " << amount << " ";

    //     // cout << '\n';
    // }
    // cout << "total files: " << i << endl;
}