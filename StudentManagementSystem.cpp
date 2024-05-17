#include "StudentManagementSystem.h"
#include <algorithm>
using namespace std;

StudentManagementSystem::StudentManagementSystem(const string& password) : admin_password(password) {}

void StudentManagementSystem::add_student_record(const Student& student) {
    students.push_back(student);
}

Student* StudentManagementSystem::search_student_record(const string& student_id) {
    for (auto& student : students) {
        if (student.student_id == student_id) {
            return &student;
        }
    }
    return nullptr;
}

void StudentManagementSystem::modify_student_record(const string& student_id, const string& subject, int score) {
    Student* student = search_student_record(student_id);
    if (student) {
        student->add_marks(subject, score);
    }
}

void StudentManagementSystem::delete_student_record(const string& student_id) {
    students.erase(remove_if(students.begin(), students.end(),
        [&student_id](const Student& s) { return s.student_id == student_id; }),
        students.end());
}

bool StudentManagementSystem::change_admin_password(const string& old_password, const string& new_password) {
    if (old_password == admin_password) {
        admin_password = new_password;
        return true;
    }
    return false;
}