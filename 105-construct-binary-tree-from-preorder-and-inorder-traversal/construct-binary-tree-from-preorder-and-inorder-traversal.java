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
    public TreeNode solve(int prestart, int preend, int[] preorder, int instart, int inend, int[] inorder, Map<Integer,Integer> mp){
        if(prestart>preend || instart>inend){
            return null;
        }

        TreeNode root = new TreeNode(preorder[prestart]);

        int nele = mp.get(preorder[prestart]);
        int nleft = nele-instart;

        root.left = solve(prestart+1,prestart+nleft,preorder,instart,nele-1,inorder,mp);
        root.right = solve(prestart+nleft+1, preend ,preorder ,nele+1 ,inend,inorder,mp);
        return root;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
            int instart = 0;
            int inend = inorder.length-1;
            int prestart = 0;
            int preend = preorder.length-1;

            Map<Integer,Integer> mp = new HashMap<>();
            for(int i=0; i<inorder.length; i++){
                mp.put(inorder[i],i);
            }

            return solve(prestart,preend,preorder,instart,inend,inorder,mp);
    }
}