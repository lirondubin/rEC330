// Got the rotation code from here: https://www.geeksforgeeks.org/splay-tree-set-1-insert/
// MyBST.cpp
// bst_transform
//
#include "BST.cpp"
#include "MyBST.h"

using namespace std;

/**
 * Computes how to transform this MyBST into the target MyBST using rotations.
 * Returns a vector of rotations indicating which rotations around which nodes
 * must be performed to transform this into the target.
 *
 * IMPORTANT: We want to transform T1 into T2 so the call should look like
 * rotations = t1.transform(t2)
 */
 Node * MyBST::rotateRight(Node *Q);
Node *MyBST::rotateLeft(struct Node *P);
Node *splay(Node *root, int key);
Node *search(Node *root, int key);
void preOrder(Node *root);

vector<Rotation> MyBST::transform(MyBST target)
{
    vector<Rotation> returnVec{};
    // MyBST M(//some vector); //some Binary search tree

    // M.transform(t2//some other BST)
    /*** Your implementation should go here. ***/
    MyBST *t2 = &target;
    if (!(t2->root->key))
    {
        return returnVec;
    }
    else
    {
        search(root, t2->root->key); // search(current BST's root, target's key)
    }

    return returnVec;
}

Node *splay(Node *root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    if (root->key > key)
    {
        if (root->left == NULL)
        {
            return root;
        }
        if (root->left->key > key)
        {
            root->left->left = splay(root->left->left, key);
            root = rotateRight(root);
        }
        else if (root->left->key < key) // Zig-Zag (Left Right)
        {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
            {
                root->left = rotateLeft(root->left);
            }
        }
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
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
            {
                root->right = rotateRight(root->right);
            }
        }
        else if (root->right->key < key) // Zag-Zag (Right Right)
        {
            root->right->right = splay(root->right->right, key);
            root = rotateLeft(root);
        }
        return (root->right == NULL) ? root : rotateLeft(root);
    }
}
Node *search(Node *root, int key)
{
    return splay(root, key);
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
    vector<int> firstVec = {1, 5, 3, 65, 34};
    MyBST M(firstVec);
    vector<int> secondec = {5, 1, 34, 3, 65};
    MyBST Q(firstVec);

    M.transform(Q);

    // MyBST *T = &M;
    // T->root->key;
    // cout << T->root->right->right->left->key << endl;
    // cout << M->(key + 1) << endl;

    // cout << M.print() << endl;

    return 0;
}