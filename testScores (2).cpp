/******************************************************************************

File name: testScores.cpp - Assignment #4;
Authour: Hong Phuc Le (Mark);
Date: Oct 30, 2023;
Purpose: (Test Scores) Write a program that dynamically allocates an array large enough to hold a user-defined
number of test scores. Once all the scores are entered, the array should be passed to a function that
calculates the average score. The program should display the average with appropriate headings. Use
pointer notation rather than array notation whenever possible. Input Validation: Do not accept negative
numbers for test scores.
Use the following function headers:
double average(double*, int);

*******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Declare prototypes datatype and const values
double average(double*, int);
void inputTestScores(double*, int);
// Adjut number of scores input
const int MAX_SCORES = 100;

int main() {
char restartOption;
do {
  // Let user input number of scores not over MAX_SCORES.
  int numScores;
  cout << "WELCOME TO TEST SCORE CALCULATOR PROGRAM !" << endl;
  cout << "How many test scores will you enter? ";
  cin >> numScores;

  // Validate the size of numScores.
  if (numScores <= 0 || numScores > MAX_SCORES) {
    cout << "Invalid number of test scores. Please enter a value between 1 and " << MAX_SCORES << "." << endl;
    return 1; // Exit with an error code.
  }

  // Store testScores in an array.
  double* testScores = new double[numScores];

  // Input test scores.
  inputTestScores(testScores, numScores);

  // Calculate the average test score.
  double averageScore = average(testScores, numScores);

  // Display the average test score.
  cout  <<"\nAverage score: " << averageScore << endl;

  // Freeing up the memory that was allocated to the array.
  delete[] testScores;
      // Ask the user if they want to restart
    cout << "Do you want to restart the program? (y/n): ";
    cin >> setw(2) >> restartOption;
    
} while (restartOption == 'y' || restartOption == 'Y'); {
    if (restartOption == 'n' || restartOption == 'N') {
         cout << "Thank you for choosing us !";
    } else if (restartOption == ' ') {
        cout << "Thank you for choosing us !";
        } else {
        cout << "Wrong input ! Anyway .Thank you for choosing us !";
    }
return 0;
    } 
}

//Function to validate testScores.
void inputTestScores(double* scores, int numScores) {
    // Start the loop to validate inputs of user.
  for (int i = 0; i < numScores; i++) {
    cout << "Enter test score " << i + 1 << ": ";
    cin >> scores[i];
    // Validate the score from input
    while (scores[i] < 0 || scores[i] > 100) {
      if (scores[i] < 0) {
        cout << "Negative scores are not allowed." << endl;
      } else {
        cout << "Invalid score. Please enter a score between 0 and 100." << endl;
      }
      cout << "Re-Enter another score for test score " << i + 1 << ": ";
      cin >> scores[i];
    }
  }
}

//Function to calculate the average of scores.
double average(double* scores, int numScores) {

  // Step 1 : Calculate the sum of the test scores.
  double sum = 0;
  for (int i = 0; i < numScores; i++) {
    sum += scores[i];
  }

  // Step 2: Calculate the average test score.
  double averageScore = sum / numScores;

  //Step 3: Return the average test score.
  return averageScore;
}