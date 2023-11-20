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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<int,TreeNode*>> q;
        vector<int> ans;
        if(!root){
            return ans;
        }
        int ptr = -1;

        q.push({0,root});
        while(!q.empty()){
            auto it = q.front();
            int level= it.first;
            TreeNode* node = it.second;
            q.pop();

            if(ptr!=level){
                ans.push_back(node->val);
                ptr = level;
            }

            if(node->right!=NULL){
                q.push({level+1,node->right});
            }
            if(node->left!=NULL){
                q.push({level+1,node->left});
            }

        }
        return ans;

    }
};