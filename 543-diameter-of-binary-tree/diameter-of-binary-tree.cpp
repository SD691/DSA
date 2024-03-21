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
    int ans = 0;
    int v(TreeNode* root){
        if(root == NULL)  return 0;

        int lh = v(root->left);
        int rh = v(root->right);

        ans = max(ans,lh+rh+1);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        v(root);
        return ans-1;
    }
};