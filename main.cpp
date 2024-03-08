#include <iostream>
// #include <string>
// #include <cmath>
#include "include/RSort.h"
using namespace std;

int main()
{
    // 排序算法测试
    RSort t;
    vector<int> a = {2, 4, 1, 0, 3, 5, 5, 21, 52, 79};
    // 快排测试
    //  t.qsort(a, 0, a.size() - 1);
    t.heapsort(a);
    // 排序结果展示
    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}
