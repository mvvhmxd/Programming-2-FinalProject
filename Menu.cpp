#include "Menu.h"
#include <iostream>
#include<iostream>
using namespace std;
Menu::Menu(StudentManagementSystem& sms, FileHandler& fh, Admin& admin)
    : sms(sms), fh(fh), admin(admin) {}

void Menu::display() {
    cout << "\n================= Student Management System =================\n";
    cout << "1. Add Student\n";
    cout << "2. Search and Generate MarkSheet\n";
    cout << "3. Modify Student Record\n";
    cout << "4. Delete Student Record\n";
    cout << "5. Change Admin Password\n";
    cout << "6. Exit\n";
    cout << "============================================================\n";
   
}

void Menu::run() {
    char choice;
    do {
        display();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            string id, name, subject;
            int score;
            cin.ignore();
            cout << "Enter student ID: ";
            getline(cin, id);
            cout << "Enter student name: ";
            getline(cin, name);
            Student new_student(id, name);
            sms.add_student_record(new_student);

            cout << "Enter subjects and scores (type 'done' to finish):\n";
            while (true) {
                cout << "Subject: ";
                getline(cin, subject);
                if (subject == "done") break;
                cout << "Score: ";
                cin >> score;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline after integer input
                sms.modify_student_record(id, subject, score);
            }
            break;
        }
        case '2': {
            string id;
            cout << "Enter student ID: ";
            cin >> id;
            Student* student = sms.search_student_record(id);
            if (student) {
                MarkSheet ms(*student);
                ms.display();
            }
            else {
                cout << "Student not found.\n";
            }
            break;
        }
        case '3': {
            string id, subject;
            int score;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter subject: ";
            cin >> subject;
            cout << "Enter score: ";
            cin >> score;
            sms.modify_student_record(id, subject, score);
            break;
        }
        case '4': {
            string id;
            cout << "Enter student ID: ";
            cin >> id;
            sms.delete_student_record(id);
            cout << "Record Deleted successfully.\n";
            break;
        }
        case '5': {
            string oldPass, newPass;
            cout << "Enter old password: ";
            cin >> oldPass;
            cout << "Enter new password: ";
            cin >> newPass;
            if (admin.change_password(oldPass, newPass)) {
                cout << "Password changed successfully.\n";
            }
            else {
                cout << "Failed to change password. Ensure your old password is correct.\n";
            }
            break;
        }
        case '6':
            fh.save_data(sms.students);
            cout << "Exiting and saving data...\n";
            break;
        default:
            cout << "Invalid option, try again!\n";
        }
    } while (choice != '6');
}
