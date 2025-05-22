#include "Employee.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

// default constructor
Employee::Employee() {
  isBusy = false;

  
  body = new sf::RectangleShape(sf::Vector2f(10, 40));
  body->setOrigin(10, 10);

  // setting up font
  if (!font.loadFromFile("fonts/MyFont.ttf")) {
    std::cerr << "Failed to load font!" << std::endl;
  }

  // info = new sf::Text();
  // info->setString("");
  // info->setFont(font);
  // info->setFillColor(sf::Color::Red);
  // info->setCharacterSize(20);
}

// graphics functions
void Employee::draw(sf::RenderWindow* win) {
  win->draw(*body);
  // win->draw(*info);
}

int Employee::get_x() { return body->getPosition().x; }
int Employee::get_y() { return body->getPosition().y; }
int Employee::get_depth() { return depth; }
void Employee::set_position(sf::Vector2f position) {
  body->setPosition(position);
}

bool Employee::get_isBusy() { return isBusy; }
void Employee::set_isBusy(bool status) { isBusy = status; }

// sf::Text* Employee::get_info(){
//   return info;
// }

int Employee::get_busyTimer() { return busyTimer.getElapsedTime().asSeconds(); }

Employee::~Employee() {
}