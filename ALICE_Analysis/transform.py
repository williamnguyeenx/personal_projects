import pandas as pd

# Specify the path to the Excel file
file_path1 = './convert/sheet1.csv'
file_path2 = './convert/sheet2.csv'

# Read the Excel file
df1 = pd.read_csv(file_path1)
df2 = pd.read_csv(file_path2)
print("Loaded csv files. Ready to check")

print("Checking sheet1\n")
# Check for null values
null_values = df1.isnull().sum()
print("Null values in each column:\n", null_values)

# Check for duplicates
duplicates = df1.duplicated().sum()
print(f"Number of duplicate rows: {duplicates}")

# Check data types
data_types = df1.dtypes
print("Data types of each column:\n", data_types)

print("Checking sheet2\n")
# Check for null values
null_values2 = df2.isnull().sum()
print("Null values in each column:\n", null_values)

# Check for duplicates
duplicates2 = df2.duplicated().sum()
print(f"Number of duplicate rows: {duplicates}")

# Check data types
data_types2 = df2.dtypes
print("Data types of each column:\n", data_types)

print("Data check complete.")

