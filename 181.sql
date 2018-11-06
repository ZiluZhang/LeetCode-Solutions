-- Employees Earning More Than Their Managers

# Write your MySQL query statement below
select e1.Name as Employee from Employee as e1, Employee as e2
where e1.ManagerId = e2.Id and e1.Salary > e2.Salary

-- # Write your MySQL query statement below
-- select a.Name as "Employee"
-- from Employee as a, Employee as b
-- where a.ManagerId = b.Id and a.Salary > b.Salary;