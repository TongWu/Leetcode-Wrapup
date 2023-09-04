/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Indicate a counter, which will count who many unique integer in this array
        int counter=1;
        for (int i=1; i<=nums.size()-1; i++) {
            if (nums[i] != nums[i-1]) {
                nums[counter] = nums[i];
                counter++;
            }
        }
        return counter;
    }
};
// @lc code=end

