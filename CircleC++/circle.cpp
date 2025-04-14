/******************************************************************************
Author: Hong Phuc Le 
Due Date:  April 09, 2024
Program: Flying Colors
File: flags.cpp , flag.h , flag_imp.cpp

- This program is designed to assist users in understanding the concepts of data types, variables, 
and operators; this C++ program demonstrates: Header File (flag.h): The header file now uses std::string instead of C-style strings, and the member functions are more concise.
Implementation File (flag.cpp): The implementation file now uses std::string instead of C-style strings, and the member functions are more concise.
Main Program (main.cpp): The main program now uses a std::vector to store the Flag objects, and the user interaction has been made more natural. The program also ensures proper memory management by deallocating the memory for the Flag objects before exiting.
Overall, the program allows users to manage a collection of flags by adding flags with their respective colors and displaying the stored flags' information. It ensures proper memory management and provides a simple and intuitive user interface for interaction.
*******************************************************************************/
#include "circle.h"
#include <iostream>
#include <iomanip>
using namespace std;
#include <bits/stdc++.h> // Powerful library
// start main function
int main() {
    char answer;

    do {
        double radius;
        cout << "Going in Circles ... \n" << endl;
        
        cout << "Enter the radius of the circle: ";
        cin >> radius;  // Input radius from user

        Circle circle(radius);

        cout << "\nProperties ... \n" << endl;
        cout << setprecision(2) << fixed;  // Set precision and fixed formatting for output
        cout << "\tDiameter: " << circle.getDiameter() << endl;         // Display diameter
        cout << "Circumference: " << circle.getCircumference() << endl;  // Display circumference
        cout << "\tArea: " << circle.getArea() << endl;                  // Display area

        cout << "\nDo you want to calculate for another circle (y/n)? ";
        cin >> answer;  // Ask user if they want to calculate for another circle
        cout << "\n";

        if(tolower(answer) == 'n') {
            cout << "\nThank you for using our service ! See you again !" ;
        }

    } while (tolower(answer) == 'y');  // Continue loop if user enters 'y' 

    return 0;
}
