--
-- @lc app=leetcode id=595 lang=mysql
--
-- [595] Big Countries
--

-- @lc code=start
# Write your MySQL query statement below
select World.name, World.population, World.area FROM World WHERE World.area>=3000000 OR World.population>=25000000
-- @lc code=end

