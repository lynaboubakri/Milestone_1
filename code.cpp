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

    //Display CSV
    displayCSV(table, rowCount, columnNames, numCols);

    cout << "\n-------------------------------------------\n";
    cout << "End of Milestone 1 Output\n";
    cout << "-------------------------------------------\n";

    return 0;
}
