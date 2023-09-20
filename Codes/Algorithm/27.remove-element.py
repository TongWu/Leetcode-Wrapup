#
# @lc app=leetcode id=27 lang=python
#
# [27] Remove Element
#

# @lc code=start
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        
        '''
        Dual pointer:
        Two pointer fast and slow, for each elements, if the element 
        not equal to the target, the element of slow pointer is re-writted
        by the fast pointer element. Then slow pointer move forward. 
        Whatever the element is, fast pointer always move forward.
        '''
        fast = 0
        slow = 0
        while fast < len(nums):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        return slow

# @lc code=end

