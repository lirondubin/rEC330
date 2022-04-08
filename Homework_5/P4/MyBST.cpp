// Got the rotation code from here: https://www.geeksforgeeks.org/splay-tree-set-1-insert/
// MyBST.cpp
// bst_transform
//
//#include "BST.h"
#include "MyBST.h"
#include "BST.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * Computes how to transform this MyBST into the target MyBST using rotations.
 * Returns a vector of rotations indicating which rotations around which nodes
 * must be performed to transform this into the target.
 *
 * IMPORTANT: We want to transform T1 into T2 so the call should look like
 * rotations = t1.transform(t2)
 */
Node *rotateRight(Node *Q);
Node *rotateLeft(Node *P);
Node *adjust(Node *root, int key);
vector<Rotation> rotVec{};

vector<Rotation> MyBST::transform(MyBST target)
{
    vector<Rotation> returnVec;
    MyBST *t2 = &target;
    if (!(t2->root->key))
    {
        return rotVec;
    }
    else
    {
        adjust(root, t2->root->key);
        // transform(target);
    }

    return rotVec;
}

Node *MyBST::adjust(Node *root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root; //(root, root->key);
    }
    if (root->key > key)
    {
        if (root->left == NULL)
        {
            return root;
        }
        if (root->left->key > key)
        {
            root->left->left = adjust(root->left->left, key);
            root = rotateRight(root);
            Rotation tracker(key, ZIG);
            rotVec.push_back(tracker);
        }
        else if (root->left->key < key) // Zig-Zag (Left Right)
        {
            root->left->right = adjust(root->left->right, key);
            if (root->left->right != NULL)
            {
                root->left = rotateLeft(root->left);
                Rotation tracker(key, ZAG);
                rotVec.push_back(tracker);
            }
        }
        Rotation tracker(key, ZIG);
        rotVec.push_back(tracker);
        return (root->left == NULL) ? root : rotateRight(root);
    }
    else // Key lies in right subtree
    {
        if (root->right == NULL)
        {
            return root;
        }

        if (root->right->key > key)
        {
            root->right->left = adjust(root->right->left, key);
            if (root->right->left != NULL)
            {
                root->right = rotateRight(root->right);
                Rotation tracker(key, ZIG);
                rotVec.push_back(tracker);
            }
        }
        else if (root->right->key < key) // Zag-Zag (Right Right)
        {
            root->right->right = adjust(root->right->right, key);
            root = rotateLeft(root);
            Rotation tracker(key, ZAG);
            rotVec.push_back(tracker);
        }
        Rotation tracker(key, ZAG);
        rotVec.push_back(tracker);
        return (root->right == NULL) ? root : rotateLeft(root);
    }
}

MyBST::MyBST(int num)
{
    root = new Node;
    root->key = num;
    root->left = nullptr;
    root->right = nullptr;
}

MyBST::MyBST(vector<int> &nums)
{
    root = new Node;
    root->key = nums[0];
    root->left = nullptr;
    root->right = nullptr;
    for (int i = 1; i < nums.size(); i++)
        insert(nums[i]);
}

// You can use the rotation functions below as a starting point,
// or you can choose your own implementation strategy.
Node *MyBST::rotateRight(Node *Q)
{
    Node *P = Q->left;
    Q->left = P->right;
    P->right = Q;
    return P;
}

Node *MyBST::rotateLeft(Node *P)
{
    Node *Q = P->right;
    P->right = Q->left;
    Q->left = P;
    return Q;
}

int main()
{

    vector<int> firstVec = {5, 1, 34, 3, 65};
    MyBST M(firstVec);

    Rotation R(5, ZIG);
    vector<Rotation> test;
    test.push_back(R);
    vector<int> secondvec = {1, 5, 3, 65, 34};
    MyBST Q(secondvec);

    cout << "[INFO] Before: " << endl
         << M.print() << endl;
    M.transform(Q);
    cout << "[INFO] After: " << endl
         << M.print() << endl;

    // MyBST *T = &M;
    // T->root->key;
    // cout << T->root->right->right->left->key << endl;
    // cout << M->(key + 1) << endl;

    // cout << M.print() << endl;

    return 0;
}