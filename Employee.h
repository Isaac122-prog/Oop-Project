#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <SFML/Graphics.hpp>

#include "Customer.h"

class Employee {
 protected:
  bool isBusy;  // whether an employee is busy or not
  sf::Shape* body;
  int depth; // unsure if we actually need this yet

 public:
  Employee();  // default constructor

  // graphics functions
  void draw(sf::RenderWindow* win);
  int get_x();
  int get_y();
  int get_depth();
  void set_position(sf::Vector2f position);

  virtual void doTask(Customer* customer) = 0;  // virtual function making this
                                                // an abstract class
};

#endif