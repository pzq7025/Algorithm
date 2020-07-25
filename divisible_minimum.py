# 直接x10+1必然会溢出，考虑到 (Ax10+1)%K = (A%K x10+1)%K，遂采用取余的方法来替代原数直接乘。
# K为偶数或者末位为5的时候得不出1，遂剔除。
K = 7


def x():
    if (K % 2 == 0) or (K % 5 == 0):
        return -1
    remainder = 0
    flag = 0
    while True:
        remainder = (remainder * 10 + 1) % K
        if remainder == 0:
            break
        flag += 1
    return flag


print(x())
