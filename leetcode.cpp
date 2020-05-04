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
            if (i == 0) {
                path[i][j] = 1;
                continue;
            }
            if (j == 0) {
                path[i][j] = 1;
                continue;
            }
            path[i][j] = path[i - 1][j] + path[i][j - 1];
        }
    }
    cout << path[m - 1][n - 1] << endl;
}

int main() {
    int m, n;
    cin >> m >> n;
    path_choose(m, n);
}