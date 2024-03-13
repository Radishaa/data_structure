#ifndef RAVLTREE_H
#define RAVLTREE_H
#include <vector>

class RAVLTree
{
private:
    /**
     * @brief 获取当前子树的高
     */
    int getHeight(RAVLTree *root);

    /**
     * @brief 更行当前子树高
     */
    void updateHeight(RAVLTree *root);

    /**
     * @brief 获取当前子树平衡因子
     */
    int balanceFactor(RAVLTree *root);

    /**
     * @brief 旋转当前子树
     */
    RAVLTree *rotate(RAVLTree *root);

    /**
     * @brief 右旋当前子树
     */
    RAVLTree *rightRotate(RAVLTree *root);

    /**
     * @brief 左旋当前子树
     */
    RAVLTree *lefttRotate(RAVLTree *root);

public:
    int val;
    int height;
    RAVLTree *left;
    RAVLTree *right;

    /**
     * @param root 待插入的子树
     * @param tar 待插入的值
     * @return 返回完成插入后的树
     * @brief 将指定值插入到指定子树中
     */
    RAVLTree *insert(RAVLTree *root, int tar);

    /**
     * @param root 待删除的子树
     * @param tar 待删除的值
     * @return 返回完成删除后的树
     * @brief 删除指定子树中的指定值
     */
    RAVLTree *remove(RAVLTree *root, int tar);

    /**
     * @param root 待查找的子树
     * @param tar 待查找的值
     * @return 返回查找后的节点，没有找到返回nullptr
     * @brief 在子树中查找特定的值
     */
    RAVLTree *serarch(RAVLTree *root, int tar);

    /**
     * @brief 层序遍历树
     */
    std::vector<int> levelOrder(RAVLTree *root);

    /**
     * @bre
     */
    void inOrder(RAVLTree *root);

    RAVLTree(int x) : val(x), left(nullptr), right(nullptr), height(0){};
    ~RAVLTree();
};

#endif
