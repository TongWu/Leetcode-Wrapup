--
-- @lc app=leetcode id=197 lang=mysql
--
-- [197] Rising Temperature
--

-- @lc code=start
# Write your MySQL query statement below
SELECT w.id FROM Weather w, Weather w2 WHERE DATEDIFF(w.recordDate, w2.recordDate) = 1 AND w.temperature > w2.temperature
-- @lc code=end

