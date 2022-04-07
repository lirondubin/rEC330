//
//  MyBST.cpp
//  bst_transform
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

struct Node *search(struct Node *root, int key);
void inorder(struct Node *root, MyBST *t2);
void adjust(Node *root, MyBST *t2);

vector<Rotation> MyBST::transform(MyBST target)
{

    // MyBST M(//some vector); //some Binary search tree

    // M.transform(t2//some other BST)
    /*** Your implementation should go here. ***/
    MyBST *t2 = &target;

    if (!(t2->root->key))
    {
        return {};
    }
    else
    {
        search(root, t2->root->key); // search(current BST's root, target's key)
        inorder(root, t2);

        /*
        target = "find root 2 in BST by applying search";
        "adjust root(target)";
        transform(target->left);
        transform(target->right);
        */
        cout << "fuck you wise owl" << endl;
    }

    return {};
}

struct Node *search(struct Node *root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

void inorder(struct Node *root, MyBST *t2)
{
    if (root != NULL)
    {
        if (root->key != t2->root->key)
        {
            adjust(root, t2);
        }
        inorder(root->left, t2);
        inorder(root->right, t2);
    }
}

void adjust(Node *root, MyBST *t2)
{
    if (t2->root->key < root->key)
    {
        Rotation(root->key, ZIG);
    }
    else if (t2->root->key >= root->key)
    {
        Rotation(root->key, ZAG);
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
    vector<int> firstVec = {1, 5, 3, 65, 34};
    MyBST M(firstVec);
    vector<int> secondec = {1, 5, 3, 65, 34};
    MyBST Q(firstVec);

    M.transform(Q);

    MyBST *T = &M;
    // T->root->key;
    cout << T->root->right->right->left->key << endl;
    // cout << M->(key + 1) << endl;

    // cout << M.print() << endl;

    return 0;
}