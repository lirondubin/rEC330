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

// struct Node *search(struct Node *root, int key);
void inorder(struct Node *root, MyBST *t2);
void adjust(Node *root, MyBST *t2);

Node *rightRotate(Node *x);
Node *leftRotate(Node *x);
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
        Node *desiredRoot = search(root, t2->root->key); // search(current BST's root, target's key)
        inorder(desiredRoot, t2);

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

// struct Node *search(struct Node *root, int key)
// {
//     // Base Cases: root is null or key is present at root
//     if (root == NULL || root->key == key)
//         return root;

//     // Key is greater than root's key
//     if (root->key < key)
//         return search(root->right, key);

//     // Key is smaller than root's key
//     return search(root->left, key);
// }

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
        // do a ZIG rotation
    }
    else if (t2->root->key >= root->key)
    {
        // do a ZAG rotation
    }
    return;
}

Node *rightRotate(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}
Node *splay(Node *root, int key)
{
    // Base cases: root is NULL or
    // key is present at root
    if (root == NULL || root->key == key)
        return root;
    if (root->key > key)
    {
        // Key is not in tree, we are done
        if (root->left == NULL)
            return root;
        // Zig-Zig (Left Left)
        if (root->left->key > key)
        {
            // First recursively bring the
            // key as root of left-left
            root->left->left = splay(root->left->left, key);
            // Do first rotation for root,
            // second rotation is done after else
            root = rightRotate(root);
        }
        else if (root->left->key < key) // Zig-Zag (Left Right)
        {
            // the key as root of left-right
            root->left->right = splay(root->left->right, key);
            // Do first rotation for root->left
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
        // Do second rotation for root
        return (root->left == NULL) ? root : rightRotate(root);
    }
    else // Key lies in right subtree
    {
        if (root->right == NULL)
            return root;
        if (root->right->key > key)
        {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (root->right->key < key) // Zag-Zag (Right Right)
        {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        return (root->right == NULL) ? root : leftRotate(root);
    }
}
Node *search(Node *root, int key)
{
    return splay(root, key);
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