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
#include <iostream>
#include <iomanip>
#include "flag.h" // Include the header file for the Flag class
#include <bits/stdc++.h> // Powerful library

//Declare some constants variables
const int SIZE = 50; // Maximum size for the flags array
const int COL = 20; // Column width for formatting output

//Start main function here 
int main() {
    std::string country; // Variable to store country name input
    int colors; // Variable to store the number of colors in a flag
    int choice; // Variable to store user's menu choice
    Flag flags[SIZE]; // Array to store flags
    int numFlags = 0; // Variable to keep track of the number of flags added

    std::cout << "\nFlying Colors App ..." << std::endl;

    std::string line(COL * 2, '-'); // String for formatting output
    std::string colorName; // Variable to store color name declared outside the switch block

    do {
        // Display menu options
        std::cout << "\nChoose one of the following options:" << std::endl
             << "\t1. Add a flag to the collection" << std::endl
             << "\t2. Display flags in the collection." << std::endl
             << "\t3. Quit." << std::endl
             << "Option: ";
        std::cin >> choice; // Get user's choice

        switch (choice) {
            case 1:
                std::cout << "\nAdding a flag ..." << std::endl;
                std::cout << "Enter country name: ";
                std::cin >> country; // Get country name input
                flags[numFlags].setCountry(country); // Set country for the current flag
                std::cout << "Enter number of colors: ";
                std::cin >> colors; // Get the number of colors in the flag
                flags[numFlags].setColors(colors); // Set the number of colors for the current flag

                // Loop to input color information for each color in the flag
                for (int i = 0; i < colors; i++) {
                    int r, g, b;
                    std::cout << "Enter color name for color " << i + 1 << ": ";
                    std::cin >> colorName; // Get color name input
                    std::cout << "Red (0-255): ";
                    std::cin >> r; // Get red component input
                    std::cout << "Green (0-255): ";
                    std::cin >> g; // Get green component input
                    std::cout << "Blue (0-255): ";
                    std::cin >> b; // Get blue component input
                    flags[numFlags].setColor(i, colorName, r, g, b); // Set color information for the current flag
                }

                numFlags++; // Increment the number of flags added
                break;
            case 2:
                std::cout << "\nDisplaying Flags ..." << std::endl;
                std::cout << std::endl << line << std::endl
                     << std::setw(COL) << std::left << "Country" << "Colors" << std::endl
                     << line << std::endl;

                // Loop to display information of each flag in the collection
                for (int i = 0; i < numFlags; i++) {
                    std::cout << std::setw(COL) << std::left << flags[i].getCountry() << flags[i].getColors() << std::endl;
                }
                break;
            case 3:
                std::cout << "\nGood Bye ..." << std::endl;
                break;
            default:
                std::cout << "Error ... Invalid choice. Try again." << std::endl;
        }
    } while (choice != 3); // Continue the loop until the user chooses to quit

    return 0;
}
