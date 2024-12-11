#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

string assessPasswordStrength(const string& password, vector<string>& feedback) {
    int score = 0;

    // Check for password length
    if (password.length() >= 12) {
        score += 2;
    } else if (password.length() >= 8) {
        score += 1;
    } else {
        feedback.push_back("Your password should be at least 8 characters long.");
    }

    // Check for uppercase letters
    if (regex_search(password, regex("[A-Z]"))) {
        score += 1;
    } else {
        feedback.push_back("Add at least one uppercase letter.");
    }

    // Check for lowercase letters
    if (regex_search(password, regex("[a-z]"))) {
        score += 1;
    } else {
        feedback.push_back("Add at least one lowercase letter.");
    }

    // Check for numbers
    if (regex_search(password, regex("[0-9]"))) {
        score += 1;
    } else {
        feedback.push_back("Include at least one number.");
    }

    // Check for special characters
    if (regex_search(password, regex("[!@#$%^&*(),.?\":{}|<>]"))) {
        score += 1;
    } else {
        feedback.push_back("Use at least one special character (!@#$%^&*(), etc.).");
    }

    // Assess password strength
    if (score >= 5) {
        return "Strong";
    } else if (score >= 3) {
        return "Moderate";
    } else {
        return "Weak";
    }
}

int main() {
    cout << "Password Strength Assessment Tool" << endl;
    string password;
    cout << "Enter your password: ";
    getline(cin, password);

    vector<string> feedback;
    string strength = assessPasswordStrength(password, feedback);

    cout << "Password Strength: " << strength << endl;
    if (!feedback.empty()) {
        cout << "Suggestions to improve your password:" << endl;
        for (const string& suggestion : feedback) {
            cout << "- " << suggestion << endl;
        }
    }

    return 0;
}
