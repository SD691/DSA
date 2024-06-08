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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        if(root==null) return list;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while(!q.isEmpty()){

            int size = q.size();
            List<Integer> l = new LinkedList<>();
            for(int i=0; i<size; i++){
                TreeNode val = q.element();
                q.poll();

                l.add(val.val);
                
                if(val.left!=null){
                    q.add(val.left);
                }

                if(val.right!=null){
                    q.add(val.right);
                }
            }
            list.add(l);
        }
        return list;
    }
}