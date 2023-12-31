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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;
        while(!q.empty()){
            auto node = q.front();
            
            q.pop();

            if(node->left!=NULL){
                q.push(node->left);
                ans++;
            }
            if(node->right!=NULL){
                q.push(node->right);
                ans++;
            }
        }
        return ans;
    }
};