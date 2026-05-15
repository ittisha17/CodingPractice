SELECT 
    reg.contest_id,
    ROUND(
        (COUNT(DISTINCT reg.user_id) * 100.0) / 
        (SELECT COUNT(*) FROM Users),
        2
    ) AS percentage
FROM Register reg
GROUP BY reg.contest_id
ORDER BY percentage DESC, reg.contest_id ASC;