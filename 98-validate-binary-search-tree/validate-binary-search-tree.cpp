class Solution {
    bool find(TreeNode* root, long long min, long long max){
        if(root == NULL) return true;

        // Check if the current node's value is within the valid range
        if(root->val <= min || root->val >= max) return false;

        // Recursively check the left and right subtrees with updated ranges
        return find(root->left, min, root->val) && find(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode* root) {
        return find(root, LLONG_MIN, LLONG_MAX);
    }
};
