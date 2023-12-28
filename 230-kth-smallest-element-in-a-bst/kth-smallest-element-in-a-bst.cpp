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
    void preOrder(vector<int> &trav, TreeNode* root){
        if(root==NULL) return;

        preOrder(trav,root->left);
        trav.push_back(root->val);
        preOrder(trav,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> trav;
        preOrder(trav,root);
        for(int i=0; i<trav.size(); i++){
            if(k==1){
                return trav[i];
            }
            else{
                k--;
            }
        }
        return -1;
    }
};