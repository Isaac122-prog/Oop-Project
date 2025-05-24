#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "Cafe.h"

class Game {
 private:
  Cafe* cafe;
  int customerKey;

  sf::RenderWindow* win;
  sf::Font font;

  std::vector<sf::Text> customerTexts;  // FROM CHATGPT
  sf::Text waiterTimer;
  sf::Text cleanerTimer;
  sf::Text baristaTimer;
  sf::Text chefTimer;

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
  void baristaAction();  // generate drink if barista finished brewing,
                         // otherwise displays timer
  void chefAction();     // generate food is chef finished cooking, otherwise
                         // displays timer
  void waiterAction();   // serves food if waiter finished serving, otherwise
                         // displays timer
  void cleanerAction();  // sets table to clean if cleaner finished cleaning,
                         // otherwise displays timer

  // destructor
  ~Game();
};

#endif