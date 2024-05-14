#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <map>
using namespace std;

class Student {
public:
    string student_id;
    string name;
    map<string, int> marks;
    char grade;
    Student(string id, string name);
    void add_marks(const string& subject, int score);
    void calculate_grade();
};

#endif


