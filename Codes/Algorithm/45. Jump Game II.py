class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n, start, end, step = len(nums), 0, 0, 0
        # 检查是否已经到达或超过了数组的最后一个位置
        while end < n - 1:
            step += 1
            # maxend for the farest block reached
            maxend = end + 1
            # 通过遍历 start 到 end 的位置，更新 maxend。对于每个位置 i，检查从 i 开始最远可以跳到哪里（i + nums[i]）
            for i in range(start, end + 1):
                # 如果在这个过程中发现可以直接跳到或超过数组的末尾，函数立即返回当前的跳跃次数 step
                if i + nums[i] >= n - 1:
                    return step
                # 更新 start 为 end + 1（即当前跳跃的结束位置的下一个位置），end 更新为 maxend（即新的最远跳跃位置）
                maxend = max(maxend, i + nums[i])
            start, end = end + 1, maxend
        return step
