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
    void inorder(TreeNode* root, vector<int> &order){
        if(root==NULL){
            return;
        }

        inorder(root->left,order);
        order.push_back(root->val);
        inorder(root->right,order);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        inorder(root,order);

        if(k>order.size()){
            return -1;
        }
        return order[k-1];
    }
};