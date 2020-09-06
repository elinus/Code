package Data_Structures_and_Algorithms.Trees;

public class TreeTraversalMain {

    public static void main(String[] args) {

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        TreeTraversal ttObj = new TreeTraversal();

        ttObj.inOrderRecursive(root);
        ttObj.inOrderIterative(root);
        System.out.println();

        ttObj.preOrderRecursive(root);
        ttObj.preOrderIterative(root);
        System.out.println();

        ttObj.postOrderRecursive(root);
        ttObj.postOrderIterativeTwoStacks(root);
        ttObj.postOrderIterativeOneStack(root);
        System.out.println();

        ttObj.levelOrderTraversal(root);
        ttObj.levelOrderZigZagTraversal(root);
    }
}
