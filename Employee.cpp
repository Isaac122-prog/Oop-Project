#include "Employee.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Cafe.h"

using namespace std;

// constructor
Employee::Employee() {
  isBusy = false;
  waitTime = std::time(nullptr);
  wasCalled = false;
  label = "unnamed";
  customerNo = 0;

  body = new sf::RectangleShape(sf::Vector2f(10, 40));
  body->setOrigin(10, 10);
}

// getters and setters
bool Employee::get_isBusy() { return isBusy; }
void Employee::set_isBusy(bool status) { isBusy = status; }
bool Employee::get_wasCalled() { return wasCalled; }
void Employee::set_wasCalled(bool status) { wasCalled = status; }
std::time_t Employee::get_waitTime() { return waitTime; }
std::string Employee::get_label() { return this->label; }
int Employee::get_customerNo() { return customerNo; }

// draw employee
void Employee::draw(sf::RenderWindow* win) { win->draw(*body); }

// getters and setters for graphics
int Employee::get_x() { return body->getPosition().x; }
int Employee::get_y() { return body->getPosition().y; }
void Employee::set_position(sf::Vector2f position) {
  body->setPosition(position);
}
sf::Shape* Employee::get_body() { return body; }

// destructor
Employee::~Employee() {}