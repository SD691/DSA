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
    void par(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left!=NULL){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right!=NULL){
                parent[node->right] = node;
                q.push(node->right);
            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        par(root,parent);

        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        unordered_map<TreeNode*,int> vis;
        vector<int> ans;
        vis[target] = 1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int val = it.second;

            if(val==k){
                ans.push_back(node->val);
            }

            if(node->left && vis.find(node->left)==vis.end()){
                vis[node->left] = 1;
                q.push({node->left,val+1});
            }

            if(node->right && vis.find(node->right)==vis.end()){
                vis[node->right] = 1;
                q.push({node->right,val+1});
            }
            if(parent[node] && vis.find(parent[node])==vis.end()){
                vis[parent[node]] = 1;
                q.push({parent[node],val+1});
            }
        }
        return ans;
    }
};