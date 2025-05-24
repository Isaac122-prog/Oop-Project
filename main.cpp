#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <random>

#include "Cafe.h"
#include "Game.h"
// #include "UnitTest.h"

using namespace std;

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