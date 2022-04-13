// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

#include "job.h"
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};
void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            DFS(*i);
        }
    }
}

// This function determines if there is a cyclic dependency. If there is, then it returns 0.
bool canFinish(int n, vector<pair<int, int>> &dependencies)
{
    vector<pair<int, int>> *depend = &dependencies;
    int tot_pairs = (*depend).size();

    map<int, bool> visited;
    map<int, list<int>> adj;

    for (int i = 0; i < tot_pairs; i++)
    {
        visited[i] = true;
        for (int j = 0; j < tot_pairs - 1; j++)
        {
            if (!visited[i])
            {
                // (&dependencies).pop_back();
                canFinish(n - 1, vector<pair<int, int>> * depend)
            }
        }
    }

    cout << tot_pairs << endl;
    // cout << (*depend)[0].first << endl;

    return false;
}

bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i)
{
    return false;
}
