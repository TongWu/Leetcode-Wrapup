
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 使用双指针(二分查找)
		int left = 0, right = numbers.size() - 1;
		while (left <= right) {
			int sum = numbers[left] + numbers[right];
			if (sum == target) {
				return {left+1, right+1};
			} else if (sum < target) {
				left++;
			} else if (sum > target) {
				right--;
			}
		}
		return {-1, -1};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
