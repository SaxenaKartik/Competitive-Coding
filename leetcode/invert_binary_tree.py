# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recursion(self, node):
        if node == None:
            return node
        else: 
            left = self.recursion(node.left)
            right = self.recursion(node.right)
            #temp = left
            node.left= right
            node.right = left
            return node 
        
    def invertTree(self, root: TreeNode) -> TreeNode:
        self.recursion(root)
    
    return root
        
