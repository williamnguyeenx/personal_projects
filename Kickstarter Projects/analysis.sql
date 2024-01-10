SELECT * FROM kickstarters;
-- Overview of the dataset

-- Question 1: Which category has the highest success rate?
WITH rate AS (
SELECT COUNT(*) FILTER (WHERE state = 'Successful')::decimal AS success_projs, COUNT(*) FILTER(WHERE state IN ('Successful', 'Failed', 'Cancelled', 'Suspended')) AS total_projs, category
FROM kickstarters
GROUP BY category)
SELECT category, ROUND(success_projs/total_projs*100, 0) AS success_rate
FROM rate
GROUP BY category, success_projs, total_projs
ORDER BY success_rate DESC;
-- Category 'Dance' has the highest success rate of 65% whereas 'Technology' has the lowest rate which is 23%
-- 'Dance' has 2338 out of 3767 projects are successful while 'Technology' only has 6433 out of 32562 projects are successful
-- However the profit gains from successful Technology projects is 308 times more than profit from successful Dance projects

-- Question 2: What are the top 3 categories with the highest amount of successful projects?
SELECT category, COUNT(state) AS successful_projs
FROM kickstarters
WHERE state = 'Successful'
GROUP BY category
ORDER BY successful_projs DESC;
-- Music is the category with the most successful projects in the period 2009-2018
-- The 2 following categories are 'Film & Video' and 'Games

-- Let's analyze deeper, what is the sub category with the most successful projects in this top 3 categories
SELECT sub_category, COUNT(state) AS successful_projs
FROM kickstarters
WHERE state = 'Successful' AND category = 'Music'
GROUP BY sub_category
ORDER BY successful_projs DESC;
-- In 'Music', the sub category with the most successful projects is 'Music' with 6340 projects, indicating that there was an error recording the sub categories of 'Music, and many projects weren't categorized properly. However, there is no concrete method to recategorize these projects
-- The second most successful projects sub category is 'Indie Rock' with 3618 projects

SELECT sub_category, COUNT(state) AS successful_projs
FROM kickstarters
WHERE state = 'Successful' AND category = 'Film & Video'
GROUP BY sub_category
ORDER BY successful_projs DESC;
--In 'Film & Video', the best sub category is 'Shorts' with 6673 projects

SELECT sub_category, COUNT(state) AS successful_projs
FROM kickstarters
WHERE state = 'Successful' AND category = 'Games'
GROUP BY sub_category
ORDER BY successful_projs DESC;
--In 'Games', the best sub category is 'Tabletop Games' with 7866 projects
--We can see that even though category 'Game' have less total successful projects than 'Film & Video', it has the most successful sub category with close to 8000 successful projects.

-- Question 3: What are the top 3 project with a goal over $1,000 USD that have the biggest goal completion percentage? How much money is pledged in those projects?
SELECT name, category, sub_category, plegded/goal AS goal_completion_percentage, goal, plegded
FROM kickstarters
WHERE goal >= 1000
ORDER BY goal_completion_percentage DESC
LIMIT 5;
-- The top 1 project is 'Exploding Kittens' from category 'Games' with goal completion percentage of 878%, and the pledge money of close to 8.8 millions
-- The second project is 'The World's best TRAVEL JACKET with 15 features || BAUBAX' with 459% in goal completion rate, and the pledge money of almost 9.19 millions
-- The third project is 'Fidget Cube: A Vinyl Desk Toy' at 431% in goal completion percentage and near 6.5 millions in pledge money

-- Question 4: For project with at least 50% goal completion rate, what was the relationship between number of backers and the goal completion rate?
SELECT category, plegded/goal AS goal_completion_percentage, backers
FROM kickstarters
WHERE goal > 0 AND plegded/goal >= 50
ORDER BY goal_completion_percentage ASC;
-- There is no correlation between the goal completion percentage and the amount of backers. However, it seems that certain categories have significant more backers than others

SELECT category, backers
FROM kickstarters
ORDER BY backers DESC;
-- The speculation is true as there are 1.1 millions backers invest in category 'Games' which is 1.6 times more than the second category with most backers which is 'Design'

SELECT category, sub_category, backers
FROM kickstarters
ORDER BY backers DESC;
-- The sub category with the most backers however is not category 'Games' but rather in category 'Design', specifically in 'Product Design' with near 6.17 millions.

-- Question 5: What is the trends in project success rates over the years?
SELECT EXTRACT(YEAR FROM launched) AS date_start, 
		EXTRACT(YEAR FROM deadline) AS date_due,
		COUNT(state)
FROM kickstarters
WHERE state = 'Successful'
GROUP BY date_start, date_due
ORDER BY date_start ASC;
-- Projects that are completed within the year starting those projects seems to have better chance of being successful when compared to projects that are worked on between 2 years.
-- The year with the most successful projects is 2014, then decreases a bit going into 2016 and increases going into 2017

SELECT EXTRACT(YEAR FROM launched) AS date_start, 
		EXTRACT(YEAR FROM deadline) AS date_due,
		COUNT(state)
FROM kickstarters
WHERE state = 'Successful' AND EXTRACT(YEAR FROM launched) = EXTRACT(YEAR FROM deadline)
GROUP BY date_start, date_due
ORDER BY date_start ASC;
-- In terms of projects that are worked on within a year, from 2010 to 2011 there is a significant increase going from 3813 successful projects to 10988 projects.
-- From 2011 to 2012 there is another big increase in successful projects, going from 10988 to 16880.
-- 2012-2017 period maintains a good number of successful projects with every year in this period stay above 16000 projects

SELECT EXTRACT(YEAR FROM launched) AS date_start, 
		EXTRACT(YEAR FROM deadline) AS date_due,
		COUNT(state)
FROM kickstarters
WHERE state = 'Successful' AND EXTRACT(YEAR FROM launched) != EXTRACT(YEAR FROM deadline)
GROUP BY date_start, date_due
ORDER BY date_start ASC;
-- The data suggests that people avoid working on projects when it is the transition between two years as the highest amount of successful projects is 1229 projects.
-- However, the transition phases in the 2009-2017 have similiar trend with projects that are completed within the year.
-- Therefore, the trend in this 2009-2017 period is the increase in successful projects from 2009 up to until 2014, then the little decrease from 2014 to 2017.
