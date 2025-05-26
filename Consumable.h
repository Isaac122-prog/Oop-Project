#ifndef DRINK_H
#define DRINK_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Consumable {
 private:
  bool isActive;

  sf::Shape* body;
  int depth;  
 public:
  // constructor
  Consumable();

  // getters and setters
  bool get_isActive();
  void set_isActive(bool status);

  // draw consumable
  void draw(sf::RenderWindow* win);

  // getters and setters for graphics properties
  sf::Shape* get_body();
  int get_x();
  int get_y();
  int get_depth();
  void set_position(sf::Vector2f position);

  // destructor
  ~Consumable();
};

#endif