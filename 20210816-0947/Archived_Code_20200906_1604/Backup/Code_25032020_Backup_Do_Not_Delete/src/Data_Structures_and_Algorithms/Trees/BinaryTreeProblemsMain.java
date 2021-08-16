package Data_Structures_and_Algorithms.Trees;

public class BinaryTreeProblemsMain {

    public static void main(String[] args) {

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        BinaryTreeProblems btpObj = new BinaryTreeProblems();

        System.out.println("FindMax = " + btpObj.FindMax(root)); /* Problem-1 */
        System.out.println("FindMaxUsingLevelOrder = "
                + btpObj.FindMaxUsingLevelOrder(root)); /* Problem-2 */
        System.out.println("FindInBinaryTreeUsingRecursion = "
                + btpObj.FindInBinaryTreeUsingRecursion(root, 4)); /* Problem-3 */
        System.out.println("SearchUsingLevelOrder = "
                + btpObj.SearchUsingLevelOrder(root, 7)); /* Problem-4 */
        btpObj.InsertInBinaryTree(root, 8); /* Problem-5 */
        TreeTraversal ttObj = new TreeTraversal();
        ttObj.levelOrderTraversal(root);

        int[] paths = new int[20];
        btpObj.PrintPathsRecursive(root, paths, 0); /* Problem-20 */
    }
}
