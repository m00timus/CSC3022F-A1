#ifndef Database_H  //prevent the header file from getting included twice in the same project.
#define Database_H
#include<cstdlib>
#include<vector>
#include<string>

namespace GRLMAT001
{


//methods are normally public, otherwise you will not be able to use these methods outside of the class
    
    void add_student();
    void read_database();
    void save_database();
    void display_data();
    void grade_student();
    void clear(void) { system("clear"); } // include cstdlib

    std::string name;
    std::string surname;
    std::string studentno;
    std::string classrecord;
    std::string filename = "data.txt";

    struct studentRecord    {
        std::string name, surname, studentno, classrecord;
    };
    studentRecord sr;
    std::vector <studentRecord> v;


};  //end the definition with a '};'

#endif //everything between #ifdef/#ifndef and #endif is ignored if the #if... is not TRUE
