#ifndef MARKSHEET_H
#define MARKSHEET_H

#include "Student.h"
#include <iostream>
#include <string>

class MarkSheet {
private:
    Student& student;
    int totalMarks;    // Total marks obtained by the student
    double averageScore; // Average score of the student

public:
    explicit MarkSheet(Student& student);
    void calculate();  // Calculate total marks and average
    void display();    // Display the mark sheet
};

#endif 