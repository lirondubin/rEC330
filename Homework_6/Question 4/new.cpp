#include <iostream>
#include <bits/stdc++.h>
using namespace std;
set<int> white; // white container
set<int> grey;  // grey container
set<int> black; // black container
int flag = 0;

void edge(vector<int> adj[], int n, int v);
void CycleDetect(int n, vector<int> adj[]);
bool canFinish(int n, vector<pair<int, int>> &dependencies);

void edge(vector<int> adj[], int n, int v)
{
    adj[n].push_back(v);
}

// function to detect the cycle in graph
void CycleDetect(int n, vector<int> adj[])
{
    white.erase(n); // remove from the white set
    grey.insert(n); // put into the grey set
    for (int i = 0; i < adj[n].size(); i++)
    {
        if (white.find(adj[n][i]) != white.end())
        {
            CycleDetect(adj[n][i], adj);
        }
        if (grey.find(adj[n][i]) != grey.end())
        { // check if its is present or not in grey set
            flag = 1;
        }
    }
    black.insert(n); // put into the black set
    grey.erase(n);   // remove from the grey set
}


int main()
{
    vector<pair<int, int>> dependencies = {{1, 2}, {2, 3}, {3, 1}};
    vector<int> adj[dependencies.size() + 1]; // vector of array to store the graph

    for (int i = 0; i < dependencies.size(); i++)
    {
        edge(adj, dependencies[i].first, dependencies[i].second);
        white.insert(i);
    }
    // for (int i = 0; i < ; i++)
    // {
    //     white.insert(i);
    // }
    CycleDetect(3, adj);
    if (flag == 0)
        cout << "Graph does not contain cycle" << endl;
    else
        cout << "Graph contain cycle" << endl;
    return 0;
}