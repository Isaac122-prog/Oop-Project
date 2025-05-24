#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

#include "Customer.h"

class Employee {
 protected:
  bool isBusy;  // whether an employee is busy or not
  sf::Shape* body;
  int depth;  // unsure if we actually need this yet
  sf::Clock busyTimer;

  std::time_t waitTime;
  bool wasCalled;

 public:
  // constructor
  Employee();

  // virtual function making Employee an abstract class
  virtual void doTask(Customer* customer) = 0;

  // getters and setters
  bool get_wasCalled();
  void set_wasCalled(bool status);
  bool get_isBusy();
  void set_isBusy(bool status);
  std::time_t get_waitTime();

  // graphics functions
  void draw(sf::RenderWindow* win);
  void set_position(sf::Vector2f position);

  // getters for graphics properties
  int get_x();
  int get_y();
  int get_depth();

  // destructor
  ~Employee();
};

#endif