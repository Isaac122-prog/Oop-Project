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
  int runTime;  // runtime of the cafe

  // customer objects and properties
  int maxCustomers;
  Customer* customers;
  int numActiveCustomers; // no. customer that have been/are active
  int activeCustomer; // for keybindings

  // objects in the cafe
  Player player;
  Table* tables;

  vector<Employee*> employees; 
  int maxEmployees;
  int employeeType;

  // number of consumables available to serve
  int numFood;
  int numDrink;

 public:
  sf::Clock startTime; 

  // default constructor
  Cafe();

  // constructor
  Cafe(int max);

  // getters and setters
  int get_maxCustomers();
  void set_maxCustomers(int maxCustomers);

  int get_gameDuration();
  void set_gameDuration();

  void set_activeCustomer(int customerNo);
  int get_activeCustomer();

  int get_numActiveCustomers();
  void set_numActiveCustomers(int activeCustomers);

  int get_maxEmployees();
  void set_maxEmployees(int maxEmployees);

  Employee* get_employee(int employeeNo);

  int get_employeeType();
  void set_employeeType(int employeeType);

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

  // object pointer getters
  Customer* get_customerPointer(int customerNumber);

  // adds a new employee based on employeeType
  void add_newEmployee();

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