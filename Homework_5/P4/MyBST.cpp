// https://levelup.gitconnected.com/binary-search-trees-and-recursion-f99ce7eb647b
// https://www.geeksforgeeks.org/splay-tree-set-1-insert/?ref=lbp

#include "BST.h"
#include "MyBST.h"
#include <vector>
#include <iostream>
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
Node *rotateLeft(struct Node *P);
Node *adjust(Node *root, int key);
vector<int> split(Node *P);
vector<Rotation> rotVec;

vector<Rotation> MyBST::transform(MyBST target)
{
    MyBST *t2 = &target;
    vector<int> t1keys;
    vector<int> t2keys;

    if (!(t2->root->key))
    {
        return rotVec;
    }
    else
    {
        adjust(root, t2->root->key);

        // if (root->left->key != t2->root->left->key)
        // {
        //     t1keys = split(root->left);
        //     t2keys = split(t2->root->left);
        //     MyBST t1_leftChild(t1keys);
        //     MyBST t2_leftChild(t2keys);
        //     t1_leftChild.transform(t2_leftChild);
        // }

        // if (root->right->key != t2->root->right->key)
        // {
        //     t1keys = split(root->right);
        //     t2keys = split(t2->root->right);
        //     MyBST t1_rightChild(t1keys);
        //     MyBST t2_rightChild(t2keys);
        //     t1_rightChild.transform(t2_rightChild);
        // }
        return rotVec;
    }
}

Node *MyBST::adjust(Node *root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root;
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

vector<int> MyBST::split(Node *root)
{
    vector<int> keys;
    vector<int> keySplit;

    if (root->key)
    {
        keys.push_back(root->key);
        if (root->right)
        {
            keySplit = split(root->right);
            keys.insert(
                keys.end(),
                std::make_move_iterator(keySplit.begin()),
                std::make_move_iterator(keySplit.end()));
        }
        if (root->left)
        {
            keySplit = split(root->left);
            keys.insert(
                keys.end(),
                std::make_move_iterator(keySplit.begin()),
                std::make_move_iterator(keySplit.end()));
        }
    }
    return keys;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
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

int main()
{
    vector<int> firstVec = {1, 20, 3, 34, 5, 65};
    MyBST M(firstVec);
    vector<int> secondec = {20, 5, 1, 3, 65, 34};
    MyBST Q(secondec);
    vector<Rotation> finalans;
    cout << "223" << endl;
    preOrder((&M)->root);
    cout << endl << "225" << endl;
    finalans = M.transform(Q);
    cout << "227" << endl;
    preOrder((&M)->root);
    cout << endl << "229" << endl;

    return 0;
}