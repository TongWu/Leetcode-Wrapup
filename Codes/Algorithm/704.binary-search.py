#
# @lc app=leetcode id=704 lang=python
#
# [704] Binary Search
#

# @lc code=start
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        left = 0
        right = len(nums) - 1
        while(left<=right):
          # Declare a pointer in the middle of the array
          mid = (right + left) // 2
          if nums[mid] == target:
            return mid
          elif nums[mid] > target:
            right = mid - 1
          else:
            left = mid + 1

        return -1

# @lc code=end

