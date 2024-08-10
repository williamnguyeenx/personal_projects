import pandas as pd

# Specify the path to the Excel file
file_path = './raw/data_household_ohio.xlsx'

# Read the Excel file
df_sheet1 = pd.read_excel(file_path, sheet_name='County 2010-2022')
df_sheet2 = pd.read_excel(file_path, sheet_name='Subcounty, Places, Zip Codes')

# Save the sheets to CSV files
df_sheet1.to_csv('./convert/sheet1.csv', index=False)
df_sheet2.to_csv('./convert/sheet2.csv', index=False)


# Extracting data from the survival budget sheets

file_path_2 = './raw/household-survival-budget-ohio.xlsx'

# Survival
df_franklin = pd.read_excel(file_path_2, sheet_name='Franklin Survival')
df_franklin.to_csv('./convert/franklin.csv')

df_delaware = pd.read_excel(file_path_2, sheet_name='Delaware Survival')
df_delaware.to_csv('./convert/delaware.csv')

df_licking = pd.read_excel(file_path_2, sheet_name='Licking Survival')
df_licking.to_csv('./convert/licking.csv')

# Stability
df_franklin = pd.read_excel(file_path_2, sheet_name='Franklin Stability')
df_franklin.to_csv('./convert/franklin_stability.csv')

df_delaware = pd.read_excel(file_path_2, sheet_name='Delaware Stability')
df_delaware.to_csv('./convert/delaware_stability.csv')

df_licking = pd.read_excel(file_path_2, sheet_name='Licking Stability')
df_licking.to_csv('./convert/licking_stability.csv')



