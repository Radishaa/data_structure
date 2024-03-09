#ifndef RHEAP_H
#define RHEAP_H
#include <vector>

class RHeap
{
    std::vector<int> heap;
    bool isMaxHeap;

private:
    /**
     * @param p 当前节点
     * @brief 获取p的左孩子
    */
    int getLeft(int p);

    /**
     * @param p 当前节点
     * @brief 获取p的右孩子
    */
    int getRight(int p);

    /**
     * @param p 当前节点
     * @brief 获取p的父节点
    */
    int getParent(int p);

    /**
     * @param nums 当前节点
     * @param i 待交换位置1
     * @param j 待交换位置2
     * @brief 交换nums中的i和j位置元素
    */
    void swap(std::vector<int> &nums, int i, int j);

    /**
     * @param i 从i节点上升
     * @param isMaxHeap 是否是大顶堆
     * @brief 从i出上升，保持大顶堆的构造
    */
    void siftUp(int i,bool isMaxHeap);

    /**
     * @param i 从i节点下坠
     * @param isMaxHeap 是否是大顶堆
     * @brief 从i出下坠，保持大顶堆的构造
    */
    void siftDown(int i,bool isMaxHeap);


public:
    //构造函数
    RHeap();
    RHeap(bool isMaxHeap) : isMaxHeap(isMaxHeap){};
    RHeap(std::vector<int> heap, bool isMaxHeap);

    /**
     * @brief 获取堆顶元素
    */
    int peek();

    /**
     * @param 加入堆的数值
     * @brief 添加新元素进堆
    */
    void push(int val);

    /**
     * @brief 将堆顶元素推出
    */
    void pop();


};

#endif
