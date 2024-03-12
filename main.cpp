#include <iostream>
// #include <string>
// #include <cmath>
#include "include/RSort.h"
#include "include/RAVLTree.h"
using namespace std;

int main()
{
    // 排序算法测试
    RSort t;
    vector<int> a = {2, 4, 1, 0, 3, 5, 5, 21, 52, 79};
    // 快排测试
    //  t.qsort(a, 0, a.size() - 1);
    t.shellsort(a);
    // 排序结果展示
    // for (size_t i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << endl;
    // }
    RAVLTree *root = new RAVLTree(2);
    root = root->insert(root, 10);
    root = root->insert(root, 5);
    root = root->insert(root, 3);
    root = root->insert(root, 9);
    root = root->insert(root, 22);
    root = root->insert(root, 33);
    root = root->insert(root, 44);
    root = root->remove(root, 2);
    root->inOrder(root);
    std::cout << root->serarch(root, 5)->val << std::endl;

    return 0;
}
