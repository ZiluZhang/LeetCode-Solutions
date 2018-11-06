-- Second Highest Salary

# Write your MySQL query statement below
SELECT MAX(Salary) as SecondHighestSalary FROM Employee
Where Salary <
(SELECT MAX(Salary) FROM Employee);