/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Binary Search
        int left = 0, right = nums.size() - 1;
        int start = -1, end = -1;

        // Find the left border (start)
        // Run the while loop until the left is greater than right
        while (left <= right) {
            // Declare the middle position
            int middle = left + ((right - left) / 2);
            if (nums[middle] >= target) {
                // Means the target should at the left hand side
                right = middle - 1;
                start = middle;
            } else {
                // Means the target should at the right hand side
                left = middle + 1;
            }
        }

        // Find the end position
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] <= target) {
                left = middle + 1;
                end = middle;
            } else {
                right = middle - 1;
            }
        }

        if (start == -1 || end == -1) {return {-1, -1};}
        if (nums[start] == target && nums[end] == target) {return {start, end};}
        return {-1, -1};
    }
};
// @lc code=end

