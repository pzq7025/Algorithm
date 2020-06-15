#include <iostream>
#include <vector>
using namespace std;
int reverse_pair(vector<int> &nums); // 逆序对
int MergerSort(vector<int> &nums, vector<int> &tmp, int l, int r);  // 归并算法
int main() {
    // 逆序对的使用
    vector<int> array = {1, 3, 2, 3, 1};
    cout << reverse_pair(array);
    return 1;
}

int reverse_pair(vector<int> &nums) {
    int n = nums.size();
    vector<int> tmp(n);
    return MergerSort(nums, tmp, 0, n - 1);
}

int MergerSort(vector<int> &nums, vector<int> &tmp, int l, int r) {
    // 参数意义：原数组大小，新数组大小，开始位置，结束位置
    if (l >= r) { // 分治结束的位置
        return 0;
    }
    // 找到中间的位置，将数组拆分
    int mid = (l + r) / 2;
    // 完成了分支中的分
    int inv_count = MergerSort(nums, tmp, l, mid) + MergerSort(nums, tmp, mid + 1, r);
    // 设定两个数组的游标和需要计数的位置
    // [1, 2, 3, 4]
    //  ^
    //  |
    //  i
    // [2, 4, 5, 6, 7]
    //  ^
    //  |
    //  j
    int i = l, j = mid + 1, pos = l;
    // 归并算法
    // 逆序对产生过程
    /**
     * a:[7, 2, 4, 5, 3]
     * 分治：
     * 分：
     * [7], [2], [4], [5], [3]
     * 第一个待归并的数组：[7],[4]
     * 第二个待归并的数组：[2],[5]
     * 合并之后：[2,7], [4, 5], [3]
     * i的位置在2上，j的位置在4上
     * 1:[2]
     * 由于4小于7，因此逆序数加一，通用的是：第二个数组的当前值如果大于第一个数组的当前值，那么逆序对就是第一个数组的长度-当前的位置+1
     * 2:[2,4,5,7]  逆序对为2
     * 第二次之后：[2,4,5,7], [3]
     * 第一次：[2]
     * 第二次：由于3比4小，所以逆序对的个数就是，4到7的个数之和
     * */
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
            tmp[pos] = nums[i];
            ++i;
            inv_count += (j - (mid + 1)); // 如果第二个数组先于第一个数组的值优先进入新数组，则出现逆序对
        } else {
            tmp[pos] = nums[j];
            ++j;
        }
        ++pos;
    }
    // 剩下的部分直接赋值
    // 逆序对的产生和前面的作用原理一样
    for (int k = i; k <= mid; ++k) {
        tmp[pos++] = nums[k];
        inv_count += (j - (mid + 1));
    }
    for (int m = j; m <= r; ++m) {
        tmp[pos++] = nums[m];
    }
    // 使用copy数组减少空间消耗
    copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
    return inv_count;
}
