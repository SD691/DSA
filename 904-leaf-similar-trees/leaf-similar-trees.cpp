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
    void traverse(TreeNode* root, vector<int> &one){
        if(root->right==NULL && root->left==NULL){
            one.push_back(root->val);
            return;
        }

        if(root->left){
            traverse(root->left,one);
        }
        if(root->right){
            traverse(root->right,one);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL || root2==NULL) return false;
        vector<int> one,two;
        traverse(root1,one);
        traverse(root2,two);
        if(one.size()!=two.size()) return false;
        for(int i=0; i<one.size(); i++){
            if(one[i]!=two[i]) return false;
        }
        return true;
    }
};