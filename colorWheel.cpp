/******************************************************************************
Author: Hong Phuc Le 
Due Date:  Feb 20, 2024
Program: The Color Wheel
File: colorWheel.cpp

Color Wheel Algorithm

1. Initialization

Open "wheel.dat" file containing color wheel data
Display welcome message
2. Main Loop

Call showMenu() to display options
Get user's menu choice
Based on choice:
Call showPrimaryColors()
Call showSecondaryColors()
Call showTertiaryColors()
Call showColorWheel()
Exit program
Repeat until exit chosen
3. Termination

Close file
Display exit message
Function Definitions

showMenu()

Display menu options
Get user choice
Return choice
showColor(file, line, format1, format2)

Read color from specified line in file
Format color name using given parameters
Display formatted color
showPrimaryColors(file, format)

Display primary colors from file
showSecondaryColors(file, format)

Display secondary colors from file
showTertiaryColors(file, format)

Display tertiary colors from file
showColorWheel(file)

Display all colors in wheel format
Data Structures

ifstream: File input
string: Store color names
Control Flow

while loop: Repeat menu until exit
switch statement: Select action based on choice
*******************************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  // for setprecision
#include <bits/stdc++.h> // Powerful library
using namespace std;

// A function that displays the menu and returns the user's choice
int showMenu() {
 
// Menu function
  int choice;
  cout << endl << "\nChoose one of the following options: \n";
  cout << "\t1. Primary colors.\n";
  cout << "\t2. Secondary colors.\n";
  cout << "\t3. Tertiary colors.\n";
  cout << "\t4. Color Wheel.\n";
  cout << "\t5. Quit.\n";
  cout << "Option: \n";
  cin >> choice;
  return choice;
}

// Function to display a color from the file with adjusted space format to each menu options
void showColor(ifstream& file, int line, bool useFormatting1, bool useFormatting2) {
    file.seekg(line * 16); // Move the read marker to the desired line
    string color;
    getline(file, color); // Read the color name

    if (useFormatting1) {
        color.erase(color.find_last_not_of(' ') + 1); // Remove trailing whitespaces
        cout << left << setw(8) << color << "\t"; // Display the color name with adjusted space format and add a tab
        if (line % 3 == 2) {
            cout << endl;  // Add a newline after every third color
        }
    } else if (useFormatting2) {
        cout << left << color << "\t"; // Display the color name without formatting and add a tab
        if (line % 3 == 2) {
            cout << endl;  // Add a newline after every third color
        }
    } else {
        cout << left << color << "\t"; // Display the color name without formatting and add a tab
        if (line % 3 == 3) {
            cout << "\n" << endl;  // Add a newline after every third color
        }
    }
}

// A function that displays the primary colors
void showPrimaryColors(ifstream& file, bool useFormatting1) {
    cout << "Primary Colors\n";
     cout << "----------------------------------\n" << endl;
    for (int i = 0; i < 12; i += 4) {
        showColor(file, i, false, false);
    }
}

// A function that displays the secondary colors
void showSecondaryColors(ifstream& file, bool useFormatting1) {
  cout << "Secondary Colors " << endl;
   cout << "----------------------------------\n" << endl;
  for (int i = 2; i < 12; i += 4) { // Loop through the lines with secondary colors
    showColor(file, i, false, false); // Display the color on that line
  }
}

// A function that displays the tertiary colors
void showTertiaryColors(ifstream& file, bool useFormatting2) {
    cout << "Tertiary Colors\n";
     cout << "----------------------------------\n" << endl;
    for (int i = 1; i < 12; i += 2) {
        showColor(file, i, false, useFormatting2); // Display the color on that line with appropriate formatting
    }
}

// A function that displays the color wheel
void showColorWheel(ifstream& file) {
  cout << "Color Wheel\n";
  cout << "----------------------------------\n" << endl;
  for (int i = 0; i < 12; i++) {
        showColor(file, i, true, false); // Use formatting for the color wheel
    }
}

// Function prototypes
int showMenu();
void showColor(ifstream& file, int line, bool useFormatting1, bool useFormatting2);
void showPrimaryColors(ifstream& file, bool useFormatting1);
void showSecondaryColors(ifstream& file, bool useFormatting1);
void showTertiaryColors(ifstream& file, bool useFormatting2);
void showColorWheel(ifstream& file);

int main() {
      cout << "The Wheel of Colors App ... ";
    ifstream file("wheel.dat", ios::binary); // Open the file in binary mode
    if (!file) { // Check if the file is opened successfully
        cout << "Error: cannot open the file.\n";
        return 1;
    }

    int choice = showMenu(); // Display the menu and get the user's choice
    while (choice != 5) { // Loop until the user chooses to exit
        switch (choice) { // Execute different functions based on the choice
            case 1:
                showPrimaryColors(file, false); // Display the primary colors
                break;
            case 2:
                showSecondaryColors(file, false); // Display the secondary colors
                break;
            case 3:
                showTertiaryColors(file, true); // Display the tertiary colors
                break;
            case 4:
                showColorWheel(file); // Display the color wheel
                break;
            default:
                cout << "Invalid option. Please try again.\n"; // Handle invalid input
        }
        choice = showMenu(); // Display the menu and get the user's choice again
    }

    file.close(); // Close the file
    cout << "Thank you for using the color wheel program.\n"; // Quit message
    return 0;
}
