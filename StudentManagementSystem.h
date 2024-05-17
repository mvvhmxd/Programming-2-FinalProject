#ifndef STUDENTMANAGEMENTSYSTEM_H
#define STUDENTMANAGEMENTSYSTEM_H

#include "Student.h"
#include <vector>
#include <string>
using namespace std;

class StudentManagementSystem {
protected:

    string admin_password;

public:
    vector<Student> students;
    explicit StudentManagementSystem(const string& password);
    void add_student_record(const Student& student);
    Student* search_student_record(const string& student_id);
    void modify_student_record(const string& student_id, const string& subject, int score);
    void delete_student_record(const string& student_id);
    bool change_admin_password(const string& old_password, const string& new_password);
};

#endif