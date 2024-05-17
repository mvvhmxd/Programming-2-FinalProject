#ifndef MENU_H
#define MENU_H

#include "StudentManagementSystem.h"
#include "FileHandler.h"
#include "Admin.h"
#include "MarkSheet.h"
#include "PasswordManager.h"

class Menu {
private:
    StudentManagementSystem& sms;
    FileHandler& fh;
    Admin& admin;

public:
    Menu(StudentManagementSystem& sms, FileHandler& fh, Admin& admin);
    void display();
    void run();
};

#endif
