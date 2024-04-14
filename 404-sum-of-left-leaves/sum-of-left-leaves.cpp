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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*,bool>> q;
        q.push({root,false});
        int sum = 0;
        while(!q.empty()){
            auto it= q.front();
            TreeNode* node = it.first;
            bool val = it.second;
            q.pop();

            if(val==true && node->left==NULL && node->right==NULL){
                sum = sum+node->val;
            }

            if(node->left){
                q.push({node->left,true});
            }
            if(node->right){
                q.push({node->right,false});
            }
        }

        return sum;
    }
};