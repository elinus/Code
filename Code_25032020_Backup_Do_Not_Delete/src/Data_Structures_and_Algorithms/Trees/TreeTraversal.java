package Data_Structures_and_Algorithms.Trees;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class TreeTraversal {

    private void inOrderUtil(TreeNode root) {
        if (root != null) {
            inOrderUtil(root.left);
            System.out.print(root.val + " ");
            inOrderUtil(root.right);
        }
    }

    private void preOrderUtil(TreeNode root) {
        if (root != null) {
            System.out.print(root.val + " ");
            preOrderUtil(root.left);
            preOrderUtil(root.right);
        }
    }

    private void postOrderUtil(TreeNode root) {
        if (root != null) {
            postOrderUtil(root.left);
            postOrderUtil(root.right);
            System.out.print(root.val + " ");
        }
    }

    public void inOrderRecursive(TreeNode root) {
        if (root != null) {
            inOrderUtil(root);
            System.out.println();
        }
    }

    public void inOrderIterative(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        while (true) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            if (stack.isEmpty()) break;
            root = stack.pop();
            System.out.print(root.val + " ");
            root = root.right;
        }
        System.out.println();
    }

    public void preOrderRecursive(TreeNode root) {
        if (root != null) {
            preOrderUtil(root);
            System.out.println();
        }
    }

    public void preOrderIterative(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        while (true) {
            while (root != null) {
                System.out.print(root.val + " ");
                stack.push(root);
                root = root.left;
            }
            if (stack.isEmpty()) break;
            root = stack.pop();
            root = root.right;
        }
        System.out.println();
    }

    public void postOrderRecursive(TreeNode root) {
        if (root != null) {
            postOrderUtil(root);
            System.out.println();
        }
    }

    public void postOrderIterativeTwoStacks(TreeNode root) {
        if (root == null) return;
        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        stack1.push(root);
        while (!stack1.isEmpty()) {
            TreeNode node = stack1.pop();
            stack2.push(node);
            if (node.left != null)
                stack1.push(node.left);
            if (node.right != null)
                stack1.push(node.right);
        }
        while (!stack2.isEmpty()) {
            System.out.print(stack2.pop().val + " ");
        }
        System.out.println();
    }

    public void postOrderIterativeOneStack(TreeNode root) {
        if (root == null) return;
        Stack<TreeNode> stack = new Stack<>();
        while (true) {
            while (root != null) {
                if (root.right != null)
                    stack.push(root.right);
                stack.push(root);
                root = root.left;
            }
            if (stack.isEmpty()) break;
            root = stack.pop();
            if (root.right != null && !stack.isEmpty() && stack.peek() == root.right) {
                stack.pop();
                stack.push(root);
                root = root.right;
            } else {
                System.out.print(root.val + " ");
                root = null;
            }
        }
        System.out.println();
    }

    public void levelOrderTraversal(TreeNode root) {
        if (root == null) return;
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            System.out.print(node.val + " ");
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        System.out.println();
    }

    public void levelOrderZigZagTraversal(TreeNode root) {
        if (root == null) return;
        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        Queue<TreeNode> queue1 = new LinkedList<TreeNode>();
        Queue<TreeNode> queue2 = new LinkedList<TreeNode>();
        stack1.push(root);
        while (!stack1.isEmpty() || !queue2.isEmpty()) {
            while (!stack1.isEmpty()) {
                TreeNode node1 = stack1.pop();
                System.out.print(node1.val + " ");
                if (node1.right != null) stack2.push(node1.right);
                if (node1.left != null) stack2.push(node1.left);
            }
            while (!stack2.isEmpty()) {
                TreeNode node2 = stack2.pop();
                System.out.print(node2.val + " ");
                if (node2.left != null) stack1.push(node2.left);
                if (node2.right != null) stack1.push(node2.right);
            }
        }
    }
}
