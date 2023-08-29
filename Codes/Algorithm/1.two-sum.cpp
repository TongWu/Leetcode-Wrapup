/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Create an unordered map to store the seen values
        unordered_map <int, int> map;

        for(int i=0; i<nums.size(); i++) {
            // Create an iterator to iterate the vector
            auto itr = map.find(target - nums[i]);

            // If the number is found in map
            if (itr != map.end()) {
                // return the two values' position
                return {itr->second, i};
            }

            // Add the value into the map
            map.insert(pair<int,int>(nums[i], i));
        }

        // If no pair found, return null
        return {};
    }
};
// @lc code=end

