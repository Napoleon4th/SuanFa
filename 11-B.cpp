//
// Created on 2023/11/24.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};


TreeNode* buildTree(int n, const vector<pair<int, int>>& nodes) {
    if (n == 0) {
        return nullptr;
    }

    vector<TreeNode*> tree(n + 1, nullptr);

    for (int i = 1; i <= n; ++i) {
        tree[i] = new TreeNode(i);
    }

    for (int i = 1; i <= n; ++i) {
        if (nodes[i - 1].first != -1) {
            tree[i]->left = tree[nodes[i - 1].first];
        }
        if (nodes[i - 1].second != -1) {
            tree[i]->right = tree[nodes[i - 1].second];
        }
    }

    return tree[1];
}

vector<int> findDecoratedNodes(TreeNode* root) {
    vector<int> result;

    if (!root) {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

            if (i == 0 || i == levelSize - 1) {
                result.push_back(node->val);
            }

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].first >> nodes[i].second;
    }

    TreeNode* root = buildTree(n, nodes);

    vector<int> result = findDecoratedNodes(root);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
