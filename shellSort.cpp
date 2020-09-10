#include <iostream>
#include <vector>

using namespace std;

// 希尔排序算法 
int xierSort(vector<int> &nums);

int main() {
    vector<int> num_list = {1, 5, 0, 4, 1, 2, 8};
    xierSort(num_list);
    return 0;
}

int xierSort(vector<int> &nums) {
    int path_len = nums.size() / 2;  // 选择步长
    while (path_len > 0) {
        cout << path_len << endl;
        //  循环的次数为数组的长度值-步长  这样就可以保证最后一个被访问  同时数组不会出现越界的情况   
        //  还有一个优化的地方就是可以使用 一个flag判断时候有变化   如果没有变化就说明已经是顺序结果  就不需要交换
        for (int i = 0; i < nums.size() - path_len; ++i) {
            if (nums[i] >= nums[i + path_len]) {
                int tem = nums[i];
                nums[i] = nums[i + path_len];
                nums[i + path_len] = tem;
            }
        }
        for (auto xx:nums) {
            // 输出每次的结果
            cout << xx << " ";
        }
        cout << endl;
        path_len--;
    }
    // 排序好的结果
    for (auto xx:nums) {
        cout << xx << " ";
    }
}


