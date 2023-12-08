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
    string tree2str(TreeNode* root) {
        if(!root) return "";

        string ans;
        preorder(root,ans);
        return ans;
    }

    void preorder(TreeNode* node, string &ans){
        if(node==NULL){
            return;
        }

       ans = ans + to_string(node->val);

        if(node->left!=NULL || node->right!=NULL){
            ans.push_back('(');
            preorder(node->left,ans);
            ans.push_back(')');
        }

        if(node->right!=NULL){
            ans.push_back('(');
            preorder(node->right,ans);
            ans.push_back(')');
        }
    }
};