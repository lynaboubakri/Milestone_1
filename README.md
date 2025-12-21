# Milestone_1
**Global Constants:**
- MAX_ROWS:
  Maximum number of attendance records that can be stored (e.g. 100 students).

- MAX_COLS:
  Maximum number of columns allowed in the attendance sheet (10 as required).

**Main Variables Used**
- sheetName (string):
Stores the name of the attendance sheet entered by the user.

- columnNames[MAX_COLS] (string array):
Stores the names of each column (e.g. StudentID, Name, Status).

- columnTypes[MAX_COLS] (string array):
Stores the data type of each column (INT or TEXT).

- table[MAX_ROWS][MAX_COLS] (string 2D array):
Stores the actual attendance data. Each row represents one student record.

- numCols (int):
Stores the number of columns defined by the user.

- rowCount (int):
Tracks how many rows have been inserted into the table.

- add (int):
  To check if the user wants to insert another row or no (0 = No, 1 = Yes).

**Function Explanations**

- createSheetName(string &sheetName):
Prompts the user to enter the attendance sheet name and stores it in the sheetName variable.

- setupColumns(string colNames[], string colTypes[], int &numCols):
Allows the user to define the number of columns (maximum 10).

*For each column, the user enters:*

- Column name

- Column data type (INT or TEXT)
  The function stores this information in the columnNames and columnTypes arrays.

- insertRow(string table[][MAX_COLS], int &rowCount, string colTypes[], int numCols)

Inserts one attendance record into the table.
For each column:

- Prompts the user for input
- Validates input if the column type is INT
- Stores the data in the table

After insertion, rowCount is increased.

- displayCSV(string table[][MAX_COLS], int rowCount, string colNames[], int numCols)
  Displays the attendance sheet in CSV format.
  First prints column names, then prints all inserted rows separated by commas.
