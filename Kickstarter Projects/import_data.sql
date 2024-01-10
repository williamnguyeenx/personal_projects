CREATE TABLE kickstarters(id INT,
						 name VARCHAR,
						 category VARCHAR,
						 sub_category VARCHAR,
						 country VARCHAR,
						 launched TIMESTAMP,
						 deadline DATE,
						 goal INT,
						 plegded INT,
						 backers INT,
						 state VARCHAR);
						 
COPY kickstarters
FROM '/Users/phucnh/Downloads/Kickstarter+Projects/kickstarter_projects.csv'
DELIMITER ','
CSV HEADER;