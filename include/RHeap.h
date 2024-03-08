#ifndef RHEAP_H
#define RHEAP_H
#include <vector>

class RHeap
{
    std::vector<int> heap;
    bool isMaxHeap;

private:
    int getLeft(int p);
    int getRight(int p);
    int getParent(int p);
    void swap(std::vector<int> &nums, int i, int j);
    void siftUp(int i,bool isMaxHeap);
    void siftDown(int i,bool isMaxHeap);


public:
    RHeap();
    RHeap(bool isMaxHeap) : isMaxHeap(isMaxHeap){};
    RHeap(std::vector<int> heap, bool isMaxHeap);

    int peek();

    void push(int val);

    int pop();


};

#endif
