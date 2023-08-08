struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        
        // If root is greater than both: root = root->left
        // If root is smaller than both: root = root->right
        // If root is between p and q(inclusive) : return root
        
        TreeNode * current = root;

        while (current) {
            if (current->val > p->val and current->val > q->val){
                current = current->left;
            }
            else if (current->val < p->val and current->val < q->val){
                current = current->right;
            }
            else {
                break;
            }
        }
        return current;
    }
};