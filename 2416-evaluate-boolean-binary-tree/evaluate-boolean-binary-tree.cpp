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
    bool eval(TreeNode* root){
        if(root->val==0){
            return false;
        }
        if(root->val==1){
            return true;
        }

        bool left = eval(root->left);
        bool right = eval(root->right);
        bool ans;
        if(root->val==2){
            ans = left|right;
        } 
        if(root->val==3){
            ans =  left&right;
        }
        return  ans;
    }
    bool evaluateTree(TreeNode* root) {
        return eval(root);
    }
};