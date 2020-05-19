#include <iostream> //for cout,
#include <fstream>  // Needed for file stream objects
#include <algorithm>
#include <vector>
#include <sstream>  // Needed for string stream objects
#include <string>
#include "Database_H.h"

using namespace std;
//MyClass c;

int main(int argc, char* argv[]) { //type exactly like this, allows for parameters to be passed to your program
//main method for program
    for(;;) {

        int opt;

        cout << endl << "welcome to the student centre" << endl;
        cout << endl << "-----------------------------" << endl;
        cout << endl << "1. add student" << endl;
        cout << endl << "2. read database" << endl;
        cout << endl << "3. save database" << endl;
        cout << endl << "4. display given student data" << endl;
        cout << endl << "5. grade student" << endl;
        cout << endl << "0: quit" << endl;


        cin >> opt;
        cout << "\n" << endl;
        //c.clear();

        switch (opt) {

            case 1:
                GRLMAT001::add_student();
                break;
            case 2:
                GRLMAT001::read_database();
                break;
            case 3:
                GRLMAT001::save_database();
                break;
            case 4:
                GRLMAT001::display_data();
                break;
            case 5:
                GRLMAT001::grade_student();
                break;
            case 0:
                exit(0);
            default:
                break;
        }
    //c.clear();
    }
    return 0;
    }

void GRLMAT001::add_student() {
//adds new student, or updates old entry    
    bool contains = false;;
    cout << endl << "enter first name: " << endl;
    cin >> sr.name;

    cout << endl << "enter surname: " << endl;
    cin >> sr.surname;

    cout << endl << "enter student number: " << endl;
    cin >> sr.studentno;

    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
        //discard characters until newline is found

    cout << endl << "enter class record ( separated by a " " ): " << endl;
    getline(cin, sr.classrecord);
 
    for (auto &element:v)
    {
        if (element.studentno == sr.studentno)
        {
            contains = true;
            element.name = sr.name;
            element.surname = sr.surname;
            element.studentno = sr.studentno;
            element.classrecord = sr.classrecord;
            //cout << element.classrecord;
        } else { }  
    }

    if (contains)
    {
        cout << endl << "student number already exists. updating data..." << endl;
        cout << endl << "Data was added to the student database. " << endl;
    }
    
    else if(!contains)
    {
        cout << endl << "New data detected. " << endl;
        v.push_back(sr);
        cout << endl << "Data was added to the student database. " << endl;
    }
    
    
    
    }

void GRLMAT001::read_database() {
//reads from txt file into vector 

	ifstream in(filename);
    std::string line;

    while (std::getline(in, line)) {
      // Parse the line using a string stream
      std::istringstream row(line);
      std::string field;

      row >> field;
      sr.name = field;

      row >> field;
      sr.surname = field;

      row >> field;
      sr.studentno = field;

      while (row >> field) {
	  	//cout << field + "\n";
        classrecord = classrecord + " " + field;
      }
      sr.classrecord = classrecord;
      classrecord = "";
      v.push_back(sr);
    }
	in.close();
    cout << "Database succesfully read.";
    }

void GRLMAT001::save_database() {
//writes from vector into txt file   
    std::ofstream out("./data.txt");
    for (int i = 0; i < v.size(); i++) 
    { out << v[i].name + " " + v[i].surname + " " + v[i].studentno + " " + v[i].classrecord;  out << endl; }
    cout << "Database successfully saved. ";
    }

void GRLMAT001::display_data() {
//displays the data given a specific student number 
    std::string temp;
    int posit;
    cout << endl << "Enter the student number to locate: " << endl;
    cin >> temp;

    struct find_stdno : std::unary_function<studentRecord, bool> {
    std::string studentno;
    find_stdno(std::string studentno):studentno(studentno) { }
    bool operator()(studentRecord const& m) const {
        return m.studentno == studentno;
    }
    };

    auto it = std::find_if(v.begin(), v.end(), find_stdno(temp));

    if ( it != v.end() ) {
        posit = distance(v.begin(), it);
        cout << endl << "entry found. " << endl;
        cout << endl << "\nName: " << v.at(posit).name;
        cout << endl << "\nSurname: " << v.at(posit).surname;
        cout << endl << "\nStudent Number: " << v.at(posit).studentno;
        cout << endl << "\nClass Record: " << v.at(posit).classrecord;
    }
    else
    {
        cout << endl << "Entry not found. " << endl;
        posit = -1;
    }
    
    }

void GRLMAT001::grade_student() {
//calculates average grade for given student  
    std::string temp;
    int posit;
    int avg = 0;
    
    cout << endl << "Enter the student number to recieve grade average: " << endl;
    cin >> temp;

    struct find_stdno : std::unary_function<studentRecord, bool> {
    std::string studentno;
    find_stdno(std::string studentno):studentno(studentno) { }
    bool operator()(studentRecord const& m) const {
        return m.studentno == studentno;
    }
    };

    auto it = std::find_if(v.begin(), v.end(), find_stdno(temp));

    if ( it != v.end() ) {
        posit = distance(v.begin(), it);
        cout << endl << "entry found. " << endl;
        
        
        std::stringstream iss(v.at(posit).classrecord);
        int count = 0;
        avg = 0;

         do { 
        int subs; 
        // Get the word from the istringstream 
        iss >> subs; 
        avg += subs; 
        count++;

    } while (iss);
        
        avg = avg / count;
        cout << endl << "\ngrade average: " << avg;
        
    }
    else
    {
        cout << endl << "Entry not found. " << endl;
        posit = -1;
    }
    

    }


