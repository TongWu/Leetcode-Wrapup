/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int head = 0, tail = s.size()-1;
        while(head <= tail) {
            char temp = s[head];
            s[head++] = s[tail];
            s[tail--] = temp;
        }
    }
};
// @lc code=end

