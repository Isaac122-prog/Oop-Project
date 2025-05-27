#include <jsoncpp/json/json.h>

#include <SFML/Graphics.hpp>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>

#include "Cafe.h"
#include "Game.h"
#include "UnitTest.h"

using namespace std;

// Display Instructions
void showInstructions() {
    cout << "\n======== GAME INSTRUCTIONS ========\n";
    cout << "Welcome to Cafe Game!\n\n";
    cout << "Context: \n";
    cout << "Customers will enter the cafe with low scores in hunger, thirst, and disgust out of 5\n";
    cout << "Customers will start of with a Happiness level of 15\n";
    cout << "Objective:\n";
    cout << "  - Serve all customers efficiently using your cafe staff to max out their scores before they leave. \n\n";
    cout << "Controls:\n";
    cout << "      1, 2, 3, etc. → allocate customer for task. MUST BE PRESSED BEFORE ACTIVATING EACH EMPLOYEE\n";
    cout << "      Q → Barista (serve drink)\n";
    cout << "      W → Chef (prepare food)\n";
    cout << "      E → Waiter (deliver food/drink to customer)\n";
    cout << "      R → Cleaner (clean customer's table)\n";
    cout << "      T → Extra employee (unlocked after 2nd customer leaves)\n";
    cout << "      P → To check your in game performance\n";
    cout << "Note:\n";
    cout << "  - The mouse is NOT used during gameplay.\n";
    cout << "  - Use it only to click between the graphics window and terminal if needed.\n";
    cout << "  - available food and drink appear as white squares\n";
    cout << "  - customer's disgust score will continually decrease over time.\n";
    cout << "  - if gameplay pauses, check the terminal for a message!\n";
    cout << "====================================\n\n";
}

// displaying the menu
int showMenu() {
  int choice;
  cout << "===== CAFE GAME MENU =====" << endl;
  cout << "1. Start Game" << endl;
  cout << "2. Instructions" << endl;
  cout << "0. Quit" << endl;
  cout << "===========================" << endl;
  cout << "Enter your choice: ";
  cin >> choice;

  // checking if input is lower than 0 or above 2
  while ((choice < 0 || choice > 2) || cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input. Please enter 0, 1, or 2: ";
    cin >> choice;
  }

  return choice;
}

int main() {
  srand(time(0));  // set rand timer

  int customers = 1;
  int yesNo;
  int typeGame;

  // starting game
  cout << "would you like to start the game?\npress 1 for yes, 0 for no"
       << endl;
  cin >> yesNo;

  // checking input
  while (yesNo != 1 && yesNo != 0 || cin.fail()) {
    cin.clear();             // clear error flag
    cin.ignore(1000, '\n');  // discard bad input
    std::cout << "invalid input. Please try again." << std::endl;
    cin >> yesNo;
  }
    // Menu / instructions
if (yesNo == 1) {
    int menuChoice = showMenu();  // menu choice should show
    
    while (menuChoice == 2) { 
        showInstructions(); // shows instructions
        menuChoice = showMenu(); // show menu again after instructions
    }

    if (menuChoice == 0) { // happens if they want to quit
        cout << "Exiting game. See you next time!" << endl;
        return 0;
    }
}

  while (yesNo == 1) {
    Cafe* cafe;

    // prompt for type of game
    cout << "press 1 to play previously saved version, press 0 to play new game"
         << endl;
    cin >> typeGame;

    // checking input
    while (typeGame != 1 && typeGame != 0 || cin.fail()) {
      cin.clear();             // clear error flag
      cin.ignore(1000, '\n');  // discard bad input
      std::cout << "invalid input. Please try again." << std::endl;
      cin >> typeGame;
    }
    if (typeGame == 1) {
      // checking if saved file exists and implementing
      if (std::ifstream infile{"event_data.json"}) {
        std::ifstream save_file("event_data.json", std::ifstream::binary);
        Json::Value save;
        save_file >> save;

        customers = save["maxCustomers"].asInt();
        std::cout << "customers from file: " << customers << endl;
      } else {
        std::cout << "no saved file! starting new game" << std::endl;
        typeGame = 0;
      }
    }
    if (typeGame == 0) {
      // prompt for max number of customers
      cout << "How many customers do you want? (between 1 and 10)" << endl;
      cin >> customers;
      while (customers > 10 || customers < 1 || cin.fail()) {
        cin.clear();             // clear error flag
        cin.ignore(1000, '\n');  // discard bad input
        cout << "Must be between 1 and 10! Try again: " << endl;
        cin >> customers;
      }
    } else if (typeGame!=1 && typeGame!=0 || cin.fail()){
      cin.clear();             // clear error flag
      cin.ignore(1000, '\n');  // discard bad input
      std::cout << "no game selected. Ending." << std::endl;
      return 0;
    }

    // create cafe
    cafe = new Cafe(customers);

    // set saved attributes into cafe
    if (typeGame == 1) {
      if (std::ifstream infile{"event_data.json"}) {
        std::ifstream save_file("event_data.json", std::ifstream::binary);
        Json::Value save;
        save_file >> save;

        cafe->set_savedVersion(true);

        cafe->set_maxEmployees(save["numEmployees"].asInt());
        cafe->set_employeeType(save["newEmployee"].asInt());

        if (cafe->get_maxEmployees() > 4) {
          cafe->add_newEmployee();
        }

        // Get the customers JSON array
        const Json::Value& customersArray = save["customers"];

        // Loop through the array and update each customer
        int maxActiveCustomers = 0;
        for (int i = 0; i < customersArray.size(); ++i) {
          const Json::Value& cust = customersArray[i];

          cafe->get_customerPointer(i)->set_thirst(cust["thirst"].asInt());
          cafe->get_customerPointer(i)->set_hunger(cust["hunger"].asInt());
          cafe->get_customerPointer(i)->set_disgust(cust["disgust"].asInt());
          cafe->get_customerPointer(i)->set_isActive(cust["isActive"].asBool());
          cafe->get_customerPointer(i)->set_happiness(
              cust["happiness"].asBool());
          cafe->get_customerPointer(i)->set_startTime();
          // set maxActiveCustomers
          if (cafe->get_customerPointer(i)->get_isActive()) {
            maxActiveCustomers = i + 1;
          }
        }

        cafe->set_numActiveCustomers(maxActiveCustomers);
      }
    }

    Game* game = new Game("cafe game", cafe);
    game->run();

    if (cafe != nullptr) {
      delete cafe;
      cafe = nullptr;
    }

    std::cout << "you have completed the game. Would you like to play again?\n "
                 "press 1 for yes and 0 for no"
              << std::endl;
    cin >> yesNo;
    // checking input
    while (yesNo != 1 && yesNo != 0 || cin.fail()) {
      cin.clear();             // clear error flag
      cin.ignore(1000, '\n');  // discard bad input
      std::cout << "invalid input. Please try again." << std::endl;
      cin >> yesNo;
    }
  }
  // UnitTest unitTest;S
  // unitTest.runTests();

  return 0;
}