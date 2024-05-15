#include "SearchEngine.h"
using namespace std;

SearchEngine::SearchEngine(vector<Student>& students) : students(students) {}

Student* SearchEngine::search_by_id(const string& id) {
    for (Student& student : students) {
        if (student.student_id == id) {
            return &student;
        }
    }
    return nullptr; // Return null if no student found
}

vector<Student*> SearchEngine::search_by_name(const string& name) {
    vector<Student*> foundStudents;
    for (Student& student : students) {
        if (student.name == name) {
            foundStudents.push_back(&student);
        }
    }
    return foundStudents; // Return a vector of pointers to found students
}