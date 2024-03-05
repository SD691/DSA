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
    TreeNode* tra(vector<int> &preorder, int preleft, int preright, vector<int> &inorder, int inleft, int inright, unordered_map<int,int> &mp){
        if(preleft>preright || inleft>inright) return NULL;
        TreeNode* root = new TreeNode(preorder[preleft]);

        int ele = mp[preorder[preleft]];
        int nele = ele-inleft;

        root->left = tra(preorder,preleft+1,preleft+nele,inorder,inleft,ele-1,mp);
        root->right = tra(preorder,preleft+nele+1,preright,inorder,ele+1,inright,mp);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        // look into this
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        int preleft = 0;
        int preright = n-1;
        int inleft = 0;
        int inright = n-1;

        return tra(preorder,preleft,preright,inorder,inleft,inright,mp);
    }
};