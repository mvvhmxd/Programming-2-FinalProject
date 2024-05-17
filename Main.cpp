#include "StudentManagementSystem.h"
#include "FileHandler.h"
#include "Admin.h"
#include "Menu.h"
#include <iostream>
using namespace std;

int main() {
    // System setup
    string adminPassword = PasswordManager::encrypt_password("admin123");
    StudentManagementSystem sms(adminPassword);
    FileHandler fh("project.txt");
    Admin admin("admin", adminPassword);

    // Load students from file
    vector<Student> loaded_students = fh.load_data();
    for (auto& student : loaded_students) {
        sms.add_student_record(student);
    }

    // Start the menu
    Menu menu(sms, fh, admin);
    menu.run();

    return 0;
}
