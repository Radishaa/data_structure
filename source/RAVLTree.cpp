#include "RAVLTree.h"
#include <queue>
#include <iostream>

// RAVLTree::RAVLTree(){}

RAVLTree::~RAVLTree() {}

RAVLTree *RAVLTree::insert(RAVLTree *root, int tar)
{
    if (root == nullptr)
        return new RAVLTree(tar);
    if (tar < root->val)
    {
        root->left = insert(root->left, tar);
    }
    else if (tar > root->val)
    {
        root->right = insert(root->right, tar);
    }
    else
    {
        return root;
    }
    updateHeight(root);
    root = rotate(root);
    return root;
}

RAVLTree *RAVLTree::remove(RAVLTree *root, int tar)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (tar < root->val)
        root->left = remove(root->left, tar);
    else if (tar > root->val)
        root->right = remove(root->right, tar);
    else
    {
        if (root->left == nullptr || root->right == nullptr)
        {
            RAVLTree *child = root->left != nullptr ? root->left : root->right;
            if (child == nullptr)
            { // 叶子结点，直接删除
                delete root;
                return nullptr;
            }
            else
            { // 有一个孩子，将孩子变成原来节点
                delete root;
                root = child;
            }
        }
        else
        { // 有两个孩子，此处做法是，删除原有节点，将右孩子的最小值替换该节点
            RAVLTree *temp = root->right;
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }
            int temVal = temp->val;
            root->right = remove(root->right, temVal);
            root->val = temVal;
        }
    }
    updateHeight(root);
    root = rotate(root);
    return root;
}

RAVLTree *RAVLTree::serarch(RAVLTree *root, int tar)
{
    RAVLTree *temp = root;
    while (temp != nullptr)
    {
        if (tar < temp->val)
            temp = temp->left;
        else if (tar > temp->val)
            temp = temp->right;
        else
        {
            return temp;
        }
    }
    std::cout << "Not found!" << std::endl;
    return temp;
}

void RAVLTree::inOrder(RAVLTree *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    std::cout << root->val << std::endl;
    inOrder(root->right);
}

std::vector<int> RAVLTree::levelOrder(RAVLTree *root)
{
    std::queue<RAVLTree *> queue;
    queue.push(root);
    std::vector<int> vec;
    while (!queue.empty())
    {
        RAVLTree *node = queue.front();
        vec.push_back(node->val);
        queue.pop();
        if (node->left != nullptr)
            queue.push(node->left);
        if (node->right != nullptr)
            queue.push(node->right);
    }
    return vec;
}

RAVLTree *RAVLTree::rotate(RAVLTree *root)
{
    int _balanceFactor = balanceFactor(root);
    if (_balanceFactor > 1)
    { // 左偏树
        if (balanceFactor(root->left) >= 0)
        { // LL
            return rightRotate(root);
        }
        else
        { // LR
            root->left = lefttRotate(root->left);
            return rightRotate(root);
        }
    }
    else if (_balanceFactor < -1)
    { // 右偏树
        if (balanceFactor(root->right) <= 0)
        { // RR
            return lefttRotate(root);
        }
        else
        { // RL
            root->right = rightRotate(root->right);
            return lefttRotate(root);
        }
    }
    return root;
}

RAVLTree *RAVLTree::rightRotate(RAVLTree *root)
{
    RAVLTree *child = root->left;
    RAVLTree *gra_child = child->right;
    child->right = root;
    root->left = gra_child;
    updateHeight(root);
    updateHeight(child);
    return child;
}

RAVLTree *RAVLTree::lefttRotate(RAVLTree *root)
{
    RAVLTree *child = root->right;
    RAVLTree *gra_child = child->left;
    child->left = root;
    root->right = gra_child;
    updateHeight(root);
    updateHeight(child);
    return child;
}

int RAVLTree::getHeight(RAVLTree *root)
{
    return root == nullptr ? -1 : root->height;
}

void RAVLTree::updateHeight(RAVLTree *root)
{
    root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

int RAVLTree::balanceFactor(RAVLTree *root)
{
    if (root == nullptr)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}
