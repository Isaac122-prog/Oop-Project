#include "Employee.h"

#include <SFML/Graphics.hpp>

using namespace std;

// default constructor
Employee::Employee() { isBusy = false; }

// graphics functions
void Employee::draw(sf::RenderWindow* win) { win->draw(*body); }

int Employee::get_x() { return body->getPosition().x; }
int Employee::get_y() { return body->getPosition().y; }
int Employee::get_depth() { return depth; }
void Employee::set_position(sf::Vector2f position) {
  body->setPosition(position);
}