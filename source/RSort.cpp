#include "RSort.h"
#include<ctime>

RSort::RSort() {}

void RSort::qsort(std::vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;

    int pivot = partition(nums, left, right);
    qsort(nums, left, pivot - 1);
    qsort(nums, pivot + 1, right);
}

int RSort::partition(std::vector<int> &nums, int left, int right)
{
    int i = left, j = right;
    // 随机的基准数
    srand(time(nullptr));
    int r = rand() % (right - left + 1) + left;
    swap(nums, r, left);
    while (i < j)
    {
        //必须右端先动！非常重要非常重要
        //因为右边先判断则判断
        while (i < j && nums[left] <= nums[j])
            j--;
        while (i < j && nums[left] >= nums[i])
            i++;
        
        swap(nums, i, j);
    }
    swap(nums, left, i);
    return i;
}

void RSort::swap(std::vector<int> &nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
