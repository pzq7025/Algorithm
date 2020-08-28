#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(string text1, string text2);  // 最长公共子序列

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    cout << longestCommonSubsequence(text1, text2);  // 最长公共子序列
    return 0;
}

// 最长公共子序列
int longestCommonSubsequence(string text1, string text2) {
    /**
     * 状态转移表如下，*表示字串的序列，之所以填充其他位置是为了找寻的方便，同时在不增加新的相同字串的时候，源字串的长度就是已找到值的最大值
     * 如：
     * ac 当我匹配到 ac时当前的子串长度为2  当我在增加一个d时  就变成 ac与acd匹配，此时增加的d并不影响最大子串的长度
     * 
     *         "  a   b  c   d  e
     *   "  0  0  0   0  0   0  0
     *   a  0  0  1*  1  1   1  1
     *   c  0  0  1   1  2*  2  2
     *   e  0  0  1   1  2   2  3*
     */
    // 增加一行空
    int m = text1.size() + 1;
    int n = text2.size() + 1;
    if (m == 1 || n == 1) {
        return 0;
    }
    // 内存申请
    vector<vector<int>> dp_table(m, vector<int>(n, 0));
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            // 状态转移方程
            if (text1[i - 1] == text2[j - 1]) {  // 判断此时两个串中的字符是否相等
                dp_table[i][j] = dp_table[i - 1][j - 1] + 1;  // 如果相等就取右上角的值+1
            } else {
                dp_table[i][j] = max(dp_table[i - 1][j], dp_table[i][j - 1]);  // 否则就取最大值
            }
        }
    }
    return dp_table[m - 1][n - 1];
}
