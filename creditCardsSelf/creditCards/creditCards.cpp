/******************************************************************************
    Author: Hong Phuc Le 
    Date:  February 8, 2024
    Program: Credit Card Number Validator
    File: creditCards.cpp
    This program allows users to check the validity of a 7-digit credit card number
    by comparing it with a sorted list of valid credit card numbers.
    Sort the array of credit card numbers in ascending order by implementing the Bubble Sort algorithm.
    Determine whether a credit card number is valid by implement the Binary Search algorithm.
    The list of valid credit card numbers is read from a file, and the program
    uses binary search for efficient validation.
*******************************************************************************/
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <array>
#include <string>
#include <algorithm>
//Timer library effect
#include <chrono>
#include <thread>
using namespace std;

// Function prototypes
void readAccNumbers(ifstream &file, int arr[], int size);
void bubbleSort(int arr[], int size);
bool isValid(int arr[], int size, int num);
void displayWelcomeMessage(char cusName[], char MAX_NAME_LENTH);
void loadingMessage();
//Calling library for depending on the window version function clear_screen
#ifdef _WIN32
    #include <conio.h>
    #define CLEAR_SCREEN "cls"
#else
    #include <unistd.h>
    #include <term.h>
    #define CLEAR_SCREEN "clear"
#endif


// Display main function
int main() {
  //Datatype Declaration
    char MAX_NAME_LENTH = 50;
    char cusName[MAX_NAME_LENTH];
  const int maxSize = 100;
  int arr[maxSize];
  string answer;
  string input;


 cout << "Welcome to my bank HONG PHUC LE !" << endl;
 //Introduction to machine
  displayWelcomeMessage(cusName, MAX_NAME_LENTH);
 cout << "\n\n\n\n\n\nCredit Card Account Checker ... " << endl;
  // Open file and read credit card numbers into the array
  ifstream file("accNumbers.txt");
  readAccNumbers(file, arr, maxSize);
  file.close();

  // Bubble Sorting function callback
  bubbleSort(arr, maxSize);

  
  
  // Ask the user if they want to check another account number using do while loop
  do {
    // Prompt user to enter a 7-digit credit card number
    cout << "\nEnter a 7-digit credit card number: ";
    cin >> answer;

    // Validate the user's input to avoid illegal execution or injection
    if (answer.size() == 7 && all_of(answer.begin(), answer.end(), ::isdigit)) {
      int num = stoi(answer);

      // Check if the entered credit card number is valid
      if (isValid(arr, maxSize, num)) {
        cout << "-> The credit card number is valid\n" << endl;
      } else {
        cout << "-> The credit card number is invalid\n" << endl;
      }
    } else {
      cout << "Invalid input. Please enter a 7-digit number." << endl;
      // Clear the buffer char left - clear trashes
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
      continue; // restart the loop
    }

    // Ask the user if they want to check another account number
    cout << "Would you like to check another account number (y/n)? ";
    cin >> input;
    // Clear the buffer char left - clear trashes
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  

  } while (input == "y" || input == "Y" || input == "yes" || input == "Yes" || input == "YES"); 
  //Additional function to validate input from customers
  if (input == "n" || input == "N" || input == "no" || input == "No" || input == "NO") {
      //End loop then display this message to thank you customers
      cout << "\nGood bye " << cusName << " ! " << " See you again !";
  }else {
      //Message when end loop cause enter invalid or illegal symbols
      cout << "\nOh no " << cusName << " ! Error ! You have entered some suspicious ! Not allowed ";
  }
  
  return 0; 
}

//Function display welcome message to customers
void displayWelcomeMessage(char cusName[], char MAX_NAME_LENTH) {
    cout << "Please enter your name: ";
    cin.getline(cusName, MAX_NAME_LENTH);
    cout << "Welcome " << cusName << " to our machine" << endl;
    loadingMessage();
}
//Function loading message and delay timer
void loadingMessage() {
    // Loading to the machine
    cout << "Loading...to machine...please wait\n\n" << endl;
    // Delay 2 seconds effect to avoid lagging
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    system(CLEAR_SCREEN);  // Clear the screen to start displaying the main function
}

// Function to read the list of valid credit card numbers from a file txt, to start implementation to sort
void readAccNumbers(ifstream &file, int arr[], int size) {
  int i = 0;
  while (file >> arr[i] && i < size) {
    i++;
  }
}

// Function Bubble Sort to sort the array of credit card numbers in the txt file 
void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap elements if they are in the wrong order
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Function Binary Search algorithm to determine whether or not each entered credit card number is valid  
bool isValid(int arr[], int size, int num) {
  int low = 0, high = size - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == num) {
      return true;
    } else if (arr[mid] < num) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}


