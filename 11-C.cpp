//
// Created on 2023/11/24.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(int n, const vector<pair<int, int>>& edges) {
    vector<TreeNode*> nodes(n);

    for (int i = 0; i < n; ++i) {
        nodes[i] = new TreeNode(i);
    }

    for (int i = 0; i < n - 1; ++i) {
        int l = edges[i].first;
        int r = edges[i].second;

        if (l != -1) {
            nodes[i]->left = nodes[l];
        }

        if (r != -1) {
            nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];  // 返回根节点
}

pair<int, int> findLongestPath(TreeNode* root) {
    if (!root) {
        return make_pair(0, 0);
    }

    auto leftResult = findLongestPath(root->left);
    auto rightResult = findLongestPath(root->right);

    int currentDepth = 1 + max(leftResult.first, rightResult.first);
    int currentEdges = leftResult.second + rightResult.second + 1;

    return make_pair(currentDepth, max(currentEdges, max(leftResult.second, rightResult.second)));
}

int diameterOfBinaryTree(TreeNode* root) {
    if (!root) {
        return 0;
    }

    auto leftResult = findLongestPath(root->left);
    auto rightResult = findLongestPath(root->right);

    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);

    return max({leftResult.first + rightResult.first, leftDiameter, rightDiameter});
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    TreeNode* root = buildTree(n, edges);

    int result = diameterOfBinaryTree(root);
    auto a= findLongestPath(root);
    cout << 2*(a.second-1)-result<<endl;
    return 0;
}
