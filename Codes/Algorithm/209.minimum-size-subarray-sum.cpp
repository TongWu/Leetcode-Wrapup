/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*
        滑动窗口法：

        该方法使用两个指针（与双指针法极其类似）确定起始位置和终止位置。
        在brute-force中，我们同样使用了滑动窗口法。在初始状态，起始位置在0，通过第一个for loop不断后调终止位置，
        再通过第二个for loop在起始位置到数组末尾后调整起始位置到下一个。这种方法使用了两个for loop，时间复杂度
        为n^2。
        
        但是在滑动窗口法中，我们可以改变起始位置的变动策略。在初始状态，起始位置在0，通过第一个for loop不断后调
        终止位置。但是一旦滑动窗口中的数字和大于等于目标值后，起始位置即+1。这样我们只需要一个for loop便能解决
        问题。
        */ 

       int result = INT32_MAX;
       int sublen = 0;
       int j = 0; //起始位置
       int sum = 0;

       for (int i=0 /*终点位置*/; i<nums.size(); i++) 
       {
            sum += nums[i];
            /*
            使用while的原因：
            考虑到即使滑动起始位置后，剩下的数组仍能满足条件，所以需要不断验证
            */
            while (sum >= target)
            {
                sublen = i - j + 1;
                result = result < sublen ? result : sublen;
                /*
                滑动起始位置后，将sum中滑出起始位置的数值减掉，同时让起始位置j加一
                */
                sum -= nums[j++];
            }
       }
       return result == INT32_MAX ? 0 : result;
    }
};
// @lc code=end

