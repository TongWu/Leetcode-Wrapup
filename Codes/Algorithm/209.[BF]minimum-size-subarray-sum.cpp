/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // This method is BRUTE-FORCE

        /*使用INT32_MAX而不使用0进行初始化的原因是避免target=0的情况*/
        int result = INT32_MAX;
        int sublen = 0;

        // 使用两个for loop，不断搜索可能的结果，从子字符串开始位为0开始，一直搜索到子字符串开始位为最后一位
        // 当找到解时，由于不确定是否是最优解，会继续搜索
        for (int i = 0; i < nums.size(); i++) //设置子字符串起点为i
        {
            int sum = 0;
            for (int j=i; sum<nums.size(); j++) {
                sum += nums[j];
                if (sum >= target)
                {
                    sublen = j - i + 1; // 提取子字符串的长度
                    /*
                    If the result is smaller than sublen, then the value of result will not change
                    Otherwise, replace the value of result to sublen
                    */
                    result = result < sublen ? result : sublen;
                    break;
                }
            }
        }

        /*
        At the end of the code, if the result is still the maximum value of int32, then return 0
        Otherwise, return the result value
        */
        return result == INT32_MAX ? 0 : result;
    }
};
// @lc code=end

