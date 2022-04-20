// https://www.codespeedy.com/cycle-detection-in-a-directed-graph-in-cpp/

#include "job.h"
#include <vector>
#include <iterator>
#include <list>
#include <iostream>
#include <set>
#include <utility>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

set<int> white; // white container
set<int> grey;  // grey container
set<int> black; // black container
int flag = 0;
int flag1 = 0;

void CycleDetect(int n, vector<int> adj[]);
bool canFinish(int n, vector<pair<int, int>> &dependencies);

// function to detect the cycle in graph
void CycleDetect(int n, vector<int> adj[])
{
    white.erase(n); // remove from the white set
    grey.insert(n); // put into the grey set

    // cout << "[INFO] adj[n].size() = " << sizeof(adj)/sizeof(arr[0])<< endl;
    for (int i = 0; i < adj[n].size(); i++)
    {
        // cout << "[INFO] adj[i][0] = " << adj[i][0] << endl;
        // cout << "[INFO] adj[i][1] = " << adj[i][1] << endl << endl;
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

bool canFinish(int n, vector<pair<int, int>> &dependencies)
{
    vector<int> adj[n + 1]; // array of vectors to store the graph

    // cout << "[INFO] adj[n].size() = " << sizeof(adj) / sizeof(vector<int>) << endl;
    // cout << "[INFO] dependencies.size() = " << dependencies.size() << endl;
    for (int i = 0; i < dependencies.size(); i++)
    {
        adj[dependencies[i].first].push_back(dependencies[i].second);
    }
    for (int i = 1; i < n; i++)
    {
        white.insert(i);
    }
    // cout << "[INFO] white.size() = " << white.size() << endl;
    // cout << "[INFO] adj[n].size() = " << *(&adj + 1) - adj << endl;

    CycleDetect(n, adj);

    if (flag == 0)
    {
        cout << " TRUE - Graph DOES NOT contain a cycle" << endl;
        return true;
    }
    else
    {
        cout << " FALSE - Graph DOES contain a cycle" << endl;
        return false;
    }
    return 0;
}

bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i)
{
    // reverse dependicnes
    vector<int> opppsiteAdj[n + 1]; // array of vectors to store the graph

    for (int i = 0; i < dependencies.size(); i++)
    {
        opppsiteAdj[dependencies[i].second].push_back(dependencies[i].first);
    }
    white.erase(n); // remove from the white set
    grey.insert(n); // put into the grey set

    int counter = 0;
    while (!isempty(stack))
    {
        int popped = stack.pop();
        if (popped == white.end())
        {
            for (int i = 0; i < adj[n].size(); i++)
            {
                counter++;
                if (i < counter)
                { // check if its is present or not in grey set
                    flag1 = 1;
                }
            }
        }
    }

    black.insert(n); // put into the black set
    grey.erase(n);   // remove from the grey set
    return false;
}

int main()
{
    // vector<pair<int, int>> CircleLine = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9},{13,14},{14,15},{15,16},{16,17},{17,18},{18,19},{19,20},{20,21},{21,22},{9,1}};
    // canFinish(22, CircleLine); // expect false

    // vector<pair<int, int>> circle = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9},{9,1}};
    // canFinish(9, circle); // expect false

    // vector<pair<int, int>> line = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9},{9,10}};
    // canFinish(10, line); // expect true

    // vector<pair<int, int>> star1 = {{10,2},{10,2},{10,3},{10,4},{10,5},{10,6},{10,7},{10,8},{10,9}};
    // canFinish(10, star1); // expect true

    // vector<pair<int, int>> star2 = {{1,10},{2,10},{3,10},{4,10},{5,10},{6,10},{7,10},{8,10},{9,10}};
    // canFinish(10, star2); // expect true

    // vector<pair<int, int>> ShortLoop = {{1,2},{2,3},{3,1}};
    // canFinish(3, ShortLoop); // expect false

    // vector<pair<int, int>> small = {{1,2},{2,3}};
    // canFinish(2, small); // expect true

    // vector<pair<int, int>> ex2 = {{1,2},{2,1}};
    // canFinish(2, ex2); // expect true

    // vector<pair<int, int>> ex1 = {{1,2}};
    // canFinish(2,ex1);

    return 0;
}