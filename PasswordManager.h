// PasswordManager.h
#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <string>
using namespace std;

class PasswordManager {
public:
    static bool validate_password(const string& password);
    static string encrypt_password(const string& password);
};

#endif
