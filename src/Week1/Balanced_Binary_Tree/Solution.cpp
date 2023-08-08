#include <algorithm>
#include <cmath>
#include <tuple>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        auto [bool_val, height_diff] = dfs(root);
        return bool_val;
    }

    std::tuple<bool, int> dfs(TreeNode* root) {
        if (!root) {
            return {true, -1};
        }

        auto [left_bool, left_height] = dfs(root->left);
        auto [right_bool, right_height] = dfs(root->right);

        return {(left_bool and right_bool and (std::abs(left_height - right_height) <= 1)), 
                1+std::max(left_height, right_height)};
    }
    
};