#ifndef CAFE_H
#define CAFE_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <vector>

#include "Barista.h"
#include "Chef.h"
#include "Cleaner.h"
#include "Consumable.h"
#include "Customer.h"
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
 private:
  // sf::RenderWindow* win; TO BE DELETED

  int runTime;  // runtime of the cafe

  // customer objects and properties
  int maxCustomers;
  Customer* customers;
  int numActiveCustomers; // no. customer that have been/are active
  int activeCustomer;

  // objects in the cafe
  Player player;
  // Waiter waiter;
  // Cleaner cleaner;
  // Chef chef;
  // Barista barista;
  Table* tables;

  vector<Employee*> employees;
  int maxEmployees;
  int newEmployee;

  // number of consumables available to serve
  int numFood;
  int numDrink;

 public:
  sf::Clock startTime;  // CHECK WHERE THIS SHOULD BE

  // default constructor
  Cafe();

  // constructor
  Cafe(int max);

  // getters and setters
  int get_maxCustomers();
  int get_gameDuration();

  void set_activeCustomer(int customerNo);
  int get_activeCustomer();

  int get_numActiveCustomers();

  int get_maxEmployees();
  Employee* get_employee( int i);

  int get_numFood();
  void increase_numFood();
  void decrease_numFood();
  int get_numDrink();
  void increase_numDrink();
  void decrease_numDrink();

  // object getters
  Customer get_customer(int customerNumber);
  Table get_table(int tableNo);
  Player get_player();
  Cleaner get_cleaner();
  Waiter get_waiter();
  Chef get_chef();
  Barista get_barista();

  // object pointer getters
  Customer* get_customerPointer(int customerNumber);
  Cleaner* get_cleanerPointer();
  Waiter* get_waiterPointer();
  Chef* get_chefPointer();
  Barista* get_baristaPointer();

  // introduces the next customer based on the previous
  // customer's stats
  void newCustomer();

  // customer leaves based on their stats
  void customerLeaves();

  // add a new employee
  int add_employee();

  // displays performance to player
  void viewPerformance();

  // destructor
  ~Cafe();
};

#endif