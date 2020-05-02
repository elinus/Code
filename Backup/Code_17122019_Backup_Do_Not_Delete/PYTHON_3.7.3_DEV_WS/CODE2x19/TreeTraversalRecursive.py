class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def pre_order(node):
    if node is not None:
        print(node.data, end=' ')
        pre_order(node.left)
        pre_order(node.right)


def post_order(node):
    if node is not None:
        post_order(node.left)
        post_order(node.right)
        print(node.data, end=' ')


def in_order(node):
    if node is not None:
        in_order(node.left)
        print(node.data, end=' ')
        in_order(node.right)


if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)

    print('----- Print pre-order traversal -----')
    pre_order(root)
    print('\n')

    print('----- Print post-order traversal -----')
    post_order(root)
    print('\n')

    print('----- Print in-order traversal -----')
    in_order(root)
    print('\n')
