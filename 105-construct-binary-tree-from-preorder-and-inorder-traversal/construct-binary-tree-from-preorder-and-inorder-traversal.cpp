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
    TreeNode* build(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, map<int,int> &mp){
        if(prestart>preend || instart>inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);

        int ele = mp[root->val];
        int nele = ele-instart;

        root->left = build(preorder,prestart+1,prestart+nele,inorder,instart,ele-1,mp);
        root->right = build(preorder,prestart+nele+1,preend,inorder,ele+1,inend,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prestart = 0;
        int preend = preorder.size()-1;
        int instart = 0;
        int inend = inorder.size()-1;

        map<int,int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return build(preorder,prestart,preend,inorder,instart,inend,mp);
    }
};