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
#include <bits/stdc++.h> // Powerful C++ Library
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>

using namespace std;

// Function prototypes
void loadAnswer(long long arr[], int& size, const string& filename);
void bubbleSort(long long arr[], int n);
bool binarySearch(long long arr[], int size, long long target);

// Function to read valid credit card numbers from a file
void loadAnswer(long long arr[], int& size, const string& filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Error: Could not open file " << filename << endl;
    return;
  }

  int i = 0;
  while (file >> arr[i]) { // Read numbers from the file into the array
    i++;
  }

  size = i; // Set the size of the array
  file.close(); // Close the file
}

// Function to sort the array of credit card numbers (Bubble Sort)
void bubbleSort(long long arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) { // If current element is greater than the next one
        swap(arr[j], arr[j + 1]); // Swap them
      }
    }
  }
}

// Function to check if a credit card number exists using Binary Search
bool binarySearch(long long arr[], int size, long long target) {
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) { // If target is found at mid
      return true; // Return true
    } else if (arr[mid] < target) { // If target is greater than mid
      low = mid + 1; // Update low
    } else { // If target is smaller than mid
      high = mid - 1; // Update high
    }
  }
  return false; // If target is not found
}
// Start main function 
int main() {
  const string filename = "accNumbers.txt";
  long long answer[1000]; // Adjust size as needed
  int numCards = 0;

  // Load credit card numbers from file
  loadAnswer(answer, numCards, filename);

  // Sort the array using bubble sort
  bubbleSort(answer, numCards);

  char choice;
  cout << "Credit Card Account Checker ...\n";
  do {
    long long cardNumber;

    // Prompt user for credit card number
    cout << "\nEnter a 7-digit account number: ";
    cin >> cardNumber;

    // Validate user input
    if (cin.fail() || cardNumber < 1000000 || cardNumber > 9999999) {
      cout << "\nInvalid input. Please enter a 7-digit number." << endl;
      cin.clear(); // Clear error flags
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
      continue; // Restart the loop
    }

    // Check if number is valid using binary search
    bool isValid = binarySearch(answer, numCards, cardNumber);

    // Print validation result
    cout << (isValid ? "Valid" : "Invalid") << " credit card number." << endl;

    // Ask user if they want to check another account number
    cout << "\nWould you like to check another account number (y/n)? ";
    cin >> choice;
    if (choice == 'n' || choice == 'N') { // If user chooses to exit
      cout << "\nGoodbye ...\n";
      break;
    }  else if (!(choice == 'n' || choice == 'N' || choice == 'y' || choice == 'Y')) { // If user input is not valid
      cout << "\nNo, your choice is out of options\n";
      return 0; // Exit program
    }

  } while (choice == 'y' || choice == 'Y'); // Continue loop if user wants to check another account

  return 0; // Exit program
}



