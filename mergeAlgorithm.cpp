#include <iostream>

using namespace std;

void merge();

int main() {
// 归并排序
    merge();
    return 1;
}

void merge() {
    int max_0[5] = {2, 9, 17, 34, 50};
    int max_1[6] = {3, 5, 10, 20, 24, 31};
    int new_max[11];
    int flag = 0;
    int one = 0, two = 0;
    while (one < 5 && two < 6) { // 若果一个数组结束直接跳出循环
        if (max_0[one] > max_1[two]) {
            //  如果第一个数组的值大于第二个数组的值， 第二个数组向后移动一位
            new_max[flag] = max_1[two];
            two++;
        } else {
        //  如果第一个数组的值小于等于第二个数组的值， 第一个数组向后移动一位
            new_max[flag] = max_0[one];
            one++;
        }
        flag++;
    }
    // 将剩下的函数值赋值
    if (one < 5) {
        for (; one < 5; one++) {
            cout << max_0[one] << " ";
            new_max[flag] = max_0[one];
            flag++;
        }
    }
    if (two < 6) {
        for (; two < 6; two++) {
            new_max[flag] = max_1[two];
            flag++;
        }
    }
    cout << endl;
    for (int i : new_max) {
        cout << i << " ";
    }
}
