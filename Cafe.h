#ifndef CAFE_H
#define CAFE_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include "Barista.h"
#include "Chef.h"
#include "Cleaner.h"
#include "Customer.h"
#include "Consumable.h"
#include "Employee.h"
#include "KitchenStaff.h"
#include "Player.h"
#include "Table.h"
#include "Waiter.h"

using namespace std;

class Employee;
class KitchenStaff;
class Waiter;
class Barista;
class Chef;

class Cafe {
 protected:
    sf::RenderWindow* win;

  int runTime;

  int maxCustomers;
  Customer* customers;
  int numActiveCustomers;
  int activeCustomer;

  Consumable baristaDrink;
  Consumable chefFood;
  Table* tables;

  int numFood;
  int numDrink;

  Player player;
  Waiter waiter;
  Cleaner cleaner;
  Chef chef;
  Barista barista;

 public:
  sf::Clock startTime;  // CHECK WHERE THIS SHOULD BE

  Cafe();
  Cafe(int max);

  int get_maxCustomers();
  int get_gameDuration();

  void newCustomer();     // introduces the next customer based on the previous
                          // customer's stats
  void customerLeaves();  // customer leaves based on their stats

  void viewPerformance();

  Customer get_customer(int customerNumber);
  Customer* get_customerPointer(int customerNumber);
  Table get_table(int tableNo);
  Player get_player();
  Cleaner get_cleaner();
  Waiter get_waiter();
  Chef get_chef();
  Barista get_barista();
  
  Cleaner* get_cleanerPointer();
  Waiter* get_waiterPointer();
  Chef* get_chefPointer();
  Barista* get_baristaPointer();

  int get_numFood();
  void increase_numFood();
  void decrease_numFood();
  int get_numDrink();
  void increase_numDrink();
  void decrease_numDrink();

  void set_baristaDrink(bool status);
  void set_chefFood(bool status);

  void set_activeCustomer(int customerNo);
  int get_activeCustomer();

  ~Cafe();
};

#endif