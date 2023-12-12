class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        first = nums.pop()
        second = nums.pop()
        return (first - 1) * (second - 1)
