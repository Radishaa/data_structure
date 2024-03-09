#include "RHeap.h"

RHeap::RHeap() {}

RHeap::RHeap(std::vector<int> tmpheap, bool tmpisMaxHeap)
{
    isMaxHeap = tmpisMaxHeap;
    heap = tmpheap;
    for (int i = getParent(heap.size() - 1); i >= 0; i--)
    {
        siftDown(i, tmpisMaxHeap);
    }
}

int RHeap::peek()
{
    return heap[0];
}

void RHeap::push(int val)
{
    heap.push_back(val);

    siftUp(heap.size() - 1, isMaxHeap);
}

void RHeap::pop()
{
    // 不需要返回，通过peek()获取堆顶元素即可
    if (heap.empty())
    {
        // 未做错误分析
        return;
    }
    int pop = heap[0];

    swap(heap, 0, heap.size() - 1);

    heap.pop_back();

    siftDown(0, isMaxHeap);
}

void RHeap::siftUp(int i, bool isMaxHeap)
{
    if (isMaxHeap)
    {
        while (true)
        {
            int p = getParent(i);
            if (p < 0 || heap[i] <= heap[p])
                return;

            swap(heap, i, p);
            i = p;
        }
    }
    else
    {
        while (true)
        {
            int p = getParent(i);
            if (p < 0 || heap[i] >= heap[p])
                return;

            swap(heap, i, p);
            i = p;
        }
    }
}

void RHeap::siftDown(int i, bool isMaxHeap)
{
    if (isMaxHeap)
    {
        while (true)
        {
            int l = getLeft(i), r = getRight(i), max = i;
            if (l < heap.size() && heap[l] >= heap[max])
                max = l;
            if (r < heap.size() && heap[r] >= heap[max])
                max = r;
            if (max == i)
                return;
            swap(heap, max, i);
            i = max;
        }
    }
    else
    {
        while (true)
        {
            int l = getLeft(i), r = getRight(i), max = i;
            if (l < heap.size() && heap[l] <= heap[max])
                max = l;
            if (r < heap.size() && heap[r] <= heap[max])
                max = r;
            if (max == i)
                return;
            swap(heap, max, i);
            i = max;
        }
    }
}

int RHeap::getLeft(int p)
{
    return p * 2 + 1;
}

int RHeap::getRight(int p)
{
    return p * 2 + 2;
}

int RHeap::getParent(int p)
{
    return (p - 1) / 2;
}

void RHeap::swap(std::vector<int> &nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
