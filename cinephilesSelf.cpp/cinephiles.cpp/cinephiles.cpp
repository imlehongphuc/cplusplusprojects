/******************************************************************************
Author: Hong Phuc Le 
Due Date:  Feb 13, 2024
Program: College Cinephiles Pathways Stats
File: cinephiles.cpp

- This program simulates a college cinephile pathway stats
Reads pathway data from a user-specified file.
The file contains college information, pathway information, and the number of movies each student sees in the pathway.
Stores student data in an array.
Displays college and pathway information.
Displays the number of movies seen by each student in a formatted table.
Calculates and displays the average number of movies seen by all students.
Presents movie-watching statistics for each processed pathway file.
The program repeatedly asks for a new file name until the user chooses to stop.
This allows for analyzing several pathway files consecutively.
Dynamically allocates memory for the student data array.
Deallocates memory after processing each file to avoid memory leaks.
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>  // for setprecision
#include <bits/stdc++.h> // Powerful library

using namespace std;

// Function to read data from file and store it in an array
void readData(string pathwayFile, int*& data, int& numStudents, string& college, string& pathway) {
    ifstream file(pathwayFile);
    if (!file) { // Check if file opened successfully
        cerr << "Error opening file " << "'"<< pathwayFile <<"'"<< endl;
        exit(1);
    }

    // Read college and pathway information
    getline(file, college);
    getline(file, pathway);

    // Read the number of students in the file
    file >> numStudents;

    // Dynamically allocate the array
    data = new int[numStudents];

    // Read the student answers
    for (int i = 0; i < numStudents; i++) {
        file >> data[i];
    }

    file.close(); // Close the file
}

// Function to display the student answers and (college,pathway) information
void displayAnswers(int* data, int numStudents, string college, string pathway) {
    cout << "\nCollege: " << college << endl;
    cout << "Pathway: " << pathway << endl;
    cout << "------------------------" << endl;
     cout << "\nNumber of movies seen by " << numStudents << " students" << endl;
     //for loop to display all movies have been seen by students
    for (int i = 0; i < numStudents; i++) {
        cout <<  setw(9) << data[i] << setw(9);
        if (i % 10 == 9) { // Wrap after every 10 numbers
            cout << endl;
        }
    }
    cout << endl;
}

// Function to calculate and display the average number of movies seen
void calculateAverage(int* data, int numStudents) {
    int totalMovies = 0;
    for (int i = 0; i < numStudents; i++) {
        totalMovies += data[i];
    }
cout << "\nAverage number of movies seen: " << fixed << setprecision(0) << (double)totalMovies / numStudents <<"\n"<< endl;
}

int main() {
    //Prototype Function
    void calculateAverage(int* data, int numStudents);
    void displayAnswers(int* data, int numStudents, string college, string pathway);
    void readData(string pathwayFile, int*& data, int& numStudents, string& college, string& pathway);

   char choice; // datatype of choice is character
     int* data = nullptr; // Initialize data pointer to nullptr
        int numStudents = 0;
 cout << "\nCollege Cinephiles Pathways Stats ... \n" <<endl;
 // start loop do - while to display the function and ask user's option
    do {
        string pathwayFile, college, pathway;
        cout << "Please Enter Pathway file name: ";
        cin >> pathwayFile;

       

        readData(pathwayFile, data, numStudents, college, pathway);
        displayAnswers(data , numStudents, college, pathway);
        calculateAverage(data, numStudents);

        delete[] data; // Deallocate memory

        cout << "Do you have another file (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
if (choice == 'n' || choice == 'Y') {
    cout << "BYE ! See you again !";
} else {
    cout << "BYE ! See you again !";
}
    return 0;
}

