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

    TreeNode* solve(int pre_st, int pre_en, vector<int> &preorder,int in_st, int in_en, vector<int> &inorder, unordered_map<int,int> &mp){
        if(pre_st>pre_en || in_st>in_en){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pre_st]);

        int nele = mp[preorder[pre_st]];
        int n_left = nele-in_st;

        root->left = solve(pre_st+1,pre_st+n_left,preorder,in_st,nele-1,inorder,mp);
        root->right = solve(pre_st+n_left+1,pre_en,preorder,nele+1,in_en,inorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_st,pre_end,in_st,in_end;
        pre_st = 0;
        pre_end = preorder.size()-1;
        in_st = 0;
        in_end = inorder.size()-1;

        unordered_map<int,int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return solve(pre_st,pre_end,preorder,in_st,in_end,inorder,mp);
    }
};