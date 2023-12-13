# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maximumAverageSubtree(self, root):
        """
        :type root: TreeNode
        :rtype: float
        """
        self.res = 0

        def dfs(node):
            if not node:
                return 0, 0
            val_left, count_left = dfs(node.left)
            val_right, count_right = dfs(node.right)
            val_total = float(val_left + val_right + node.val)
            count_total = count_left + count_right + 1
            self.res = max(self.res, val_total / count_total)
            return val_total, count_total

        dfs(root)
        return self.res
