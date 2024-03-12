#ifndef RAVLTREE_H
#define RAVLTREE_H
#include <vector>

class RAVLTree
{
private:
    int getHeight(RAVLTree *root);
    void updateHeight(RAVLTree *root);
    int balanceFactor(RAVLTree *root);
    RAVLTree *rotate(RAVLTree *root);
    RAVLTree *rightRotate(RAVLTree *root);
    RAVLTree *lefttRotate(RAVLTree *root);

public:
    int val;
    int height;
    RAVLTree *left;
    RAVLTree *right;

    RAVLTree *insert(RAVLTree *root, int tar);
    RAVLTree *remove(RAVLTree *root, int tar);
    RAVLTree *serarch(RAVLTree *root, int tar);
    std::vector<int> levelOrder(RAVLTree *root);
    void inOrder(RAVLTree *root);

    RAVLTree(int x) : val(x), left(nullptr), right(nullptr), height(0){};
    ~RAVLTree();
};

#endif
