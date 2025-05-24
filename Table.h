#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Table {
 private:
  sf::RectangleShape* body;
  bool isClean;
  int depth;

 public:
  // default constructor
  Table();
  // constructor
  Table(int depth);

  // getters and setters
  sf::RectangleShape* get_body();
  void set_isClean(bool cleanliness);
  bool get_isClean();

  // graphics: draws table
  void draw(sf::RenderWindow* win);

  // destructor
  ~Table();
};

#endif