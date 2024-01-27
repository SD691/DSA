/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root,int &count){
        if(!root) return 0;

        int left = max(0,dfs(root->left,count));
        int right = max(0,dfs(root->right,count));

        count = max(count,(left+right+root->val));
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int count = INT_MIN;
        dfs(root,count);
        return count;
    }
};