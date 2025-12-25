#include <iostream>
#include <string>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 10;

//Function Prototypes
void createSheetName(string &sheetName);
void setupColumns(string colNames[], string colTypes[], int &numCols);
void insertRow (string table[][MAX_COLS], int &rowCount, string colTypes[], int numCols);
void displayCSV (string table[][MAX_COLS], int rowCount, string colNames[], int numCols); 
// is validint function
bool isValidInt(const string& str) {
if (str.empty()) {
return false;
}
int startIndex = 0;
if (str.[0] == '-') { // if first character is a minus sign
if (str.length() == 1) { // if its only a minus sign (no digits)
return false; // thats not valid
}
startIndex = 1;
}
for (int i = startIndex; i < str.length(); i++) {
if (!isdigit(str[i])) { // if this character is not a digit (0-9)
return false; // Invalid - return false
}
}
return ture; // all characters are digits - its valid
}
int main() {
    string sheetName;
    string columnNames[MAX_COLS];
    string columnTypes[MAX_COLS];
    string table[MAX_ROWS][MAX_COLS];
    int numCols = 0;
    int rowCount = 0;
    int add = 1;

    cout << "===========================================\n";
    cout << "   STUDENT ATTENDANCE TRACKER - MILESTONE 1\n";
    cout << "===========================================\n\n";

    //Sheet name
    createSheetName(sheetName);

    //Column setup
    setupColumns(columnNames, columnTypes, numCols);

    //Rows insertion 
    while(add==1 && rowCount<MAX_ROWS){
        insertRow(table, rowCount, columnTypes, numCols);
        
        //Giving the user an option to insert a new row
        cout << "Do you want to insert another row? (0 = No, 1 = Yes): ";
        cin >> add;
        
        if (add!=0 && add!=1){
            cout <<"Error: please enter 0 or 1 only\n";
            add = 1;
        }
    }

    // implementation of the display in CSV mode 

void displayCSV ( string table [] [MAX_COLS] , int rowCount , string colNames []  , int numCols)
{ 
    cout << "___________________________________________________\n" ;
    cout << "             View Attendace sheet \n" ;
    cout << "___________________________________________________\n" ;

    // Display the names of columns 
    for ( int i =0 ; i < numCols ; i++)
    { 
        cout << colNames [i] ;
        if (i< numCols - 1)
         cout << " , " ;
    }
    cout << endl ; 
    
    // Displat of the lines 
    for ( int r = 0 ; r < rowCount ; r++)
    {
        for ( int c = 0 ; c < numCols; c++)
        { 
            cout << table[r] [c] ;
             if ( c < numCols - 1) 
             cout << " , "  ;
        }
        cout << endl;
    }
}

    //Display CSV
    displayCSV(table, rowCount, columnNames, numCols);

    cout << "\n___________________________________________________\n";
    cout << "           End of Milestone 1 Output\n";
    cout << "___________________________________________________\n";

    return 0;
}


// insertRow implementation
void insertRow (string table[][MAX_COLS], int &rowCount, string colTypes[], int cumCols)
cout << "\n___________________________________________________\n";
cout << "              Insert New Attendance Row\n";
cout << "___________________________________________________\n";
string input;
for (int col =0; col < numCols; col++) { // loop through each column
if (colTpes[col] == "INT") { // If this column is an integer
while (true) { // keep looping until we get a valid input
cout << "Enter column " << (col + 1) << " value: ";
cin >> input; // Gets input string
if (isValidInt(input)) { // Check if its a valid integer using function
table[rowCount][col] = input; // store it into the table at current row
break; // Exit the loop - we got a valid input
} else {
cout << "Error: Invaldi INT value. Please enter a number.\n"; // show error
}
}
}
else if (colTpes[col] == "TEXT") { // if this column needs text
cout << "Enter column " << (col + 1) << " value: ";
cin.ignore ();
getline(cin, input); // reads the entire line including spaces
while (input.empty()) {
cout << "Error: Value cannot be empty.\n";
cout << Enter column " << (col + 1) << " value: ";
getline(cin. input); // Ask again
}
table[rowCount][col] = input; // stores the text in the table
}
}
rowCount++; // Increase row count because we just a row
cout << "Row inserted successfully.\n";
}
