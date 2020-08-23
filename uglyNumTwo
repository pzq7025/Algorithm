#include <iostream>
#include <vector>

using namespace std;

int nthUglyNumber(int n); // 前n个丑数


int main() {
    int n = 8;
    // 输出前n个丑数
    cout << nthUglyNumber(n);
}


// 前n个丑数
int nthUglyNumber(int n) {
    vector<int> dp = {1};
    int l_2 = 0, l_3 = 0, l_5 = 0;
    for (int i = 1; i < n; ++i) {
        // 通过*2，*3，*5和游标就可以保证是由当前的最小数产生的结果
        int x = min(2 * dp[l_2], 3 * dp[l_3]);
        int re = min(x, 5 * dp[l_5]);
        cout << " " << 2 * dp[l_2] << " " << 3 * dp[l_3] << " " << 5 * dp[l_5] << endl;
        dp.push_back(re);  // 将最小的计算结果入栈
        for (auto ttn:  dp) {
            cout << ttn << endl;
        }
        // 通过下面的if的来判断入栈的是哪个数，这样可以每次出现的值都是最小值
        if (dp[i] == 2 * dp[l_2]) {
            l_2++;
        }
        if (dp[i] == 3 * dp[l_3]) {
            l_3++;
        }
        if (dp[i] == 5 * dp[l_5]) {
            l_5++;
        }
    }
    return dp[n - 1];
}
