--
-- @lc app=leetcode id=1581 lang=mysql
--
-- [1581] Customer Who Visited but Did Not Make Any Transactions
--

-- @lc code=start
# Write your MySQL query statement below
SELECT Visits.customer_id as customer_id, count(Visits.visit_id) as count_no_trans FROM Visits LEFT JOIN Transactions ON Visits.visit_id = Transactions.visit_id WHERE Transactions.transaction_id IS NULL GROUP BY Visits.Customer_id
-- @lc code=end

