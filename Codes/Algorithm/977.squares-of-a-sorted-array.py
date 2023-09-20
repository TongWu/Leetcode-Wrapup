#
# @lc app=leetcode id=977 lang=python
#
# [977] Squares of a Sorted Array
#

# @lc code=start
class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        '''
        Dual pointer:
        '''
        cur1 = 0
        cur2 = len(nums) - 1
        nums1 = [0] * len(nums)
        cur3 = len(nums) - 1
        while cur1 <= cur2:
            if nums[cur1]**2 >= nums[cur2]**2:
                nums1[cur3] = nums[cur1]**2
                cur1 += 1
            else:
                nums1[cur3] = nums[cur2]**2
                cur2 -= 1
            cur3 -= 1
        return nums1
        
# @lc code=end

