#include "RSort.h"
#include "RHeap.h"
#include <ctime>

RSort::RSort() {}

void RSort::qsort(std::vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;

    int pivot = partition(nums, left, right);
    qsort(nums, left, pivot - 1);
    qsort(nums, pivot + 1, right);
}

void RSort::msort(std::vector<int> &nums, int left, int right)
{
    // 递归终止条件
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    msort(nums, left, mid);
    msort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

void RSort::heapsort(std::vector<int> &nums)
{
    RHeap maxHeap = RHeap(nums, true);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        nums[i] = maxHeap.pop();
    }
}

void RSort::merge(std::vector<int> &nums, int left, int mid, int right)
{
    // 创建一个新的temp数组用于比较两边的数进行归并
    std::vector<int> temp(right - left + 1);
    // i是左边数组指针，j是右边数组指针，k是temp指针
    int i = left, j = mid + 1, k = 0;
    // 左边数组和右边数组都有元素时
    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
        {
            temp[k++] = nums[i++];
        }
        else
        {
            temp[k++] = nums[j++];
        }
    }
    // 把剩余数组元素放入temp中
    while (i <= mid)
    {
        temp[k++] = nums[i++];
    }
    while (j <= right)
    {
        temp[k++] = nums[j++];
    }
    // 将数组放入原位置
    for (int i = 0; i < temp.size(); i++)
    {
        nums[left + i] = temp[i];
    }
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
        // 必须右端先动！非常重要非常重要
        // 因为右边先判断则判断
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
