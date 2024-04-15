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
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        int sum = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,root->val});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int val = it.second;

            if(node->left==NULL && node->right==NULL){
                sum += val;
            }
            if(node->left){
                int new_val = val*10+node->left->val;
                q.push({node->left,new_val});
            }
            if(node->right){
                int new_val = val*10+node->right->val;
                q.push({node->right,new_val});
            }

        }
        return sum;
    }
};