#
# @lc app=leetcode id=1873 lang=python
#
# [1873] Calculate Special Bonus
#

# @lc code=start
import pandas as pd

def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = 0
    employees.loc[(employees['employee_id'] % 2 != 0) & (~employees['name'].str.startswith('M')), 'bonus'] = employees['salary']
    result = employees[['employee_id', 'bonus']].sort_values(by='employee_id', ascending=True)
    return result

# @lc code=end