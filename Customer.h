#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Table.h"
// #include "Food.h"
// #include "Drink.h"

#include <ctime>
#include <random>

class Customer {
 protected:
  int hunger;
  int disgust;
  int thirst;
  int happiness;
  bool isActive;

  Table tableNo;  // was originally a pointer but i've changed it bc of the
                  // error...
  // Food foodServing;
  // Drink drinkServing;

  std::time_t startTime;
  std::time_t endTime;

  sf::RectangleShape* body;
  std::string customerAttributes;

 public:
  Customer();  // default constructor
  Customer(Table tableNo, int customerNo);

  void draw(sf::RenderWindow* win);
  sf::RectangleShape* get_body();

  void set_customerAttributes();
  std::string get_customerAttributes() const;

  int get_x() const;
  int get_y() const;
  void set_position(sf::Vector2f position);

  void set_isActive(bool state);
  bool get_isActive();

  void increase_hunger();
  void decrease_hunger();
  int get_hunger();

  void increase_thirst();
  void decrease_thirst();
  int get_thirst();

  void increase_disgust();
  void decrease_disgust(Table table);
  int get_disgust();

  void set_tableNo(Table tableNo);
  Table get_tableNo();

  // Drink get_drink();
  // Food get_food();

  int get_happiness();
  void print_attributes();
  // void draw_text(sf::RenderWindow* win);

  std::time_t get_startTime();
  std::time_t get_endTime();

  ~Customer();
};

#endif