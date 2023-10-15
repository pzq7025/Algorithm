"""
输入描述

n: 正整数，表示上限值

输出描述

返回一个List，包含小于等于n的所有素数。

思路与代码

找出小于等于n的所有素数，判断素数的时候采用筛选法而不是暴力

首先判断n是否小于1，如果是，则返回false，因为小于1的数不是质数。
接着判断n是否小于等于3，如果是，则返回true，因为2和3是质数。
然后判断n是否能被2或3整除，如果能整除，则返回false，因为质数不能被2或3整除。
接下来使用一个循环，从5开始，每次增加6（即i+=6）。这是因为质数的特性是除了2和3之外，其他质数都可以表示为6k±1的形式，其中k为正整数。
在循环中，判断n是否能被i整除或(i+2)整除，如果能整除，则返回false。
循环结束后，如果没有返回false，说明n是质数，返回true。
这个算法的优化之处在于，只需要遍历到√n，而不是遍历到n，这样可以减少循环次数，提高效率。同时，通过判断6k±1的形式，可以排除一部分非质数，进一步提高效率。
"""


def is_prime(n):
    if n < 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    for i in range(5, int(n ** 0.5) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False
    return True


def get_result(n):
    res = []
    for i in range(2, n + 1):
        if is_prime(i):
            res.append(i)
    return res


m = int(input("Enter a number: "))
result = get_result(m)
print(result)
