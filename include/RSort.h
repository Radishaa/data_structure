#ifndef RSORT_H
#define RSORT_H
#include <vector>

class RSort
{
private:
    /**
     * @brief 用于排序交换vector<int>中的两个数
     */
    void swap(std::vector<int> &nums, int i, int j);

    /**
     * @param left 划分开始位置
     * @param right 划分结束位置
     * @brief 实现快速排序划分
     */
    int partition(std::vector<int> &nums, int left, int right);

    /**
     * @param left 待合并开始位置
     * @param mid 待合并中间数
     * @param right 待合并结束位置
     * @brief 实现归并排序的合并 
    */
    void merge(std::vector<int> &nums, int left, int mid, int right);

public:
    RSort(); // 构造函数
    /**
     * @param nums 待排序数组
     * @param left 排序开始位置
     * @param right 排序结束位置
     * @brief 快速排序
     */
    void qsort(std::vector<int> &nums, int left, int right);

    /**
     * @param nums 待排序数组
     * @param left 排序开始位置
     * @param right 排序结束位置 
     * @brief 归并排序
    */
    void msort(std::vector<int> &nums, int left, int right);

};

#endif
