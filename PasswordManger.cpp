#include "PasswordManger.h"
#include <cctype>
#include <numeric>
using namespace std;

bool PasswordManager::validate_password(const string& password) {
    if (password.size() < 8) {
        return false;
    }
    bool has_digit = false, has_upper = false, has_lower = false;

    for (char c : password) {
        if (isdigit(c)) has_digit = true;
        else if (isupper(c)) has_upper = true;
        else if (islower(c)) has_lower = true;
    }
    return has_digit && has_upper && has_lower;
}

string PasswordManager::encrypt_password(const string& password) {
    string encrypted;
    for (char c : password) {
        encrypted += static_cast<char>(c + 3); // Simple Caesar cipher for example purposes
    }
    return encrypted;
}