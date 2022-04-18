// https://www.codespeedy.com/cycle-detection-in-a-directed-graph-in-cpp/

#include "job.h"
#include <vector>
#include <iterator>
#include <list>
#include <iostream>
#include <set>
#include <utility>

using namespace std;

set<int> white; // white container
set<int> grey;  // grey container
set<int> black; // black container
int flag = 0;

bool canFinish(int n, vector<pair<int, int>> &dependencies)
{
    // need to create a grpah

    cout << "[INFO] 1" << endl;
    vector<pair<int, int>> *depend = &dependencies;
    int numPairs = (*depend).size();
    vector<int> adj[numPairs];
    int adjSize = 0;

    for (int i = 0; i < numPairs; i++)
    {
        cout << "[INFO] 2" << endl;
        adj[i].push_back((*depend)[i].first);
        adj[i].push_back((*depend)[i].second);
        white.insert(i);
        adjSize++;
        // cout << "[INFO] adjSize = " << adjSize << endl;
        // cout << "[INFO] (*depend)[i].first = " << (*depend)[i].first << endl;
        // cout << "[INFO] adj[i][0] = " << adj[i][0] << endl;
        // cout << "[INFO] (*depend)[i].first = " << (*depend)[i].second << endl;
        // cout << "[INFO] adj[i][1] = " << adj[i][1] << endl << endl;
    }
    cout << "[INFO - before] white.size() = " << white.size() << endl;
    white.erase(n); // remove from the white set
    grey.insert(n); // put into the grey set
    // cout << "[INFO] *std::next(grey.begin(), n) = " << *std::next(grey.begin(), n) << endl;

    for (int i = 0; i < numPairs; i++)
    {
        cout << "[INFO] 3" << endl;
        white.erase(n);
        grey.insert(n);

        for (int j = 0; j < 2; j++)
        {
            cout << "[INFO] adj[i][j] = " << adj[i][j] << endl;
            cout << "[INFO - not equal] *(white.find(adj[i][j])) = " << *(white.find(adj[i][j])) << endl;
            cout << "[INFO - not equal] *(white.end()) = " << *(white.end()) << endl;
            if (white.find(adj[i][j]) != white.end())
            {
                cout << "IN HERE " << endl;
                vector<pair<int, int>> remaining = {};
                for (int k = 0; k < adjSize; k++) // might not be adding to the empty vector
                {
                    cout << "[INFO] 5" << endl;
                    remaining[k].first = adj[k][0];
                    remaining[k].second = adj[k][1];
                }
                // vector<pair<int,int>> *recursive;
                // recursive = &remaining;
                cout << "[INFO] 4" << endl;
                // canFinish(adj[n][i], remaining);
                // }
                // if (grey.find(adj[n][i]) != grey.end())
                // { // check if its is present or not in grey set
                //     flag = 1;
            }
            cout << "out" << endl;
        }
    }
    black.insert(n); // put into the black set
    grey.erase(n);   // remove from the grey set
    if (flag)
    {
        cout << "there is a cycle" << endl;
        return false;
    }
    else
    {
        cout << "there is no cycle" << endl;
        return true;
    }
}

bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i)
{

    return false;
}

int main()
{
    vector<int> adj[5]; // vector of array to store the graph

    vector<pair<int, int>> dependencies = {{1, 2}, {2, 3}, {3, 1}};
    //   vector<pair<int, int> > dependencies = { {1,4}, {3,6} , {2,4} };

    canFinish(3, dependencies);

    // input for edges
    // edge(adj, 0, 2);
    // edge(adj, 0, 1);l
    // edge(adj, 1, 3);
    // edge(adj, 2, 0);
    // edge(adj, 3, 3);
    // edge(adj, 2, 3);
    // edge(adj, 2, 4);
    // for (int i = 0; i < 5; i++)
    //{
    //  white.insert(i);
    //}
    // CycleDetect(0, adj);
    // if (flag == 0)
    //  cout << "Graph does not contain cycle" << endl;
    // else
    //  cout << "Graph contain cycle" << endl;
    return 0;
}