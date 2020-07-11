#include <iostream>

int convertInteger(int A, int B);

int main() {
    //  使用位运算进行相应的操作，最快的是使用汇编语言去计算
    cout << convertInteger(15, 28);
    return 0;
}

int convertInteger(int A, int B) {
    return __builtin_popcount(A ^ B);
}
