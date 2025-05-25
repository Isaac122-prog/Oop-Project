#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <random>

#include "Cafe.h"
#include "Game.h"
// #include "UnitTest.h"

using namespace std;

// Showing instructions
void showInstructions() {
  cout << "\n====== INSTRUCTIONS ======\n";
  cout << "Welcome to the Cafe Game!\n\n";
  cout << "Goal:\n";
  cout << "  - Serve all the customers efficiently.\n\n";
  cout << "How to Play:\n";
  cout << "  - Choose the number of customers (1 to 10).\n";
  cout << "  - Use the mouse to interact with the game elements.\n";
  cout << "  - Complete all customer orders to win.\n\n";
  cout << "Tips:\n";
  cout << "  - Be quick! Customers may get impatient.\n";
  cout << "  - Watch for hints and feedback during gameplay.\n";
  cout << "===========================\n\n";
}

//displaying the menu
int showMenu() {
  int choice;
  cout << "===== CAFE GAME MENU =====" << endl;
  cout << "1. Start Game" << endl;
  cout << "2. Instructions" << endl;
  cout << "0. Quit" << endl;
  cout << "===========================" << endl;
  cout << "Enter your choice: ";
  cin >> choice;

  //checking if input is lower than 0 or above 2
  if (choice < 0 || choice > 2){
    cin.clear();
    cout << "Invalid input. Please enter 0, 1, or 2: ";
    cin >> choice;
  }
 
  return choice;
}

int main() {
  srand(time(0));

  int customers;
  int yesNo;

  cout << "would you like to start the game?\npress 1 for yes, 0 for no" << endl;
  cin >> yesNo;

  while (yesNo == 1){
  cout << "How many customers do you want?" << endl;
  cin >> customers;
  while (customers > 10 || customers < 1 || cin.fail()) {
    cin.clear();  // clear error flags
    cin.ignore(std::numeric_limits<std::streamsize>::max(),
               '\n');  // discard invalid input
    cout << "Must be between 1 and 10! Try again: " << endl;
    cin >> customers;
  }

  Cafe cafe = Cafe(customers);
  Game game = Game("cafe game", &cafe);
  game.run();

  std::cout << "you have completed the game. Would you like to play again?\n press 1 for yes and 0 for no" << std::endl;
  cin >> yesNo;
  }

  // UnitTest unitTest;S
  // unitTest.runTests();

  return 0;
}