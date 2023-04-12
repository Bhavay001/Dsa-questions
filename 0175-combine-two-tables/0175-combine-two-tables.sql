# Write your MySQL query statement below
# from the sample test cases we can swee the that we need to do left join
SELECT p.firstName, p.lastName,a.city,a.state from Person as p LEFT JOIN Address as a ON p.personId = a.personId;