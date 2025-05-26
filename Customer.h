#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <random>

#include "Table.h"

class Customer {
 protected:
  bool isActive;
  Table tableNo;  // corresponding table of the customer
  int customerNo;

  int hunger;
  int disgust;
  int thirst;
  int happiness;
  std::string customerAttributes;

  std::time_t startTime;  // customer's timer
  std::time_t endTime;
  std::time_t disgustTime;  // customer's timer for depleting disgust

  sf::RectangleShape* body;

 public:
  // default constructor
  Customer();
  // constructor
  Customer(Table tableNo, int customerNo);

  // getters and setters
  void set_customerAttributes();
  std::string get_customerAttributes() const;

  void set_isActive(bool state);
  bool get_isActive();

  void set_tableNo(Table tableNo);
  Table get_tableNo();

  int get_customerNo();

  int get_happiness();

  std::time_t get_startTime();
  void set_startTime();
  std::time_t get_endTime();
  std::time_t get_disgustTime();
  void set_disgustTime();

  // getters and setters: hunger
  void increase_hunger();
  void decrease_hunger();
  void set_hunger(int hunger);
  int get_hunger();

  // getters and setters: thirst
  void increase_thirst();
  void decrease_thirst();
  void set_thirst(int thirst);
  int get_thirst();

  // getters and setters: disgust
  void increase_disgust();
  void decrease_disgust(Table table);
  void set_disgust(int disgust);
  int get_disgust();

  // for debugging: print customer stats
  void print_attributes();

  // draw customer
  void draw(sf::RenderWindow* win);

  // graphics getters and setters
  int get_x() const;
  int get_y() const;
  sf::RectangleShape* get_body();
  void set_position(sf::Vector2f position);

  // destructor
  ~Customer();
};

#endif