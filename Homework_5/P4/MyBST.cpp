//
//  MyBST.cpp
//  bst_transform
//
#include "BST.cpp"
#include "MyBST.h"

/**
 * Computes how to transform this MyBST into the target MyBST using rotations.
 * Returns a vector of rotations indicating which rotations around which nodes
 * must be performed to transform this into the target.
 *
 * IMPORTANT: We want to transform T1 into T2 so the call should look like
 * rotations = t1.transform(t2)
 */

vector<Rotation> MyBST::transform(MyBST target)
{

    // MyBST M(//some vector); //some Binary search tree

    // M.transform(t2//some other BST)
    /*** Your implementation should go here. ***/

    // if (input-> == NULL)
    // {
    //     return;
    // }
    // else
    // {
    //     target = "find root 2 in BST by applying search";
    //     "adjust root(target)";
    //     transform(target->left);
    //     transform(target->right);
    // }

    // "adjust root (target)";

    return {};
}

// void adjust(MyBST target)
// {
//     while ((target->key != num[0]) || target != MyBST)
//     {

//     }
// }

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
    vector<int> firstVec = {1, 5, 3, 65, 34};
    MyBST M(firstVec);

    MyBST *T = &M;
    T->root->key;
    cout << T->root->key << endl;
    // cout << M->(key + 1) << endl;

    // cout << M.print() << endl;

    return 0;
}