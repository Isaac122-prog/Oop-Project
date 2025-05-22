#ifndef GAME_H
#define GAME_H

#include "Cafe.h"

#include <SFML/Graphics.hpp>

class Game {
 private:
  sf::RenderWindow* win;
  Cafe* cafe;
  sf::Font font;

  int customerKey;

  sf::Text waiterTimer;
  sf::Text cleanerTimer;
  sf::Text baristaTimer;
  sf::Text chefTimer;
  
  std::vector<sf::Text> customerTexts; // FROM CHATGPT
 public:
  Game(int size, std::string title, Cafe* cafe);

  void drawFrame();
  void run();
  void keyBindings(sf::Event e);
};

#endif