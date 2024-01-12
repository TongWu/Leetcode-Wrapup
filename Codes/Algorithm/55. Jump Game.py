class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        step = 0
        for n in nums:
            # If the step less than 0, means no more jumps, return False
            if step < 0:
                return False
            # For each block, select the biggest jump step
            elif n > step:
                step = n
            # Jump to next block cost 1 step
            step -= 1
        # If can jump to the last block, return True
        return True
