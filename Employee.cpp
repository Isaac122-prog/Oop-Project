#include "Employee.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

// default constructor
Employee::Employee() {
  isBusy = false;

  
  body = new sf::RectangleShape(sf::Vector2f(10, 40));
  body->setOrigin(10, 10);
  waitTime = std::time(nullptr);
  wasCalled = false;

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
bool Employee::get_wasCalled() {return wasCalled;}
void Employee::set_wasCalled(bool status) {wasCalled = status;}



std::time_t Employee::get_waitTime() { return waitTime; }

Employee::~Employee() {
}