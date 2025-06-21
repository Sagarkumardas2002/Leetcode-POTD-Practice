# Write your MySQL query statement below
# Write your MySQL query statement below

-- Approach One
-- SELECT MAX(SALARY) as SECONDHIGHESTSALARY from EMPLOYEE where SALARY <(select MAX(SALARY) from EMPLOYEE)

SELECT ( SELECT DISTINCT Salary FROM Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1
    ) AS SecondHighestSalary;
