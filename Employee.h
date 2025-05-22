#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <SFML/Graphics.hpp>
#include <ctime>

#include "Customer.h"

class Employee {
 protected:
  bool isBusy;  // whether an employee is busy or not
  sf::Shape* body;
//   sf::Text* info;
//   sf::Font font;
  int depth; // unsure if we actually need this yet
  sf::Clock busyTimer;

 public:
  Employee();  // default constructor

  // graphics functions
  void draw(sf::RenderWindow* win);
  int get_x();
  int get_y();
  int get_depth();
  void set_position(sf::Vector2f position);

  bool get_isBusy();
  void set_isBusy(bool status);
  int get_busyTimer();

//   sf::Text* get_info();

  // SHOULD THIS BE IN THE .CPP FILE TOO???
  virtual void doTask(Customer* customer) = 0;  // virtual function making this
                                                // an abstract class
                                                ~Employee();
};

#endif