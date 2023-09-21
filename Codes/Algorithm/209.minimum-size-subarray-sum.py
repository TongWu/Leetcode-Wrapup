#
# @lc app=leetcode id=209 lang=python
#
# [209] Minimum Size Subarray Sum
#

# @lc code=start
class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """

        # Sliding window:
        '''
        - Sliding window is a window that sliding form the start of the array to the end
        - The initial window size is one, which the left pointer and right pointer are both zero
        - Before shifting, the variable `sum` is added by the right pointer's element value
            - Since the initial element for right pointer is zero, so the variable `sum` contains the sliding window's elements sum
        - **While** the sum is greater or equal to the target value, calculate the minimum length `min_len`
            - Which is one of the previous or the current window size
            - Shift the sliding window, by shifting the **left pointer**
            - Do not forget to subtract the left element value from sum
        - Then, the sliding window will default increase its size by shifting right pointer
        - Finally, return the `min_len`, if the value of `min_len` is infinite, then return 0
        '''

        l = len(nums)
        left = 0
        right = 0
        min_len = float('inf')
        sum = 0
        
        while right < l:
            sum += nums[right]
            while sum >= target:
                min_len = min(min_len, right-left+1)
                sum -= nums[left]
                left += 1
            
            right += 1

        return min_len if min_len != float('inf') else 0
# @lc code=end

