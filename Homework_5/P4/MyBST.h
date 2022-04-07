#ifndef __MYBST_H__
#define __MYBST_H__

#include "BST.h"
using namespace std;

class MyBST : public BST
{
public:
    MyBST();
    MyBST(int num);
    MyBST(vector<int> &nums);
    vector<Rotation> transform(MyBST target);

private:
    Node *rotateRight(Node *Q);
    Node *rotateLeft(Node *P);
    Node *adjust(Node *root, int key);
};

#endif /* __MYBST_H__*/