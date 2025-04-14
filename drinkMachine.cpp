/******************************************************************************
    Author: Hong Phuc Le 
    Date:  January 30, 2024
    Program: Soft Drink Dispenser
    File: drinkMachine.cpp
    This program simulates a soft drink dispenser - This program contain BOT protector. 
    It prompts a user to either pick one of the drinks, or quit.
    If the user selects a drink, the program will dispense it and update the number of drinks left.
    If there are no drinks of the type selected, it will display an error message.
*******************************************************************************/
#include <iostream>
#include <string>
//Powerful library
#include <bits/stdc++.h>
using namespace std;

// Data Structure
struct Drink {
    string name;
    int quantity;
};

// Declare global array of drinks
Drink drinks[5] = {
    {"Cola", 20},
    {"Root Beer", 20},
    {"Lemon-Lime", 20},
    {"Grape Soda", 20},
    {"Cream Soda", 20}
};

// Function prototypes
void displayMenu();
void dispenseDrink(Drink drinks[], int size, int choice);
void welcome(string& ans);
void nameAsking(string& nameUser);


// Main Function
int main() {
    //Data type declaration 
    int choice;
    string ans;
    string nameUser;
    //Welcome guest banner
    cout << "WELCOME TO HONG PHUC LE'S MACHINE !" << endl;
     
    
    // Passing data 'ans' and data'nameUser' as  parameters
        nameAsking(nameUser);
         cout << "WELCOME " <<nameUser <<" !\n" <<setw(2)<< endl;
        welcome(ans);  
        
        if (ans == "y") {
            cout << "Loading to machine...Please wait" << endl;
        } else {
            cout << "You are bot ! Bye !" << endl;
            return 0;
        }
         cout << "\nSoft Drink Dispenser ...\n" << endl;
         
         
         //Start loop do-while
    do {
       //Call function display menu
        displayMenu();
        cin >> choice;
        //Validate the quantity of drinks to display message correctly
        if (choice >= 1 && choice <= 5) {
            dispenseDrink(drinks, 5, choice - 1);
        } else if (choice != 6) {
            cout << "Error...Invalid choice. Try again." << endl;
        } else {
            cout << "\nGood bye...See you again !" << endl;
            break;  // Choose 6 to escape the loop
        }
    } while (true);  // Loop infinite till 6 would be selected

    return 0;
}
// END MAIN FUNCTION

//Funtion welcome users
// Input ans as a reference parameter
void nameAsking(string& nameUser) {  
    cout << "What is your name ? Answer to continue: ";
    getline(cin, nameUser);
}
//Funtion checking bot 
// Input ans as a reference parameter
void welcome(string& ans) {  
    cout << "Are you human ? Type 'y' to continue: ";
    cin >> ans;
}

//Function display menu of machine
void displayMenu() {
   
    cout << "Choose one of the following drinks" << endl;
    for (int i = 0; i < 5; i++) {
        cout <<setw(10) << i + 1 << ". " << drinks[i].name << " (" << drinks[i].quantity << " left)" << endl;
    }
    cout <<"         "<< "6. Quit" << endl;
    cout << "Option: ";
}

//Function dispense drinks each time chosen
void dispenseDrink(Drink drinks[], int size, int choice) {
    if (drinks[choice].quantity > 0) {
        cout << "Blink...Blink...Blink\n" << "Clink...Clink...Clink\n" << "Sink...Sink...Sink" << endl;
        cout << "Here is your " << drinks[choice].name << " drink !\n\n" << endl;
        drinks[choice].quantity--;
    } else {
        cout << "Out of stock!" << endl;
    }
}

