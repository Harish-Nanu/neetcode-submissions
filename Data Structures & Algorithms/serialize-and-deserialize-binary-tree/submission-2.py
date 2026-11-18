# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:
    
    def __init__(self):
        self.serial = ""
        self.currInd = 0

    def traverse(self, root: Optional[TreeNode]):
        if not root:
            self.serial += "1001,"
        else:
            self.serial += str(root.val) + ","
            self.traverse(root.left)
            self.traverse(root.right)
    

    def revTraverse(self):
        if self.serial[self.currInd] == 1001:
            self.currInd += 1
            return None
        else:
            curr = TreeNode(val = self.serial[self.currInd])
            self.currInd += 1
            curr.left = self.revTraverse()
            curr.right = self.revTraverse()
            return curr

    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        self.traverse(root)
        # self.serial = self.serial[0:self.maxInd+5]
        return self.serial
        
    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        import ast
        data = "[" + data + "]"
        self.serial = ast.literal_eval(data)
        print(self.serial)
        # self.maxInd = len(self.serial)
        # return None
        return self.revTraverse()
