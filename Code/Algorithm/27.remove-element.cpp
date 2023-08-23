/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow_pointer = 0;
        for(int fast_pointer=0; fast_pointer < nums.size(); fast_pointer++) {
            if (nums[fast_pointer] != val) {
                nums[slow_pointer++] = nums[fast_pointer]; 
            }
        }
        return slow_pointer;
    }
};
// @lc code=end

