# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT MAX(SALARY) as SECONDHIGHESTSALARY from EMPLOYEE where SALARY <(select MAX(SALARY) from EMPLOYEE)