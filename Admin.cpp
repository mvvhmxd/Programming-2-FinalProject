#include "Admin.h"
using namespace std;

Admin::Admin(const string& username, const string& password)
    : username(username), password(password) {}

bool Admin::login(const string& input_username, const string& input_password) {
    return username == input_username && password == input_password;
}

void Admin::logout() {
    // Cleanup or log logout events
}

bool Admin::change_password(const string& old_password, const string& new_password) {
    if (password == old_password) {
        password = new_password;
        return true;
    }
    return false;
}
