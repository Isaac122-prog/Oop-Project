#ifndef GAME_H
#define GAME_H

#include "Cafe.h"

#include <SFML/Graphics.hpp>

class Game {
 private:
  sf::RenderWindow* win;
  Cafe* cafe;
  sf::Font font;
  
  std::vector<sf::Text> customerTexts; // FROM CHATGPT
 public:
  Game(int size, std::string title, Cafe* cafe);

  void drawFrame();
  void run();
  void keyBindings(sf::Event e);
};

#endif