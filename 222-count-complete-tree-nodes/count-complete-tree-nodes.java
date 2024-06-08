/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void inorder(TreeNode root, List<Integer> vec){
        if(root==null)  return;

        vec.add(root.val);
        inorder(root.left,vec);
        inorder(root.right,vec);
    }
    public int countNodes(TreeNode root) {
        List<Integer> vec = new ArrayList<>();
        inorder(root,vec);
        return vec.size();
    }
}