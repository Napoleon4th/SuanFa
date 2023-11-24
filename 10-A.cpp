//
// Created on 2023/11/18.
//
#include <iostream>
#include <stack>

using namespace std;

// 二叉树结点的定义
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

// 前序遍历构建二叉树
TreeNode* buildTree(const string& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == '@') {
        index++;
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[index++]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);

    return root;
}

// 打印叶子节点到根节点的路径
void printLeafToRootPaths(TreeNode* root, char path[], int pathLen) {
    if (root == nullptr) {
        return;
    }

    path[pathLen] = root->data;
    pathLen++;

    if (root->left == nullptr && root->right == nullptr) {
        // 叶子节点，打印路径
        for (int i = pathLen - 1; i >= 0; i--) {
            cout << path[i];
        }
        cout << endl;
    } else {
        // 非叶子节点，递归处理左右子树
        printLeafToRootPaths(root->left, path, pathLen);
        printLeafToRootPaths(root->right, path, pathLen);
    }
}

int main() {
    string preorder;
    cin >> preorder;

    int index = 0;
    TreeNode* root = buildTree(preorder, index);

    const int MAX_PATH_LENGTH = 100; // 可根据实际情况调整
    char path[MAX_PATH_LENGTH];

    printLeafToRootPaths(root, path, 0);

    return 0;
}


