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
    void func(TreeNode* root, int val){
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        TreeNode* newLeft = new TreeNode(val);
        TreeNode* newRight = new TreeNode(val);

        root->left = newLeft;
        root->right = newRight;
        newLeft->left = left;
        newRight->right = right;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){
            auto it = q.front();
            TreeNode* node = it.first;
            int dep = it.second;
            q.pop();

            if(depth-1==dep){
                func(node,val);
            }

            if(depth-1<dep) continue;
            if(node->left){
                q.push({node->left,dep+1});
            }
            if(node->right){
                q.push({node->right,dep+1});
            }

        }
        return root;
    }
};