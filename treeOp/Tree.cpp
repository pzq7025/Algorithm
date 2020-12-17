//
// Created by 14276 on 2020/8/20.
//

#include "Tree.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void mid(Tree *tree);

vector<vector<int> > levelOrder(Tree *pRoot);  // 层次、广度搜索

vector<int> dfs(Tree *pBoot);  // 深度

int main() {
    Tree *r7 = new Tree();
    r7->data = 10;
    Tree *r6 = new Tree();
    r6->data = 6;
    Tree *r2 = new Tree();
    r2->data = 2;
    Tree *r3 = new Tree();
    r3->data = 3;
    Tree *r4 = new Tree();
    r4->data = 4;
    r4->leftTree = r6;
    r4->rightTree = r7;
    Tree *r1 = new Tree();
    r1->data = 1;
    r1->rightTree = r4;
    r1->leftTree = r3;
    Tree *root = new Tree();
    root->data = 5;
    root->rightTree = r2;
    root->leftTree = r1;
    cout << "中序遍历：" << endl;
    mid(root);  // 中序遍历
    cout << endl;
    vector<vector<int >> nums = levelOrder(root);
    cout << "层次遍历： " << endl;
    for (auto &num : nums) {
        for (int j : num) {
            cout << j << " ";
        }
    }
    cout << endl;
    cout << "深度遍历： " << endl;
    vector<int> nums1 = dfs(root);
    for (int num:nums1) {
        cout << num << " ";
    }
}

void mid(Tree *tree) {
    if (tree != nullptr) {
        mid(tree->leftTree);
        cout << tree->data << " ";
        mid(tree->rightTree);
    }
}


vector<vector<int> > levelOrder(Tree *pRoot) {
    // 队列实现
    vector<vector<int> > res;
    if (pRoot == nullptr)
        return res;
    queue<Tree *> q;
    q.push(pRoot);
    while (!q.empty()) {
        int cnt = q.size();  // 关键：这个size可以保证逐层遍历二叉树
        vector<int> temp;
        while (cnt--) {  // 层次遍历需要查询完每一个节点
            Tree *pNode = q.front();  // 先访问到元素在进行操作
            q.pop();
            temp.push_back(pNode->data);
            if (pNode->leftTree)
                q.push(pNode->leftTree);
            if (pNode->rightTree)
                q.push(pNode->rightTree);
        }
        res.push_back(temp);
    }

    return res;
}

vector<int> dfs(Tree *pBoot) {
    // 栈实现
    vector<int> res;
    if (pBoot == nullptr)
        return res;
    stack<Tree *> s;
    s.push(pBoot);
    while (!s.empty()) {
        Tree *pNode = s.top();  // 先访问到元素 在执行操作
        s.pop();
        res.push_back(pNode->data);
        if (pNode->rightTree)  // 由于压栈所以出左边的先右压栈
            s.push(pNode->rightTree);
        if (pNode->leftTree)
            s.push(pNode->leftTree);
    }
    return res;
}