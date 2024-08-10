import pandas as pd
import numpy as np

# Get the files
file_path1 = './convert/sheet1.csv'
file_path2 = './convert/sheet2.csv'

df1 = pd.read_csv(file_path1)
df2 = pd.read_csv(file_path2)
print("Loaded csv files. Ready to analyse")

# Analysis

### Overview of sheet1, which is the more broad data
print(df1.head(10))

# Top 10 highest poverty rate county
df1['Poverty_Round'] = np.round(df1['Poverty Households'] / df1['Households']*100)
df1['Under 65'] = np.round(df1['ALICE Threshold - HH under 65'])
df1['Equal or greater than 65'] = np.round(df1['ALICE Threshold - HH 65 years and over'])

# Select the required columns
df1_selected = df1[['Year', 'County', 'Poverty_Round', 'Under 65', 'Equal or greater than 65']]

# Group by 'Year' and 'County' and ensure uniqueness
df1_grouped = df1_selected.groupby(['Year', 'County'], as_index=False).first()

# Sort by 'Year' in descending order
df1_sorted = df1_grouped.sort_values(by=['Poverty_Round'], ascending=False)

df1_sorted = df1_sorted.head(10)

print(df1_sorted)

# Athens and Scioto have the highest poverty rate

### Top 10 worst poverty rate county

df1_sorted = df1_grouped.sort_values(by=['Poverty_Round'], ascending=True)

df1_sorted = df1_sorted.head(10)

print(df1_sorted)



### Franklin, Delaware, and Licking counties over the years regardin poverty rate

# Franklin poverty rate
df1_filtered = df1[df1['County'] == 'Franklin']

# Calculate the poverty rate and round the result
df1_filtered['Poverty Rate'] = np.round((df1_filtered['Poverty Households'] / df1_filtered['Households']) * 100)

# Group by 'year' and 'county' and aggregate the poverty rate
df1_grouped = df1_filtered.groupby(['Year', 'County']).agg({'Poverty Rate': 'first'}).reset_index()

# Sort the DataFrame by 'Poverty_Rate' in descending order
df1_sorted = df1_grouped.sort_values(by='Year', ascending=True)

# Display the result
print(df1_sorted)


# Delaware poverty rate
df1_filtered = df1[df1['County'] == 'Delaware']

# Calculate the poverty rate and round the result
df1_filtered['Poverty Rate'] = np.round((df1_filtered['Poverty Households'] / df1_filtered['Households']) * 100)

# Group by 'year' and 'county' and aggregate the poverty rate
df1_grouped = df1_filtered.groupby(['Year', 'County']).agg({'Poverty Rate': 'first'}).reset_index()

# Sort the DataFrame by 'Poverty_Rate' in descending order
df1_sorted = df1_grouped.sort_values(by='Year', ascending=True)

# Display the result
print(df1_sorted)

#Licking poverty rate
df1_filtered = df1[df1['County'] == 'Licking']

# Calculate the poverty rate and round the result
df1_filtered['Poverty Rate'] = np.round((df1_filtered['Poverty Households'] / df1_filtered['Households']) * 100)

# Group by 'year' and 'county' and aggregate the poverty rate
df1_grouped = df1_filtered.groupby(['Year', 'County']).agg({'Poverty Rate': 'first'}).reset_index()

# Sort the DataFrame by 'Poverty_Rate' in descending order
df1_sorted = df1_grouped.sort_values(by='Year', ascending=True)

# Display the result
print(df1_sorted)

### Poverty rate stays relatively the same for the overall county, 2-3% increase/decrease

# Overview of sheet2
print(df2.head(10))

### Average, highest, and lowest ALICE threshold

# Group by 'County' and calculate mean, min, and max
df1_grouped = df1.groupby('County').agg({
    'ALICE Threshold - HH under 65': ['mean', 'min', 'max'],
    'ALICE Threshold - HH 65 years and over': ['mean', 'min', 'max']
}).reset_index()

# Flatten the multi-level column names
df1_grouped.columns = ['_'.join(col).strip() if col[1] else col[0] for col in df1_grouped.columns.values]

# Rename the columns for readability
df1_grouped = df1_grouped.rename(columns={
    'ALICE Threshold - HH under 65_mean': 'Under_65_mean',
    'ALICE Threshold - HH under 65_min': 'Under_65_min',
    'ALICE Threshold - HH under 65_max': 'Under_65_max',
    'ALICE Threshold - HH 65 years and over_mean': 'Over_65_mean',
    'ALICE Threshold - HH 65 years and over_min': 'Over_65_min',
    'ALICE Threshold - HH 65 years and over_max': 'Over_65_max'
})

# Display the top 10 county with the lowest average for under 65
df1_low_average_under_65 = df1_grouped[['County', 'Under_65_mean']]
df1_low_average_under_65 = df1_low_average_under_65.sort_values(by='Under_65_mean', ascending=True)
print("\n", df1_low_average_under_65.head(10))

# Display the top 10 county with the highest average for under 65
df1_high_average_under_65 = df1_grouped[['County', 'Under_65_mean']]
df1_high_average_under_65 = df1_high_average_under_65.sort_values(by='Under_65_mean', ascending=False)
print("\n", df1_high_average_under_65.head(10))

# Display the top 10 county with the lowest average for at least 65
df1_low_average_over_65 = df1_grouped[['County', 'Over_65_mean']]
df1_low_average_over_65 = df1_low_average_over_65.sort_values(by='Over_65_mean', ascending=True)
print("\n", df1_low_average_over_65.head(10))

# Display the top 10 county with the highest average for at least 65
df1_high_average_over_65 = df1_grouped[['County', 'Over_65_mean']]
df1_high_average_over_65 = df1_high_average_over_65.sort_values(by='Over_65_mean', ascending=False)
print("\n", df1_high_average_over_65.head(10))

# Display the top 10 county with the lowest threshold for under 65
df1_min_under_65 = df1_grouped[['County', 'Under_65_min']]
df1_min_under_65 = df1_min_under_65.sort_values(by='Under_65_min', ascending=True)
print("\n", df1_min_under_65.head(10))

# Display the top 10 county with the lowest threshold for over 65
df1_min_over_65 = df1_grouped[['County', 'Over_65_min']]
df1_min_over_65 = df1_min_over_65.sort_values(by='Over_65_min', ascending=True)
print("\n", df1_min_over_65.head(10))

# Display the top 10 county with the highest threshold for under 65
df1_max_under_65 = df1_grouped[['County', 'Under_65_max']]
df1_max_under_65 = df1_max_under_65.sort_values(by='Under_65_max', ascending=False)
print("\n", df1_max_under_65.head(10))

# Display the top 10 county with the highest threshold for over 65
df1_max_over_65 = df1_grouped[['County', 'Over_65_max']]
df1_max_over_65 = df1_max_over_65.sort_values(by='Over_65_max', ascending=False)
print("\n", df1_max_over_65.head(10))


### From the top mean, min, max threshold county, check the poverty rate of subcounties

### Under 65 - lowest mean

df2['Location'] = df2['GEO.display_label']

df2_filtered = df2[df2['Location'].str.contains('Crawford County, Ohio', case=False, na=False)]

# Calculate the ALICE_or_lower_rate and round the result
df2_filtered['ALICE_or_lower_rate'] = np.round(((df2_filtered['Poverty Households'] + df2_filtered['ALICE Households']) / df2_filtered['Households']) * 100)

# Group by 'Year' and 'Location' and aggregate the ALICE_or_lower_rate
df2_grouped = df2_filtered.groupby(['Year', 'Location']).agg({'ALICE_or_lower_rate': 'first'}).reset_index()

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=False)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)

### Under 65 - highest mean

df2['Location'] = df2['GEO.display_label']

df2_filtered = df2[df2['Location'].str.contains('Holmes County, Ohio', case=False, na=False)]

# Calculate the ALICE_or_lower_rate and round the result
df2_filtered['ALICE_or_lower_rate'] = np.round(((df2_filtered['Poverty Households'] + df2_filtered['ALICE Households']) / df2_filtered['Households']) * 100)

# Group by 'Year' and 'Location' and aggregate the ALICE_or_lower_rate
df2_grouped = df2_filtered.groupby(['Year', 'Location']).agg({'ALICE_or_lower_rate': 'first'}).reset_index()

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=False)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)


### Over 65 - lowest mean

df2['Location'] = df2['GEO.display_label']

df2_filtered = df2[df2['Location'].str.contains('Mercer County, Ohio', case=False, na=False)]

# Calculate the ALICE_or_lower_rate and round the result
df2_filtered['ALICE_or_lower_rate'] = np.round(((df2_filtered['Poverty Households'] + df2_filtered['ALICE Households']) / df2_filtered['Households']) * 100)

# Group by 'Year' and 'Location' and aggregate the ALICE_or_lower_rate
df2_grouped = df2_filtered.groupby(['Year', 'Location']).agg({'ALICE_or_lower_rate': 'first'}).reset_index()

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=False)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=True)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)

### Over 65 - highest mean

df2['Location'] = df2['GEO.display_label']

df2_filtered = df2[df2['Location'].str.contains('Warren County, Ohio', case=False, na=False)]

# Calculate the ALICE_or_lower_rate and round the result
df2_filtered['ALICE_or_lower_rate'] = np.round(((df2_filtered['Poverty Households'] + df2_filtered['ALICE Households']) / df2_filtered['Households']) * 100)

# Group by 'Year' and 'Location' and aggregate the ALICE_or_lower_rate
df2_grouped = df2_filtered.groupby(['Year', 'Location']).agg({'ALICE_or_lower_rate': 'first'}).reset_index()

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=False)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=True)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)


### Under 65 - min

df2['Location'] = df2['GEO.display_label']

df2_filtered = df2[df2['Location'].str.contains('Wyandot County, Ohio', case=False, na=False)]

# Calculate the ALICE_or_lower_rate and round the result
df2_filtered['ALICE_or_lower_rate'] = np.round(((df2_filtered['Poverty Households'] + df2_filtered['ALICE Households']) / df2_filtered['Households']) * 100)

# Group by 'Year' and 'Location' and aggregate the ALICE_or_lower_rate
df2_grouped = df2_filtered.groupby(['Year', 'Location']).agg({'ALICE_or_lower_rate': 'first'}).reset_index()

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=False)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=True)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)


### Under 65 - max

df2['Location'] = df2['GEO.display_label']

df2_filtered = df2[df2['Location'].str.contains('Crawford County, Ohio', case=False, na=False)]

# Calculate the ALICE_or_lower_rate and round the result
df2_filtered['ALICE_or_lower_rate'] = np.round(((df2_filtered['Poverty Households'] + df2_filtered['ALICE Households']) / df2_filtered['Households']) * 100)

# Group by 'Year' and 'Location' and aggregate the ALICE_or_lower_rate
df2_grouped = df2_filtered.groupby(['Year', 'Location']).agg({'ALICE_or_lower_rate': 'first'}).reset_index()

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=False)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=True)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)


### Over 65 - min

df2['Location'] = df2['GEO.display_label']

df2_filtered = df2[df2['Location'].str.contains('Guernsey County, Ohio', case=False, na=False)]

# Calculate the ALICE_or_lower_rate and round the result
df2_filtered['ALICE_or_lower_rate'] = np.round(((df2_filtered['Poverty Households'] + df2_filtered['ALICE Households']) / df2_filtered['Households']) * 100)

# Group by 'Year' and 'Location' and aggregate the ALICE_or_lower_rate
df2_grouped = df2_filtered.groupby(['Year', 'Location']).agg({'ALICE_or_lower_rate': 'first'}).reset_index()

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=False)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=True)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)

### Over 65 - max

df2['Location'] = df2['GEO.display_label']

df2_filtered = df2[df2['Location'].str.contains('Crawford County, Ohio', case=False, na=False)]

# Calculate the ALICE_or_lower_rate and round the result
df2_filtered['ALICE_or_lower_rate'] = np.round(((df2_filtered['Poverty Households'] + df2_filtered['ALICE Households']) / df2_filtered['Households']) * 100)

# Group by 'Year' and 'Location' and aggregate the ALICE_or_lower_rate
df2_grouped = df2_filtered.groupby(['Year', 'Location']).agg({'ALICE_or_lower_rate': 'first'}).reset_index()

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=False)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=True)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)


### Crawford county has the highest threshold for all age group, and the worst poverty rate is 52% in 2022

### Check with Franklin, Delware, and Licking counties since these are the focus

# Franklin 2022
df2['Location'] = df2['GEO.display_label']

df2_filtered = df2[df2['Location'].str.contains('Franklin County, Ohio', case=False, na=False)]

# Calculate the ALICE_or_lower_rate and round the result
df2_filtered['ALICE_or_lower_rate'] = np.round(((df2_filtered['Poverty Households'] + df2_filtered['ALICE Households']) / df2_filtered['Households']) * 100)

# Group by 'Year' and 'Location' and aggregate the ALICE_or_lower_rate
df2_grouped = df2_filtered.groupby(['Year', 'Location']).agg({'ALICE_or_lower_rate': 'first'}).reset_index()

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=False)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)


# Sort the DataFrame by 'ALICE_or_lower_rate' in descending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=True)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)


# Delaware 2022
df2['Location'] = df2['GEO.display_label']

df2_filtered = df2[df2['Location'].str.contains('Delaware County, Ohio', case=False, na=False)]

# Calculate the ALICE_or_lower_rate and round the result
df2_filtered['ALICE_or_lower_rate'] = np.round(((df2_filtered['Poverty Households'] + df2_filtered['ALICE Households']) / df2_filtered['Households']) * 100)

# Group by 'Year' and 'Location' and aggregate the ALICE_or_lower_rate
df2_grouped = df2_filtered.groupby(['Year', 'Location']).agg({'ALICE_or_lower_rate': 'first'}).reset_index()

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=False)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)


# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=True)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)


# Licking 2022
df2['Location'] = df2['GEO.display_label']

df2_filtered = df2[df2['Location'].str.contains('Licking County, Ohio', case=False, na=False)]

# Calculate the ALICE_or_lower_rate and round the result
df2_filtered['ALICE_or_lower_rate'] = np.round(((df2_filtered['Poverty Households'] + df2_filtered['ALICE Households']) / df2_filtered['Households']) * 100)

# Group by 'Year' and 'Location' and aggregate the ALICE_or_lower_rate
df2_grouped = df2_filtered.groupby(['Year', 'Location']).agg({'ALICE_or_lower_rate': 'first'}).reset_index()

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=False)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)

df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=True)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)

### Threshold, survival and stability budget

# Manually extract the data

# Franklin
print("\nFranklin")
data_values = [
    ('Single Adult', '$30,084'),
    ('One Adult One Child', '$46,932'),
    ('One Adult One Childcare', '$54,480'),
    ('Two Adults', '$44,700'),
    ('Two Adults Two Children', '$73,524'),
    ('Two Adults Two Childcare', '$91,284'),
    ('Single Senior', '$34,644'),
    ('Two Seniors', '$54,468')
]


df_data = pd.DataFrame(data_values, columns=['Name', 'ANNUAL TOTAL'])
df_data['ANNUAL TOTAL'] = df_data['ANNUAL TOTAL'].str.replace('$', '').str.replace(',', '').astype(float)

under_65 = df1.loc[df1['County'] == 'Franklin', 'ALICE Threshold - HH under 65'].values[0]
over_65 = df1.loc[df1['County'] == 'Franklin', 'ALICE Threshold - HH 65 years and over'].values[0]

filtered_data = df_data[df_data['ANNUAL TOTAL'] <= under_65]
print(filtered_data, under_65)

filtered_data = df_data[df_data['ANNUAL TOTAL'] <= over_65]
print(filtered_data, over_65)

# Delaware
print("\nDelaware")
data_values = [
    ('Single Adult', '$31,560'),
    ('One Adult One Child', '$48,720'),
    ('One Adult One Childcare', '$56,220'),
    ('Two Adults', '$46,476'),
    ('Two Adults Two Children', '$75,984'),
    ('Two Adults Two Childcare', '$93,660'),
    ('Single Senior', '$35,688'),
    ('Two Seniors', '$55,488')
]

df_data1 = pd.DataFrame(data_values, columns=['Name', 'ANNUAL TOTAL'])
df_data1['ANNUAL TOTAL'] = df_data1['ANNUAL TOTAL'].str.replace('$', '').str.replace(',', '').astype(float)

under_65 = df1.loc[df1['County'] == 'Delaware', 'ALICE Threshold - HH under 65'].values[0]
over_65 = df1.loc[df1['County'] == 'Delaware', 'ALICE Threshold - HH 65 years and over'].values[0]

filtered_data = df_data1[df_data1['ANNUAL TOTAL'] <= under_65]
print(filtered_data, under_65)

filtered_data = df_data1[df_data1['ANNUAL TOTAL'] <= over_65]
print(filtered_data, over_65)

# Licking

print("\nLicking")
data_values = [
    ('Single Adult', '$28,032'),
    ('One Adult One Child', '$43,596'),
    ('One Adult One Childcare', '$49,932'),
    ('Two Adults', '$42,108'),
    ('Two Adults Two Children', '$68,400'),
    ('Two Adults Two Childcare', '$82,404'),
    ('Single Senior', '$32,532'),
    ('Two Seniors', '$51,744')
]

df_data2 = pd.DataFrame(data_values, columns=['Name', 'ANNUAL TOTAL'])
df_data2['ANNUAL TOTAL'] = df_data2['ANNUAL TOTAL'].str.replace('$', '').str.replace(',', '').astype(float)

under_65 = df1.loc[df1['County'] == 'Licking', 'ALICE Threshold - HH under 65'].values[0]
over_65 = df1.loc[df1['County'] == 'Licking', 'ALICE Threshold - HH 65 years and over'].values[0]

filtered_data = df_data2[df_data2['ANNUAL TOTAL'] <= under_65]
print(filtered_data, under_65)

filtered_data = df_data2[df_data2['ANNUAL TOTAL'] <= over_65]
print(filtered_data, over_65)

### Those who live alone struggles to meet with the survival budget

# Franklin
print("\nFranklin")
data = {
    'Name': ['Single Adult', 'Two Adults', 'Two Adults Two Children', 'Two Adults Two Childcare'],
    'ANNUAL TOTAL': ['$51,432', '$74,952', '$124,632', '$148,392']
}

df_data3 = pd.DataFrame(data)
df_data3['ANNUAL TOTAL'] = df_data3['ANNUAL TOTAL'].str.replace('$', '').str.replace(',', '').astype(float)

under_65 = df1.loc[df1['County'] == 'Franklin', 'ALICE Threshold - HH under 65'].values[0]
over_65 = df1.loc[df1['County'] == 'Franklin', 'ALICE Threshold - HH 65 years and over'].values[0]

df_data3['difference'] = df_data3['ANNUAL TOTAL'] - under_65
print(df_data3[['Name', 'difference']])


# Delaware
print("\nDelaware")
data_values = {
    'Name': ['Single Adult', 'Two Adults', 'Two Adults Two Children', 'Two Adults Two Childcare'],
    'ANNUAL TOTAL': ["$53,652","$77,892","$142,788","$166,896"]

}

df_data4 = pd.DataFrame(data)
df_data4['ANNUAL TOTAL'] = df_data4['ANNUAL TOTAL'].str.replace('$', '').str.replace(',', '').astype(float)

under_65 = df1.loc[df1['County'] == 'Delaware', 'ALICE Threshold - HH under 65'].values[0]
over_65 = df1.loc[df1['County'] == 'Delaware', 'ALICE Threshold - HH 65 years and over'].values[0]

df_data4['difference'] = df_data4['ANNUAL TOTAL'] - under_65
print(df_data4[['Name', 'difference']])


# Licking
print("\nLicking")
data_values = {
    'Name': ['Single Adult', 'Two Adults', 'Two Adults Two Children', 'Two Adults Two Childcare'],
    'ANNUAL TOTAL': ["$48,360","$70,788","$117,036","$133,044"]

}

df_data5 = pd.DataFrame(data)
df_data5['ANNUAL TOTAL'] = df_data5['ANNUAL TOTAL'].str.replace('$', '').str.replace(',', '').astype(float)

under_65 = df1.loc[df1['County'] == 'Licking', 'ALICE Threshold - HH under 65'].values[0]
over_65 = df1.loc[df1['County'] == 'Licking', 'ALICE Threshold - HH 65 years and over'].values[0]

df_data5['difference'] = df_data5['ANNUAL TOTAL'] - under_65
print(df_data5[['Name', 'difference']])

# The gap to catch up to is large, ranging from 10000 to more than 100000$ for the under 65 group

df2['Location'] = df2['GEO.display_label']

df2_filtered = df2[df2['Location'].str.contains('Delaware County, Ohio', case=False, na=False)]

# Calculate the ALICE_or_lower_rate and round the result
df2_filtered['ALICE_or_lower_rate'] = np.round(((df2_filtered['Poverty Households'] + df2_filtered['ALICE Households']) / df2_filtered['Households']) * 100)

# Group by 'Year' and 'Location' and aggregate the ALICE_or_lower_rate
df2_grouped = df2_filtered.groupby(['Year', 'Location']).agg({'ALICE_or_lower_rate': 'first'}).reset_index()

# Sort the DataFrame by 'ALICE_or_lower_rate' in ascending order
df2_sorted = df2_grouped.sort_values(by='ALICE_or_lower_rate', ascending=False)

# Limit the DataFrame to the first 10 rows
df2_limited = df2_sorted.head(10)

# Display the result
print(df2_limited)