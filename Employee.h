#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

#include "Customer.h" 

class Cafe; // FORWARD DECLARATION OF CAFE TO AVOID CIRCLE OF PAIN

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
  virtual void doTask(Customer* customer, Cafe* cafe) = 0;

  // getters and setters
  bool get_wasCalled();
  void set_wasCalled(bool status);
  bool get_isBusy();
  void set_isBusy(bool status);
  std::time_t get_waitTime();

  // draw employee
  void draw(sf::RenderWindow* win);
  
  // getters and setters for graphics properties
  int get_x();
  int get_y();
  int get_depth();
  void set_position(sf::Vector2f position);
  sf::Shape* get_body();

  // destructor
  ~Employee();
};

#endif