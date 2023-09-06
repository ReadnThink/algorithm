package LeetCode.week3.first;


import LeetCode.week3.TreeNode;

public class MinimumAbsoluteDifferenceInBST_530 {
    public boolean init;
    int min;
    int prev;

    public int getMinimumDifference(TreeNode root) {
        init = false;
        min = Integer.MAX_VALUE;
        inorder(root);
        return min;
    }

    public void inorder (TreeNode root) {
        if (root == null) return;

        inorder(root.left);
        if (!init){
            init = true;
        } else {
            min = Math.min(min, root.val - prev);
        }
        prev = root.val;
        inorder(root.right);
    }
}
