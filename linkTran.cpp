#include <iostream>
#include <vector>

using namespace std;

int linkCount(vector<vector<int >> &nums);  // 计算网络图中连通的个数

int main() {
    vector<vector<int >> nums = {{1, 0, 1},
                                 {1, 1, 0},
                                 {1, 0, 1}};
    linkCount(nums);
    return 0;
}

int linkCount(vector<vector<int >> &nums) {
    int num_x = nums.size();
    int num_y = nums[0].size();
    // 生成两个向量，用来记录x的值和y的值
    vector<int> count_x(num_x), count_y(num_y);
    for (int i = 0; i < num_x; ++i) {
        for (int j = 0; j < num_y; ++j) {
            if (nums[i][j] == 1) {
                // 对x轴的统计和对y轴的统计
                ++count_x[i];
                ++count_y[j];
            }
        }
    }
    int count = 0;
    for (int k = 0; k < num_x; ++k) {
        for (int i = 0; i < num_y; ++i) {
            if (nums[k][i] == 1) {
                // 如果值为1且该轴的值大于1则说明在此处有连接
                if (count_x[k] > 1 || count_y[i] > 1) {
                    count++;
                }
            }
        }
    }
    return count;
}
