class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def preOrderTraversal(node):
    if node:
        print(node.value, end=' ')
        preOrderTraversal(node.left)
        preOrderTraversal(node.right)

def inOrderTraversal(node):
    if node:
        inOrderTraversal(node.left)
        print(node.value, end=' ')
        inOrderTraversal(node.right)

def postOrderTraversal(node):
    if node:
        postOrderTraversal(node.left)
        postOrderTraversal(node.right)
        print(node.value, end=' ')

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.right.left = TreeNode(6)
root.right.right = TreeNode(7)

print("Pré-Ordem:")
preOrderTraversal(root)
print("\n")

print("Em Ordem:")
inOrderTraversal(root)
print("\n")

print("Pós-Ordem:")
postOrderTraversal(root)
