# !bin/even
# -*- coding:utf-8 -*-
# author:pzq
# HierSort
# version: 3.6.5
import random

"""
希尔排序
"""


def show(num_l):
    len_path = len(num_l) // 2
    while len_path > 0:
        for i in range(len(num_l) - len_path):
            if num_l[i] > num_l[i + len_path]:
                tem = num_l[i]
                num_l[i + len_path] = num_l[i]
                num_l[i] = tem
        len_path -= 1
    # 输出每次的排序结果
    for i in num_l:
        print(i, end=" ")
    print()


if __name__ == '__main__':
    # 生成随机测试结果
    for _ in range(10):
        num_list = [random.randint(1, 100000) for _ in range(6)]
        show(num_list)
