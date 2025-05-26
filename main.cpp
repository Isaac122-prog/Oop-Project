#include <jsoncpp/json/json.h>

#include <SFML/Graphics.hpp>
#include <chrono>
#include <fstream>
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
  if (choice < 0 || choice > 2) {
    cin.clear();
    cout << "Invalid input. Please enter 0, 1, or 2: ";
    cin >> choice;
  }

  return choice;
}

// assign values from save file
// void openSaved(Game game) {
//   int maxCustomers = save["maxCustomers"].asInt();
//   bool isActive = save["customers"]["cust"]["isActive"].asBool();
//   int hunger = save["customers"]["cust"]["hunger"].asInt();
// }

int main() {
  srand(time(0));

  int customers = 1;
  int yesNo;
  int typeGame;

  cout << "would you like to start the game?\npress 1 for yes, 0 for no"
       << endl;
  cin >> yesNo;
  // ADD A WHILE LOOP HERE

  while (yesNo == 1) {
    cout << "press 1 to play saved version, press 0 to play new game" << endl;
    cin >> typeGame;
    // ADD DEFENCE STUFF HERE
    if (typeGame == 1) {
      if (std::ifstream infile{"event_data.json"}) {
        std::ifstream save_file("event_data.json", std::ifstream::binary);
        Json::Value save;
        save_file >> save;

        customers = save["maxCustomers"].asInt();
      }
    } else if (typeGame == 0) {
      cout << "How many customers do you want?" << endl;
      cin >> customers;
      while (customers > 10 || customers < 1 || cin.fail()) {
        cin.clear();  // clear error flags
        cin.ignore(std::numeric_limits<std::streamsize>::max(),
                   '\n');  // discard invalid input
        cout << "Must be between 1 and 10! Try again: " << endl;
        cin >> customers;
      }
    }
    // create cafe
    Cafe* cafe = new Cafe(customers);

    if (typeGame == 1) {
      if (std::ifstream infile{"event_data.json"}) {
        std::ifstream save_file("event_data.json", std::ifstream::binary);
        Json::Value save;
        save_file >> save;

        cafe->set_maxEmployees(save["numEmployees"].asInt());
        cafe->set_newEmployee(save["newEmployee"].asInt());

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
          cafe->get_customerPointer(i)->set_startTime();
          // number field can be ignored since i is the index
          if (cafe->get_customerPointer(i)->get_isActive()){
            maxActiveCustomers = i;
          }
        }

        cafe->set_numActiveCustomers(maxActiveCustomers);
      }
    }

    Game* game = new Game("cafe game", cafe);
    game->run();

    std::cout << "you have completed the game. Would you like to play again?\n "
                 "press 1 for yes and 0 for no"
              << std::endl;
    cin >> yesNo;
  }
  // UnitTest unitTest;S
  // unitTest.runTests();

  return 0;
}
