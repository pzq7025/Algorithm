##include <iostream>
#include <vector>

using namespace std;
int serialResult(int &N);  //连续整数求和

int main() {
    int N = 100;
    serialResult(N);
    return 1;
}

int serialResult(int &N) {
    int ans = 0;
    for (int i = 1; N > 0; N -= i, i++) {
        /**
         * N       i         N%i      ans(bool)      start     num            array
         * 100     1          0         1             100       1              100
         * 99      2          1         0
         * 97      3          1         0
         *              .
         *              .
         *              .
         * 90      5          0         1              18        5        18 19 20 21 22
         *              .
         *              .
         *              .
         * 72      8          0         1              9          8          9 10 11 12 13 14 15 16
         *              .
         *              .
         *              .
         * 9       14          9        0
         * end
         * 数学理论
         * 1个长度的数组：那么就是100/1   第一个数是100
         * 2个长度的数组：那么就是99/2    除尽了说明这个数存在  那么就是x + 1
         * 类推：
         * 因为需要保证它的连续性    所以每次需要从上一个得到的值进行拓展   所以它的数就为原来数的
         * 一个数距离就是1   x
         * 两个数距离就是2   x+(x+1) == 2x + 1   所以现在的x就是在原来的x上：-1
         * 三个数距离就是3   x+(x+1)+(x+2) == 3x + 1 + 2 所以现在的x就是在原来的x上：-2
         * 四个数距离就是4   x+(x+1)+(x+2)+(x+3) == 4x + 1 + 2 + 3  所以现在的x就是在原来的x上：-3
         * n个数距离就是n    x+(x+1)+(x+2)+(x+3)+(x+4)+...+(x+k)+...+(x+n) == nx + 1 + 2 + 3 + ... + ... + n  所以现在的x就是在原来的x上：-n  (1<k<n)
         * 所以求得的X:      x = (Xn-1 - n) / n  bool判断条件就是：%n == 0  数组范围就是 range(x, x+n)
         */
        ans += (N % i == 0);
        if (N % i == 0) {
            cout << "array:";
            int start = N / i;
            for (int j = start; j < start + i; ++j) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    cout << "total:" << ans << endl;
    return ans;
}
