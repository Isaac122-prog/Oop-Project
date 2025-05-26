#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include "Customer.h"

class Cafe;  // forward declaration of cafe

class Employee {
 protected:
  bool isBusy;  // whether an employee is busy or not
  std::time_t waitTime;
  bool wasCalled;
  std::string label;
  int customerNo;

  sf::Shape* body;
  sf::Clock busyTimer;

 public:
  // constructor
  Employee();

  // virtual function making Employee an abstract class
  virtual void doTask(Customer* customer, Cafe* cafe) = 0;

  // getters and setters
  bool get_isBusy();
  void set_isBusy(bool status);
  bool get_wasCalled();
  void set_wasCalled(bool status);
  std::time_t get_waitTime();
  std::string get_label();
  int get_customerNo();

  // draw employee
  void draw(sf::RenderWindow* win);

  // getters and setters for graphics properties
  int get_x();
  int get_y();
  void set_position(sf::Vector2f position);
  sf::Shape* get_body();

  // destructor
  ~Employee();
};

#endif