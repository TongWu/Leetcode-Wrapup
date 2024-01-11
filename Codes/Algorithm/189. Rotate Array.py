class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        # reverse the input array
        def reverse(start, end):
            while start < end:
                nums[start], nums[end] = nums[end], nums[start]
                start, end = start + 1, end - 1

        n = len(nums)
        k %= n
        reverse(0, n - 1)  # Reverse the full array
        reverse(0, k - 1)  # Reverse the first k element
        reverse(k, n - 1)  # Reverse the rest
