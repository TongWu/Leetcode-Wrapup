--
-- @lc app=leetcode id=1683 lang=mysql
--
-- [1683] Invalid Tweets
--

-- @lc code=start
# Write your MySQL query statement below
SELECT tweet_id FROM Tweets WHERE CHAR_LENGTH(content) > 15
-- @lc code=end

