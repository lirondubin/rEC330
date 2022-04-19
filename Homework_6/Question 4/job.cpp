// https://www.codespeedy.com/cycle-detection-in-a-directed-graph-in-cpp/

#include "job.h"
#include <vector>
#include <iterator>
#include <list>
#include <iostream>
#include <set>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

set<int> white; // white container
set<int> grey;  // grey container
set<int> black; // black container
int flag = 0;

// void edge(vector<int> adj[], int n, int v);
void CycleDetect(int n, vector<int> adj[]);
bool canFinish(int n, vector<pair<int, int>> &dependencies);

// void edge(vector<int> adj[], int n, int v)
// {
//     adj[n].push_back(v);
// }

// function to detect the cycle in graph
// void CycleDetect(int n, vector<int> adj[])
// {
//     white.erase(n); // remove from the white set
//     grey.insert(n); // put into the grey set

//     // cout << "[INFO] adj[n].size() = " << sizeof(adj)/sizeof(arr[0])<< endl;
//     // for (int i = 0; i < adj[n].size(); i++)
//     // {
//     // cout << "[INFO] adj[i][0] = " << adj[i][0] << endl;
//     // cout << "[INFO] adj[i][1] = " << adj[i][1] << endl << endl;
//     // if (white.find(adj[n][i]) != white.end())
//     // {
//     //     CycleDetect(adj[n][i], adj);
//     // }
//     // if (grey.find(adj[n][i]) != grey.end())
//     // { // check if its is present or not in grey set
//     //     flag = 1;
//     // }
//     // }
//     black.insert(n); // put into the black set
//     grey.erase(n);   // remove from the grey set
// }

bool canFinish(int n, vector<pair<int, int>> &dependencies)
{
    vector<int> adj[dependencies.size()]; // vector of array to store the graph

    for (int i = 0; i < sizeof(adj) / sizeof(vector<int>); i++)
    {
        // edge(adj, dependencies[i].first, dependencies[i].second);
        adj[dependencies[i].first].push_back(dependencies[i].second);
    }
    for (int i = 0; i < sizeof(adj) / sizeof(vector<int>); i++)
    {
        white.insert(i);
    }

    cout << "[INFO] adj[n].size() = " << sizeof(adj) / sizeof(vector<int>) << endl;
    // cout << "[INFO] adj[n].size() = " << *(&adj + 1) - adj << endl;

    // CycleDetect(n, adj);

    if (flag == 0)
    {
        cout << "Graph DOES NOT contain a cycle" << endl;
        return true;
    }
    else
    {
        cout << "Graph DOES contain a cycle" << endl;
        return false;
    }
    return 0;
}

int main()
{
    // vector<pair<int, int>> line = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9},{9,10)}};
    // canFinish(10, line); // expect true

    // vector<pair<int, int>> star1 = {{10,2},{10,2},{10,3},{10,4},{10,5},{10,6},{10,7},{10,8},{10,9}};
    // canFinish(10, star1); // expect true

    // vector<pair<int, int>> star2 = {{1, 10}, {2, 10}, {3, 10}, {4, 10}, {5, 10}, {6, 10}, {7, 10}, {8, 10}, {9, 10}};
    // canFinish(10, star2); // expect true

    vector<pair<int, int>> ShortLoop = {{1, 2}, {2, 3}, {3, 1}};
    canFinish(3, ShortLoop); // expect false

    // vector<pair<int, int>> small = {{1, 2}, {2, 3}};
    // canFinish(2, small); // expect true

    // vector<pair<int, int>> dependencies = {{1, 2}};

    // canFinish(2, dependencies);

    return 0;
}