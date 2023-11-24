#include <iostream>
#include <algorithm>

using namespace std;

// 定义二叉树的节点结构
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

// 构建二叉树
TreeNode* buildTree(const string& preorder, int& index) {
    if (index >= preorder.length() || preorder[index] == '@') {
        index++;
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[index++]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);

    return root;
}

// 计算二叉树中相距最远的两个节点之间的距离
int findMaxDistance(TreeNode* root, int& maxDistance) {
    if (root == nullptr) {
        return 0;
    }

    // 递归计算左右子树的深度
    int leftDepth = findMaxDistance(root->left, maxDistance);
    int rightDepth = findMaxDistance(root->right, maxDistance);

    // 更新最远距离
    maxDistance = max(maxDistance, leftDepth + rightDepth);

    // 返回当前子树的深度
    return 1 + max(leftDepth, rightDepth);
}

int main() {
    int length;
    cin >> length;

    string preorder;
    cin >> preorder;

    int index = 0;
    TreeNode* root = buildTree(preorder, index);

    int maxDistance = 0;
    findMaxDistance(root, maxDistance);

    cout << maxDistance << endl;

    return 0;
}
