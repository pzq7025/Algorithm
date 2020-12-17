//
// Created by 14276 on 2020/11/14.
//

#ifndef FIRST_NODEOP_H
#define FIRST_NODEOP_H


class Node1 {
public:
    int data{};  // 数据
    Node1 *next = nullptr;  // 移动和寻找的结构体指针

    static void outAllList(Node1 *node1); // 遍历所有结果
    static void addTail(Node1 *node1, int value);  // 尾插法
    static void addHead(Node1 *node1, int value);  // 头插法
    static char searchOne(Node1 *node1, int value);  // 查找
    static void deleteOne(Node1 *node1, int value);  // 删除
};

#endif //FIRST_NODEOP_H
