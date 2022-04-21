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

void CycleDetect(int n, vector<int> adj[]);
bool canFinish(int n, vector<pair<int, int>> &dependencies);

// function to detect the cycle in graph
void CycleDetect(int n, vector<int> adj[])
{
    white.erase(n); // remove from the white set
    grey.insert(n); // put into the grey set

    for (int i = 0; i < adj[n].size(); i++)
    {
        // cout << "[INFO] white.find(adj[n][i]) = " << *(white.find(adj[n][i])) << endl;
        if (white.find(adj[n][i]) != white.end())
        {
            CycleDetect(adj[n][i], adj);
        }
        if (grey.find(adj[n][i]) != grey.end()) // check if its is present or not in grey set
        {
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
        //{1,2}
        adj[dependencies[i].first].push_back(dependencies[i].second);
    }
    for (int i = 1; i < n; i++)
    {
        white.insert(i);
    }
    // while(!white.empty())
    // {
    //     CycleDetect(n, adj);
    // }
    CycleDetect(n, adj);

    if (flag == 0)
    {
        // cout << "TRUE - Graph DOES NOT contain a cycle" << endl;
        return true;
    }
    else
    {
        // cout << "FALSE - Graph DOES contain a cycle" << endl;
        return false;
    }
    return 0;
}

bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i)
{
    // reverse dependicnes
    vector<int> opppsiteAdj[n + 1]; // array of vectors to store the graph
    stack<int> stack;
    vector<int> visited(n + 1, 0);

    for (int i = 0; i < dependencies.size(); i++)
    {
        opppsiteAdj[dependencies[i].second].push_back(dependencies[i].first);
    }
    // white.erase(n); // remove from the white set
    // grey.insert(n); // put into the grey set
    stack.push(n);

    //{2,1}
    //{1,2}
    // {{1,2},{2,3},{2,4},{1,5}};
    // {{2,1},{3,2},{4,2},{5,1}};
    int counter = 1;
    while (!stack.empty())
    {
        // int popped = stack.top();
        // stack.pop();
        // cout << "[INFO] popped = " << popped << endl;
        // // {1,2}
        // // {2,1}
        // // {2,3}
        // if (!visited[popped])
        // {
        //     visited[popped] = 1;
        // }
        for (int k = 1; k < opppsiteAdj[popped].size() + 1; k++)
        {
            cout << "[INFO] opppsiteAdj[popped][k] " << opppsiteAdj[popped][k] << endl;
            // counter++;
            cout << "[INFO] visited[k] = " << visited[k] << endl;
            if (visited[k])
            {
                counter++;
            }
            else
            {
                stack.push(k);
            }
        }
    }
    cout << endl;
    if (i >= counter)
    { // check if it is present or not in grey set, if present then return true
        // flag1 = 1;
        cout << "TRUE - This CAN run" << endl;
        return true;
    }
    else
    {
        cout << "FALSE - This CAN NOT run" << endl;
        return false;
    }
}

int main()
{
    // vector<pair<int, int>> CircleLine = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {13, 14}, {14, 15}, {15, 16}, {16, 17}, {17, 18}, {18, 19}, {19, 20}, {20, 21}, {21, 22}, {9, 1}};
    // canFinish(22, CircleLine); // expect false

    // vector<pair<int, int>> CircleLine = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9},{9,1},{9,10}/*,{14,15},{15,16},{16,17},{17,18},{18,19},{19,20},{20,21},{21,22}*/};
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

    // vector<pair<int, int>> ex2 = {{1, 2}, {2, 1}};
    // canFinish(2, ex2); // expect true

    // vector<pair<int, int>> ex1 = {{1, 2}};
    // canFinish(2, ex1);
    // cout << canRun(2, ex1, 2, 1) << endl;

    // vector<pair<int, int>> test = {{1, 2}, {2, 3}, {3, 1}, {3, 4}};
    // canFinish(3, test);

    // vector<pair<int, int>> telephone9 = {{1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}, {8, 9}, {1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}, {6, 9}};
    // cout << canRun(9, telephone9, 9, 4) << endl;

    // vector<pair<int, int>> telephone8 = {{1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}, {8, 9}, {1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}, {6, 9}};
    // // cout << canRun(9, telephone8, 8, 6) << endl;
    // canRun(9, telephone8, 8, 6);

    // vector<pair<int, int>> exFalse = {{1, 2}};
    // // cout << canRun(2, exFalse, 2, 1) << endl;
    // canRun(2, exFalse, 2, 1);

    vector<pair<int, int>> exFalse = {{1, 2}, {2, 3}, {2, 4}, {1, 5}};
    // cout << canRun(2, exFalse, 2, 1) << endl;
    canRun(5, exFalse, 3, 2);

    return 0;
}