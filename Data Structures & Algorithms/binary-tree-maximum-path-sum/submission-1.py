# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def __init__(self):
        self.TreeVal = {}
        self.Path : int

    def maxSum(self, root: Optional[TreeNode]):
        if not root:
            return 0
        else:
            self.TreeVal[root] = root.val + max(self.maxSum(root.right), self.maxSum(root.left), 0)
            # print(str(root) + str(self.TreeVal[root]))
            return self.TreeVal[root]

    def maxPath(self, root: Optional[TreeNode], parentPath):
        if not root:
            return
        else:
            leftVal = max((self.TreeVal[root.left] if root.left else 0), 0)
            rightVal = max((self.TreeVal[root.right] if root.right else 0), 0)
            combVal = leftVal + rightVal + root.val
            self.Path = max(parentPath + leftVal + root.val, parentPath + rightVal + root.val, combVal, self.Path)
            self.maxPath(root.left, max(parentPath, rightVal) + root.val)
            self.maxPath(root.right, max(parentPath, leftVal) + root.val)

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.Path = root.val
        self.maxSum(root)
        self.maxPath(root, 0)
        return self.Path
        