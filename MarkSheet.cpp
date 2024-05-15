#include "MarkSheet.h"
using namespace std;

MarkSheet::MarkSheet(Student& student) : student(student), totalMarks(0), averageScore(0.0) {}

void MarkSheet::calculate() {
    totalMarks = 0;
    for (const auto& mark : student.marks) {
        totalMarks += mark.second;
    }
    averageScore = student.marks.empty() ? 0 : static_cast<double>(totalMarks) / student.marks.size();
}

void MarkSheet::display() {
    calculate();  
    cout << "Mark Sheet for " << student.name << " (ID: " << student.student_id << ")\n";
    for (const auto& mark : student.marks) {
        cout << mark.first << ": " << mark.second << "\n";
    }
    cout << "Total Marks: " << totalMarks << "\n";
    cout << "Average Score: " << averageScore << "\n";
    cout << "Grade: " << student.grade << "\n";
}