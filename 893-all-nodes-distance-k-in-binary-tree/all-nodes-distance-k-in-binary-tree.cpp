/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent_U){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                parent_U[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent_U[node->right] = node;
                q.push(node->right);
            }
        } 
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_U;
        parent(root,parent_U);

        queue<pair<TreeNode*,int>> q;
        unordered_map<TreeNode*,bool> visited;
        q.push({target,0});
        int curr_level = 0;
        visited[target] = true;

        while(!q.empty()){
            int size = q.size();
            if(curr_level++==k) break;

            for(int i=0; i<size; i++){
                TreeNode* node = q.front().first;
                q.pop();

                if(node->left && !visited[node->left]){
                    visited[node->left] = true;
                    q.push({node->left,curr_level});
                }
                if(node->right && !visited[node->right]){
                    visited[node->right] = true;
                    q.push({node->right,curr_level});
                }
                if(parent_U[node] && !visited[parent_U[node]]){
                    visited[parent_U[node]] = true;
                    q.push({parent_U[node],curr_level});
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int val = node->val;
            ans.push_back(val);
            q.pop();
        }
        return ans;
    }
};