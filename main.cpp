/******************************************************************************

File name: passwordverifier.cpp - Assignment #5;
Authour: Hong Phuc Le (Mark);
Date: Nov 13th, 2023;
Purpose: (Password Verifier) Imagine you are developing a software package that requires users to enter 
their own passwords. Your software requires that users’ passwords meet the following criteria:
• The password should be at least six characters long.
• The password should contain at least one uppercase and at least one lowercase letter.
• The password should have at least one digit.
Write a program that asks for a password then verifies that it meets the stated criteria. If it 
doesn’t, the program should display a message telling the user why.

*******************************************************************************/
#include <iostream>

using namespace std;
// Constants for password requirements
const int MIN_PASSWORD_LENGTH = 6;

// Error messages
const string ERROR_UPPERCASE = "It should contain at least one uppercase letter.";
const string ERROR_LOWERCASE = "It should contain at least one lowercase letter.";
const string ERROR_DIGIT = "It should have at least one digit.";
const string ERROR_RANGE = "It should have at least 6 characters long.";

// Function to check if the password has at least one uppercase letter
bool hasUppercase(string password) {
  for (char c : password) {
    if (isupper(c)) {
      return true;
    }
  }
  return false;
}

// Function to check if the password has at least one lowercase letter
bool hasLowercase(string password) {
  for (char c : password) {
    if (islower(c)) {
      return true;
    }
  }
  return false;
}

// Function to check if the password has at least one digit
bool hasDigit(string password) {
  for (char c : password) {
    if (isdigit(c)) {
      return true;
    }
  }
  return false;
}

// Function to check if the password is valid based on requirements
bool isValidPassword(string password) {
  if (password.length() < MIN_PASSWORD_LENGTH) {
    return false;
  }

  if (!hasUppercase(password)) {
    return false;
  }

  if (!hasLowercase(password)) {
    return false;
  }

  if (!hasDigit(password)) {
    return false;
  }

  return true;
}

int main() {
  cout << "Password Requirements:" << endl;
  cout << " - The password should be at least " << MIN_PASSWORD_LENGTH << " characters long." << endl;
  cout << " - The password should contain at least one uppercase" << endl;
  cout << "   and at least one lowercase letter." << endl;
  cout << " - The password should have at least one digit." << endl;

  string password;

  // Loop until a valid password is entered
  while (true) {
    cout << endl << "Enter a password: ";
    cin >> password;

    if (isValidPassword(password)) {
      cout << endl << "The password is valid." << endl;
       cout << endl << "Thank you for joining our system !" << endl;
      break; // Break out of the loop if the password is valid
    } else {
      cout << endl << "The password is invalid." << endl;

      // Provide specific feedback on which requirements are not met
      if (!hasUppercase(password)) {
        cout << ERROR_UPPERCASE << endl;
      }
     if (password.length() < MIN_PASSWORD_LENGTH) {
        cout << ERROR_RANGE << endl;
      }
       if (!hasLowercase(password)) {
        cout << ERROR_LOWERCASE << endl;
      }

       if (!hasDigit(password)) {
        cout << ERROR_DIGIT << endl;
      }
    }
  }

  return 0;
}
