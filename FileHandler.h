#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Student.h"
#include <vector>
#include <string>
using namespace std;

class FileHandler {
private:
    string file_path;

public:
    explicit FileHandler(const string& path);
    void save_data(const vector<Student>& students);
    vector<Student> load_data();
};

#endif