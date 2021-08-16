package InterviewBit.L6_Tree_Data_Structure;

import java.util.ArrayList;
import java.util.Stack;

public class InorderTraversal {

    public int[] inorderTraversal(TreeNode A) {
        if (A == null) return null;
        Stack<TreeNode> stack = new Stack<>();
        ArrayList<Integer> output = new ArrayList<>();
        TreeNode root = A;
        while (true) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            if (stack.empty()) break;
            root = stack.peek();
            stack.pop();
            output.add(root.val);
            root = root.right;
        }
        int[] result = new int[output.size()];
        for (int i = 0; i < output.size(); i++) {
            result[i] = output.get(i);
        }
        return result;
    }
}
