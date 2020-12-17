//
// Created by 14276 on 2020/11/14.
//

#include "nodeop.h"
#include <iostream>

using namespace std;

int main() {
    // 使用auto避免重复生成对象名字  和使用Node1 *head = new Node1等效
    auto *head = new Node1;  //  头节点的声明
    head->data = 1;
    auto *first = new Node1;  // 创建第一个节点
    first->data = 2;
    head->next = first;  // 头结点和第一个节点相连接
    auto *second = new Node1; //创建第二个节点
    second->data = 10;
    first->next = second;  // 第一个节点和第二个相连
    Node1::addTail(head, 11); // 插入节点
    Node1::addTail(head, 12); // 插入节点
    Node1::addTail(head, 17); // 插入节点
    Node1::addHead(head, 13); // 插入节点
    Node1::addHead(head, 14); // 插入节点
    Node1::addHead(head, 15); // 插入节点
    Node1::outAllList(head);
    cout << Node1::searchOne(head, 30) << endl;
    cout << Node1::searchOne(head, 2) << endl;
    Node1::deleteOne(head, 17);
    Node1::outAllList(head);  // 遍历结果
}

void Node1::outAllList(Node1 *head) {
    while (head != nullptr) { // 遍历结果
        cout << head->data << " ";
        head = head->next;
    }
}

void Node1::addTail(Node1 *node1, int value) {
    while (node1->next != nullptr) {  // 找到指针的最后节点，插入数据
        node1 = node1->next;
    }
    auto *newNode = new Node1;
    newNode->data = value;
    node1->next = newNode;
}

void Node1::addHead(Node1 *node1, int value) {
    if (node1->next == nullptr) {
        auto *newNode = new Node1;
        newNode->data = value;
        node1->next = newNode;
    } else {
        auto *newNode = new Node1;
        newNode->data = value;
        newNode->next = node1->next;
        node1->next = newNode;
    }

}

char Node1::searchOne(Node1 *node1, int value) {
    while (node1 != nullptr) {
        if (node1->data == value) {
            return 'y';
        }
        node1 = node1->next;
    }
    return 'n';

}

void Node1::deleteOne(Node1 *node1, int val) {
    Node1 *pre = node1;
    Node1 *cur = node1;
    while (cur != nullptr && cur->data != val){
        pre = cur;
        cur = cur->next;
    }
    if (cur != nullptr){
        pre->next = cur->next;
    }
}
