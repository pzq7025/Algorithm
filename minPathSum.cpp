#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>> &grid); // 最小路径和

int main() {
    vector<vector<int >> grids = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    cout << minPathSum(grids);
}

// 最小路径和
int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> nums(grid.size(), vector<int>(grid[0].size(), 0));
    for (int l = 0; l < grid.size(); ++l) {
        for (int i = 0; i < grid[0].size(); ++i) {
            if (l == 0 && i == 0) {  // 如果是初值就为0
                grid[l][i] = grid[l][i];
                continue;
            } else if (l == 0) {  // 如果在上边界就只能从前面的路径得到
                grid[l][i] = grid[l][i] + grid[l][i - 1];
            } else if (i == 0) {  // 如果是下边界就只能从上面的结果得到
                grid[l][i] = grid[l - 1][i] + grid[l][i];
            } else { grid[l][i] = min(grid[l - 1][i], grid[l][i - 1]) + grid[l][i]; }
        }
    }

    for (int k = 0; k < grid.size(); ++k) {
        for (int i = 0; i < grid[0].size(); ++i) {
            cout << " " << grid[k][i];
        }
        cout << endl;
    }
    return grid[m - 1][n - 1];
}
