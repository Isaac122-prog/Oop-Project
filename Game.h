#ifndef GAME_H
#define GAME_H

#include <jsoncpp/json/json.h>

#include <SFML/Graphics.hpp>

#include "Cafe.h"

class Game {
 private:
  Cafe* cafe;
  int customerKey;
  int newEmployee;

  sf::RenderWindow* win;
  sf::Font font;

  std::vector<sf::Text> customerTexts;
  std::vector<sf::Text> employeeTimers;

  int activeBarista;
  int activeChef;

  int customerSave;

 public:
  // constructor
  Game(std::string title, Cafe* cafe);

  // draws all objects in a frame
  void drawFrame();

  // sets actions for when player presses keyboard keys
  void keyBindings(sf::Event e);

  // runs the game
  void run();

  // checks actions/graphics of employees based on their busy timers
  // generate drink if barista finished brewing, otherwise displays timer
  void baristaAction(int i);
  // generate food is chef finished cooking, otherwise displays timer
  void chefAction(int i);
  // serves food if waiter finished serving, otherwise displays timer
  void waiterAction(int i);
  // sets table to clean if cleaner finished cleaning, otherwise displays timer
  void cleanerAction(int i);
  // completes new employee's action based on employee type
  void newEmployeeAction(int i);

  // saves current progress to event_data.json
  void saveFile();

  // getter for cafe
  Cafe* get_cafe();

  // destructor
  ~Game();
};

#endif