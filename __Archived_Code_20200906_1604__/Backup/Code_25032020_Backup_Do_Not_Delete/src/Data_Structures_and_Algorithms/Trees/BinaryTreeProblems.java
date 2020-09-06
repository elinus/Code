package Data_Structures_and_Algorithms.Trees;

import com.interviewbit.LinkedLists.ListNode;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class BinaryTreeProblems {
    /* Problem 1 - Finding maximum element in binary tree */
    int FindMax(TreeNode root) {
        int root_val, left, right, max = Integer.MIN_VALUE;
        if (root != null) {
            root_val = root.val;
            left = FindMax(root.left);
            right = FindMax(root.right);
            if (left > right)
                max = left;
            else
                max = right;
            if (root_val > max)
                max = root_val;
        }
        return max;
    }

    /* Problem 2 - Finding maximum element in binary tree without recursion */
    int FindMaxUsingLevelOrder(TreeNode root) {
        int max = Integer.MIN_VALUE;
        if (root != null) {
            Queue<TreeNode> queue = new LinkedList<>();
            queue.add(root);
            while (!queue.isEmpty()) {
                TreeNode node = queue.poll();
                if (node.val > max) max = node.val;
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
        }
        return max;
    }

    /* Problem 3 - Search an element in binary tree */
    boolean FindInBinaryTreeUsingRecursion(TreeNode root, int data) {
        if (root == null) return false;
        else {
            if (root.val == data) return true;
            else  {
                if (FindInBinaryTreeUsingRecursion(root.left, data))
                    return true;
                return FindInBinaryTreeUsingRecursion(root.right, data);
            }
        }
    }

    /* Problem 4 - Searching an element in binary tree without recursion */
    boolean SearchUsingLevelOrder(TreeNode root, int data) {
        if (root == null) return false;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.val == data) return true;
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        return false;
    }

    /* Problem 5 - Insert element into binary tree */
    void InsertInBinaryTree(TreeNode root, int data) {
        TreeNode newNode = new TreeNode(data);
        if (root == null) {
            root = newNode;
            return;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.left != null) queue.add(node.left);
            else {
                node.left = newNode;
                return;
            }

            if (node.right != null) queue.add(node.right);
            else {
                node.right = newNode;
                return;
            }
        }
    }

    /* Problem 6 - Finding size of binary tree */
    int SizeOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        else return SizeOfBinaryTree(root.left) + 1 + SizeOfBinaryTree(root.right);
    }

    /* Problem 7 - Finding size of binary tree without recursion */
    int SizeOfBTUsingLevelOrder(TreeNode root) {
        if (root == null) return 0;
        int size = 0;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            size++;
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        return size;
    }

    /* Problem 8 - Print level order data in reverse order */
    void LevelOrderTraversalInReverse(TreeNode root) {
        if (root == null) return;
        Stack<TreeNode> stack = new Stack<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
            stack.push(node);
        }
        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
        System.out.println();
    }

    /* Problem 9 - Deleting the tree */
    void DeleteBinaryTree(TreeNode root) {
        if (root == null) return;
        DeleteBinaryTree(root.left);
        DeleteBinaryTree(root.right);
        root = null;
    }

    /* Problem 10 - Height of binary tree */
    int HeightOfBinaryTree(TreeNode root) {
        int left, right;
        if (root == null) return 0;
        else {
            left = HeightOfBinaryTree(root.left);
            right = HeightOfBinaryTree(root.right);
            if (left > right)
                return left + 1;
            else
                return right + 1;
        }
    }

    /* Problem 11 - Height of binary tree without recursion */
    int FindHeightOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        int level = 1;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        queue.add(null);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node == null) {
                if (!queue.isEmpty())
                    queue.add(null);
                level++;
            } else {
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
        }
        return level;
    }

    /* Problem 12 - Deepest node in BT */
    TreeNode DeepestNodeInBinaryTree(TreeNode root) {
        if (root == null) return null;
        TreeNode node = null;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            node = queue.poll();
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        return node;
    }

    /* Problem 14 - Number of leaves in BT w/o recursion */
    int NumberOfLeavesInBinaryTreeUsingLevelOrder(TreeNode root) {
        if (root == null) return 0;
        int count = 0;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.left == null && node.right == null)
                count++;
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        return count;
    }

    /* Problem 15 - Number of full nodes in BT w/o recursion */
    int NumberOfFullNodesInBinaryTreeUsingLevelOrder(TreeNode root) {
        if (root == null) return 0;
        int count = 0;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.left != null && node.right != null)
                count++;
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        return count;
    }

    /* Problem 16 - Number of half nodes in BT w/o recursion */
    int NumberOfHalfNodesInBinaryTreeUsingLevelOrder(TreeNode root) {
        if (root == null) return 0;
        int count = 0;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if ((node.left != null && node.right == null)
                    || (node.left == null && node.right != null))
                count++;
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        return count;
    }

    /* Problem 17 - BT identical structure check */
    boolean AreStructurallySameTrees(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null)
            return true;
        if (root1 == null || root2 == null)
            return false;
        return root1.val == root2.val
                && AreStructurallySameTrees(root1.left, root2.left)
                && AreStructurallySameTrees(root1.right, root2.right);
    }

    /* Problem 19 - Finding the level that has the maximum sum in BT */
    int FindLevelWithMaxSum(TreeNode root) {
        if (root == null) return 0;
        int level = 0, maxLevel = 0;
        int currentSum = 0, maxSum = 0;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        queue.add(null);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node == null) {
                if (currentSum > maxSum) {
                    maxSum = currentSum;
                    maxLevel = level;
                }
                currentSum = 0;
                if (!queue.isEmpty()) queue.add(null);
                level++;
            } else {
                currentSum += node.val;
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
        }
        return maxLevel;
    }

    /* Problem 20 - Print out all root-to-leaf path in BT */
    void PrintPathsRecursive(TreeNode root, int[] path, int pathLen) {
        if (root == null) return;
        path[pathLen++] = root.val;
        if (root.left == null && root.right == null)
            PrintArray(path, pathLen);
        else {
            PrintPathsRecursive(root.left, path, pathLen);
            PrintPathsRecursive(root.right, path, pathLen);
        }
    }

    void PrintArray(int[] path, int length) {
        for (int i = 0; i < length; i++) {
            System.out.print(path[i] + " ");
        }
        System.out.println();
    }

    /* Problem 22 - Sum of all element in BT with recursion */
    int Sum(TreeNode root) {
        if (root == null) return 0;
        else return root.val + Sum(root.left) + Sum(root.right);
    }

    /* Problem 23 - Sum of all element in BT without recursion */
    int SumOfBinaryTreeUsingLevelOrder(TreeNode root) {
        if (root == null) return 0;
        int sum = 0;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            sum += node.val;
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        return sum;
    }

    /* Problem 24 - Mirror of BT */
    
}
