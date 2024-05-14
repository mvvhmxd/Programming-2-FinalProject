#include "Student.h"
using namespace std;

Student::Student(string id, string name) : student_id(id), name(name), grade('F') {}

void Student::add_marks(const string& subject, int score) {
    marks[subject] = score;
    calculate_grade();
}

void Student::calculate_grade() {
    int total = 0;
    for (auto& mark : marks) {
        total += mark.second;
    }
    double average = marks.size() > 0 ? static_cast<double>(total) / marks.size() : 0;
    if (average >= 90) {
        grade = 'A';
    }
    else if (average >= 80) {
        grade = 'B';
    }
    else if (average >= 70) {
        grade = 'C';
    }
    else if (average >= 60) {
        grade = 'D';
    }
    else {
        grade = 'F';
    }
}

