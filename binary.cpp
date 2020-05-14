#include <iostream>

using namespace std;

void twoDivide(int m);

int main() {
    int m;
    cin >> m;
    twoDivide(m);
    return 1;
}


void twoDivide(int m) {
    int max[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int start = 0, end = 9;
    int mid = -1;
    while (start < end) {
        mid = (start + end) / 2;
        if (max[mid] > m) {
            end = mid - 1;
        }
        if (max[mid] < m) {
            start = mid + 1;
        }
        if (max[mid] == m) {
            break;
        }
    }
    if (max[mid] == m) {
        cout << "下标：" << mid << endl;
        cout << "结果：" << max[mid];
    } else {
        cout << "Not Found!";
    }
}
