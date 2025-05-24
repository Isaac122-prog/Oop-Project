#include "Table.h"

#include <SFML/Graphics.hpp>

// defualt constructor
Table::Table() {
  depth = 0;
  isClean = true;
  body = new sf::RectangleShape(sf::Vector2f(0, 0));
}

// constructor
Table::Table(int depth) {
  isClean = true;  // table starts clean
  this->depth = depth;
  body = new sf::RectangleShape(sf::Vector2f(20, 20));
  body->setFillColor(sf::Color::Blue);
  body->setOrigin(10, 10);
}

// graphics: draw table
void Table::draw(sf::RenderWindow* win) { win->draw(*body); }

// getters and setters
sf::RectangleShape* Table::get_body() { return body; }
void Table::set_isClean(bool cleanliness) { isClean = cleanliness; }
bool Table::get_isClean() { return isClean; }

// destructor
Table::~Table() {}