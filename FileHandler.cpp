// FileHandler.cpp
#include "FileHandler.h"
#include <fstream>
#include <sstream>
using namespace std;

FileHandler::FileHandler(const string& path) : file_path(path) {}

void FileHandler::save_data(const vector<Student>& students) {
    ofstream file(file_path);
    for (const auto& student : students) {
        file << student.student_id << "," << student.name << "," << student.grade << "\n";
        for (const auto& mark : student.marks) {
            file << mark.first << "," << mark.second << "\n";
        }
    }
    file.close();
}

vector<Student> FileHandler::load_data() {
    vector<Student> students;
    ifstream file(file_path);
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string student_id, name, grade;
        getline(iss, student_id, ',');
        getline(iss, name, ',');
        getline(iss, grade, ',');
        Student student(student_id, name);
        student.grade = grade[0];
        students.push_back(student);
    }
    file.close();
    return students;
}