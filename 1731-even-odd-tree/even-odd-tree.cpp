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
    bool check_val(vector<int> &temp, int s){
        
        if(s%2==0){
            for(int i=0; i<temp.size(); i++){
                if(temp[i]%2==0){
                    return false;
                }
            }
        }
        else if(s%2!=0){
            for(int i=0; i<temp.size(); i++){
                if(temp[i]%2!=0){
                    return false;
                }
            }
        }
        return true;
    }
    bool check(vector<int> &temp, int s){
        if(s==0) return true;
        if(s%2==0){
            for(int i=1; i<temp.size(); i++){
                if(temp[i]<=temp[i-1]){
                    return false;
                }
            }
        }
        else{
            for(int i=1; i<temp.size(); i++){
                if(temp[i]>=temp[i-1]){
                    return false;
                }
            }
        }
        return true;
        
        
    }
    bool isEvenOddTree(TreeNode* root) {
        if(root->val%2==0) return false;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        vector<int> temp;
        while(!q.empty()){
            int size=  q.size();
            int sign = q.front().second;
            vector<int> temp;

            for(int i=0; i<size; i++){
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                int val = it.second;
                temp.push_back(node->val);

                if(node->left){
                    q.push({node->left,val+1});
                }
                if(node->right){
                    q.push({node->right,val+1});
                }
            }
            if((check(temp,sign)==false || check_val(temp,sign)==false)){
                return false;
            }
            temp.clear();

            
        }

        return true;
    }
};