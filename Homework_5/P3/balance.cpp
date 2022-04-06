// https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/

#include "node.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// your includes here
bool isWeightBalanced(node *root, int k);
int max(int a, int b);
int height(node *node);

bool isWeightBalanced(node *root, int k)
{

    if (root == NULL)
    {
        return 1;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);
    if (abs(left_height - right_height) <= k)
    {
        return 1;
    }
    return 0; // don't forget to upate this
}

int max(int first, int second)
{
    if (first >= second)
    {
        return first;
    }
    else
    {
        return second;
    }
}

int height(node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(height(node->left), height(node->right));
    }
}
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

int main()
{

    return 0;
}
