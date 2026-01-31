//calling libraries
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>

using namespace std;

const int MAX_ROWS = 1000;

struct Attendance{
    int studentID;
    string name;
    int status; //0=absent, 1=present
};

Attendance sheet[MAX_ROWS];
int rowCount=0;

//function prototypes
void showHeader();
void showMenu();
void createTerm(string &termName);
bool loadAttendance(string filename);
bool insertAttendance(string filename);
void displayAttendance();
bool updateAttendanceRow(int id, int newStatus);
bool deleteAttendanceRow(int id);
int countRows();
void saveToFile(const string& filename);

//Error handling function prototypes
int validInt();
int validStatus();
string validName();
string validFilename();
bool studentExists(int id);

//main function
int main(){
    //declaring variables
    string termName, filename;
    int choice, id, status;
    //following a logical flow to display the code
    //show the header of the file 
    showHeader();
    //ask the user to enter the name of the term
    createTerm(termName);
    cout<<"Successfully loaded: "<<filename;
    cout <<"Enter attendance file name: ";
    //check the validity of the file name
    filename = validFilename();
    if(!loadAttendance(filename)){
        cout<<"Error loading file"<<endl;
        return 0;
    }
    //enter the loop at least once
    do{
        //display the menu for user so they can choose which task should be done by the code
        showMenu();
        choice=validInt();
        switch(choice){
            //allow the user to enter the data : student name, student ID and attendance statuts
            case 1:
                insertAttendance(filename);
                break;
            //display the attendance for the user
            case 2:
                displayAttendance();
                break;
            //allow the user to update the attendance status of the student
            case 3:{
                cout<<"Enter StudentID to update: ";
                id=validInt();
                //check the existence of the student ID
                if(!studentExists(id)){
                    cout<<"Error:  StudentID not found"<<endl;
                    break;
                }
                //check the validity of the input (0 or 1 only)
                status=validStatus();
                if(updateAttendanceRow(id,status))
                        cout<<"Row updated successfully"<<endl;
                break;
            }
            //allow the user to delete a row from the data
            case 4:{
                cout<<"Enter StudentID to delete: ";
                //check the balidity of the ID (accept only numbers)
                id=validInt();
                if(deleteAttendanceRow(id))
                    cout<<"Row deleted successfully"<<endl;
                else
                    cout<<"Error:  StudentID not found"<<endl;
                break;
            }
            //count and display the number of rows inserted by the user
            case 5:
                cout<<"Number of rows: "<<countRows()<<endl;
                break;
            //save the data to a CSV file
            case 6 :{
                cout << "Enter output file name: ";
                string outFile = validFilename();
                 if (saveToFile(outFile))
                    cout << "Output saved as: " << outFile << endl;
                 break;
            }
            //exit the code 
            case 0:
                cout<<"Exiting program..."<<endl;
                break;
            default:
                cout<<"Invalid choice, try again"<<endl;
        } 
    } while(choice!=0);
    return 0;
}

//display the header of the file
void showHeader(){
    cout<< "===========================================\n";
    cout<< "   STUDENT ATTENDANCE TRACKER - MILESTONE 2\n";
    cout<< "===========================================\n";
}

//display a menu to ease and improve user experience
void showMenu(){
    cout<< "\n__________________ MENU __________________\n";
    cout<< "1. Insert Attendance\n";
    cout<< "2. View Attendance\n";
    cout<< "3. Update Row\n";
    cout<< "4. Delete Row\n";
    cout<< "5. Count Rows\n";
    cout<< "6. Save To File\n";
    cout<< "0. Exit\n";
    cout<< "Enter choice: ";
}
int validInt(){
    int x;
    while (true) {
        cin >> x;
        if (cin.fail()) {
            cout << "Invalid number. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else {
            cin.ignore(1000, '\n');
            return x;
        }
    }
}

int validStatus(){
    int s;
    while (true) {
        cin >> s;
        if (!cin.fail() && (s==0 || s==1)) {
            cin.ignore(1000, '\n');
            return s;
        }
        cin.clear();
        cin.ignore(1000, '\n');
    }
}
string validName() {
    string name;
    while (true) {
        getline(cin, name);
        //empty inputs are rejected
        if (name.empty()) {
            cout << "Cannot be empty. Try again: ";
            continue;
        }
        bool valid = true;
        for (int i=0; i < name.length(); i++) {
            //allows only letters, spaces ' ', slashes '/' and apostrophes "'"
            //Some names can contain '/' or "'" :e.g.: "Aisyah’Nur" or "Siti/Nurul"
            if (!isalpha(name[i]) && name[i]!=' ' && name[i]!='/' && name[i]="'") {
                valid = false;
                break;
            }
        }
        if (valid)
            return name;
        cout << "Name must contain letters or '/' or an apostrophe only (spaces allowed). Try again: ";
    }
}
string validFilename() {
    string filename;
    while (true) {
        getline(cin, filename);
        //check if the file is empty
        if (filename.empty()) {
            cout << "Filename cannot be empty. Try again: ";
            continue;
        }
        bool valid = true;
        //loop through each character of the string
        for (int i=0; i<filename.length(); i++) {
            char c = filename[i];
            //allows letters, numbers, underscore '_' and dots '.'
            if (!isalnum(c) && c!='_' && c!='.') {
                valid = false;
                break;
            }
        }
        if (valid)
            return filename;
        cout << "Filename can only contain letters, numbers, underscores, and dots. Try again: ";
    }
}
bool studentExists(int id) {
    //loop through the sheet array to check the existence of the ID
    for (int i=0; i<rowCount; i++) {
        //if the ID is found it returns true
void displayAttendance() {
    cout << "\n___________________________________________________\n" ;
    cout << "           Current Attendance Sheet\n" ;
    cout << "___________________________________________________\n" ;

    for (int i = 0; i < rowCount; i++) {
        cout << sheet[i].studentID << ","
            << sheet[i].name << ","
            << sheet[i].status << endl;

    }
    cout << endl;
}
 bool updateAttendanceRow(int id, int newStatus) {
     for (int i = 0; i < rowCount; i++) {
        if (sheet[i].studentID==id) {
            sheet[i].status = newStatus;

            cout << "\nUpdated Sheet:\n";
            displayAttendance();
                
            return true;
    }
    return false;
}
bool deleteAttendanceRow(int id) {
    int foundIndex = -1;
    for (int i = 0; < rowCount; i++) {
if (sheet[i].studentID == id) {
foundIndex = i;
break;
}
    }
if (foundIndex == -1) {
return false;
}
for (int i = foundIndex; < rowCount - 1; i++) {
    sheet[i] = sheet[i + 1];
}
rowCount--;
cout << "\nUpdated Sheet:\n";
displayAttendance();
return true;
}
void createTerm(string &termName){
    cout<<"Enter term name: ";
    //check if the input is valid or not
    termName=validFilename();
    cout<<"Database \"" << termName << "\" created and loaded.\n";
    cout<<"Reading attendance data from file...\n";
}
}
int countRow() {
    return rowCount;
}
bool saveToFile(string filename) {
    //create output file stream
    ofstream fout(filename);
    //write header first
    file<< "StudentID,Name,Status\n";
    //write rows
    for (int i=0; i<rowCount; i++) {
        fout << sheet[i].studentID << ","
             << sheet[i].name << ","
             << sheet[i].status << "\n";
    }
    //close the file
    file.close();
}
