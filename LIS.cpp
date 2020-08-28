#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int> &nums);  // 最长上升子序列


int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums);  // 最长上升子序列
    return 0;
}

// 最长上升子序列
int lengthOfLIS(vector<int> &nums) {
    int length = nums.size();
    if (length == 0)
        return 0;
    vector<int> dp_table(length, 0);
    dp_table[0] = 1;
    int maxnum = 1;
    for (int i = 1; i < length; ++i) {  // 遍历整个数组
        int max_mid = 0;  // 我从前面找到的值 记录最大值 
        for (int j = 0; j < i; ++j) {  // 搜索前面的结果   可优化为log（n）
            if (nums[i] > nums[j]) {
                max_mid = max(dp_table[j], max_mid);
            }
        }
        dp_table[i] = max_mid + 1; // 我找到的最大值 +1 就是当前的值
        maxnum = max(maxnum, dp_table[i]); // 是否需要更新新的值
    }
    return maxnum;
}
