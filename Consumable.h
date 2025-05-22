#ifndef DRINK_H
#define DRINK_H

#include <SFML/Graphics.hpp>

class Consumable {
 private:
  bool isActive;

  sf::Shape* body;
  int depth; // unsure if we actually need this yet
  
 public:
  Consumable();

  bool get_isActive();
  void set_isActive(bool status);

  sf::Shape* get_body();

   // graphics functions
  void draw(sf::RenderWindow* win);
  int get_x();
  int get_y();
  int get_depth();
  void set_position(sf::Vector2f position);
  
  ~Consumable();
};

#endif