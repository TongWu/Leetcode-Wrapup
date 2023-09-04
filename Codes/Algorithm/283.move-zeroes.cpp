/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i=0, j=1; j<nums.size(); ) {
            if (nums[i]==0) {
                if (nums[j]!=0) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    j++;
                    i++;
                } else {
                    j++;
                }
            } else {
                j++;
                i++;
            }
        }
    }
};
// @lc code=end

