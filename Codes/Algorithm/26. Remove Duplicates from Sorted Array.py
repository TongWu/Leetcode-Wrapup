class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                nums[result] = nums[i]
                result += 1
        return result
