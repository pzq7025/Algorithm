#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool isStraight(vector<int> &nums);  // 判断是否为顺子


int main() {
    vector<int> nums = {1, 3, 2, 4, 5};  // 判断顺子
    cout << isStraight(nums);
    return 0;
}

// 判断顺子
bool isStraight(vector<int> &nums) {
    /**
     * 判断顺子的充要条件：
     *      1.max-min < 5 （关键
     *      2.元素无重复
     */
    set<int> repeat;
    int ma = 0, mi = 14;
    for (auto num: nums) {
        if (num == 0)  // 大小王
            continue;
        ma = max(num, ma);
        mi = min(num, mi);
        if (repeat.find(num) != repeat.end())  //  元素不出现判断
            return false;
        repeat.insert(num);
    }
    return ma - mi < 5;
}
