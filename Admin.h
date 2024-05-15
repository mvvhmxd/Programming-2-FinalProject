#ifndef ADMIN_H
#define ADMIN_H
using namespace std;
#include <string>

class Admin {
private:
    string username;
    string password;

public:
    Admin(const string& username, const string& password);
    bool login(const string& username, const string& password);
    void logout();
    bool change_password(const string& old_password, const string& new_password);
};

#endif

