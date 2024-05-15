#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "Student.h"
#include <vector>
#include <string>
using namespace std;

class SearchEngine {
private:
    vector<Student>& students;

public:
    explicit SearchEngine(vector<Student>& students);
    Student* search_by_id(const string& id);
    vector<Student*> search_by_name(const string& name);
};

#endif