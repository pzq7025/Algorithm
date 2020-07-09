#include <iostream>
#include <vector>

using namespace std;

int min_num(vector<int> &nums);

int main() {
    // 0 1 2 2 2
    vector<int> nums = {4, 1, 2, 3, 3};
    cout << min_num(nums);
    return 0;
}

int min_num(vector<int> &nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    // 二分思想
    // [3,4,5,1,2]
    // 通过题目的描述我们可以知道  逆序数的结果 这个数一定小于前面的一个  也小于后面的一个 本质是在找最小值
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[right]) { // 如果中间的大于右边的说明最小值还在右序列
            left = mid + 1;
        } else if (nums[mid] < nums[right]) { // 如果mid的值小于右边的 说明序列在左边 因此需要将right移动到mid
            right = mid;
        } else {
            right--;
        }
    }
    return nums[left];
}
