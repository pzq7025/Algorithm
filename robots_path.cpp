//
// Created by 14276 on 2020/5/3.
//
#include <iostream>
#include <vector>
#include <limits.h>

#define Max 100

using namespace std;

int path[Max][Max];

int path_choose(int &m, int &n) {
//    cout << m << n;
    path[0][0] = 1;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) { // 边界值
                path[i][j] = 1;
                continue;
            }
            if (j == 0) { // 边界值
                path[i][j] = 1;
                continue;
            }
            path[i][j] = path[i - 1][j] + path[i][j - 1];  // 下一个路径之和为前面两个之和
        }
    }
    cout << path[m - 1][n - 1] << endl;  // 输出m, n的值，因为是前一个所以-1
}

int main() {
    int m, n;
    cin >> m >> n;
    path_choose(m, n);
}
