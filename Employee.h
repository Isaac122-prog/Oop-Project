#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <SFML/Graphics.hpp>
#include <ctime>

#include "Customer.h"

class Employee {
 protected:
  bool isBusy;  // whether an employee is busy or not
  sf::Shape* body;
  int depth; // unsure if we actually need this yet
  sf::Clock busyTimer;

  std::time_t waitTime;
  bool wasCalled;

 public:
  Employee();  // default constructor

  // graphics functions
  void draw(sf::RenderWindow* win);
  int get_x();
  int get_y();
  int get_depth();
  void set_position(sf::Vector2f position);

  bool get_wasCalled();
  void set_wasCalled(bool status);
  bool get_isBusy();
  void set_isBusy(bool status);
  std::time_t get_waitTime();

  // SHOULD THIS BE IN THE .CPP FILE TOO???
  virtual void doTask(Customer* customer) = 0;  // virtual function making this
                                                // an abstract class
                                                ~Employee();
};

#endif