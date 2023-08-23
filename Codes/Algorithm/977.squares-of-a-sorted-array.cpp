/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int result_pointer = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        for (int i=0, j=nums.size()-1; i<=j; result_pointer--){
            if (nums[i]*nums[i] >= nums[j]*nums[j]) {
                result[result_pointer] = nums[i] * nums[i++];
            } else if (nums[i]*nums[i] < nums[j]*nums[j]) {
                result[result_pointer] = nums[j] * nums[j--];
            }
        }
        return result;
    }
};
// @lc code=end

