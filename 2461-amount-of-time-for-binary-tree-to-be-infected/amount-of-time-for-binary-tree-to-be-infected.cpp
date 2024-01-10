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
    void findP(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mp){
        if(root==NULL) return;

        if(root->left){
            mp[root->left] = root;            
        }
        if(root->right){
            mp[root->right] = root;           
        }
        findP(root->left,mp);
        findP(root->right,mp);
    }
    TreeNode* findRoot(TreeNode* root, int start){
        if(root==NULL){
            return NULL;
        }
        if(root->val==start){
            return root;
        }
        
        TreeNode* left= findRoot(root->left,start);
        TreeNode* right = findRoot(root->right,start);

        if(left==NULL){
            return right;
        }
        else{
            return left;
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> mp;
        findP(root,mp);
        
        TreeNode* temp = findRoot(root,start);
        queue<pair<TreeNode*,int>> qu;
        unordered_map<TreeNode*,int> visited;
        visited[temp] = 1;
        qu.push({temp,0});

        int count = 0;
        while(!qu.empty()){
            int size= qu.size();
            
            
            for(int i=0; i<size; i++){
                TreeNode* node = qu.front().first;
                int level = qu.front().second;
                count = max(count,level);
                qu.pop();

                if(node->left && !visited[node->left]){
                    visited[node->left] = 1;
                    qu.push({node->left,level+1});
                }
                if(node->right && !visited[node->right]){
                    visited[node->right] = 1;
                    qu.push({node->right,level+1});
                }
                if(mp[node] && !visited[mp[node]]){
                    visited[mp[node]] = 1;
                    qu.push({mp[node],level+1});
                }
            }
        }
        return count;
    }
};