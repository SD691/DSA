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
int find(TreeNode* root){
    if(root->left==NULL && root->right==NULL) return 0;

        int left = INT_MAX, right = INT_MAX;
        if(root->left){
            left = 1+find(root->left);
        }        
        if(root->right){
            right = 1+find(root->right);
        }

        return min(left,right);
}
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return find(root)+1;
    }
};