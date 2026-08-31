SELECT
    visited_on,
    SUM(amount) AS amount,
    ROUND(SUM(amount) OVER (
        ORDER BY visited_on
        ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ), 2) AS total_7_day
FROM Customer
GROUP BY visited_on;
