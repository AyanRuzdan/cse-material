## Question Statement
DataFrame `weather`

| Column Name | Type   |
| ----------- | ------ |
| city        | object |
| month       | object |
| temperature | int    |
Write a solution to **pivot** the data so that each row represents temperatures for a specific month, and each city is a separate column.
## Example
Example 1:
**Input**:

| city         | month    | temperature |
| ------------ | -------- | ----------- |
| Jacksonville | January  | 13          |
| Jacksonville | February | 23          |
| Jacksonville | March    | 38          |
| Jacksonville | April    | 5           |
| Jacksonville | May      | 34          |
| ElPaso       | January  | 20          |
| ElPaso       | February | 6           |
| ElPaso       | March    | 26          |
| ElPaso       | April    | 2           |
| ElPaso       | May      | 43          |
**Output:**

| month | ElPaso | Jacksonville |
|---|---|---|
| April | 2      | 5            |
| February | 6   | 23  |
| January | 20  | 13  |
| March | 26  | 38  |
| May | 43  | 34  | 
## Approach
We use the pivot function provided in the pandas library to pivot the dataframe, specifying which column to be the index, which values to become the columns, and which values to be distributed among the new columns
## Code
```python
import pandas as pd
def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    return weather.pivot(index='month',columns='city',values='temperature')
```