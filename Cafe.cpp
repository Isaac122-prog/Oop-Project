#include "Cafe.h"

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

using namespace sf;

Cafe::Cafe() { std::cout << "function is unusable" << endl; }

Cafe::Cafe(int max) {
  // maximum game duration will be 2 minutes for every customer
  maxCustomers = max;
  runTime = maxCustomers * 120;

  // creating an array of tables
  tables = new Table[maxCustomers];

  // assigning tables to the table pointer array
  for (int j = 0; j < maxCustomers; j++) {
    int divisor1;
    int divisor2;
    if (maxCustomers < 5) {
      divisor1 = maxCustomers - 1;
    } else {
      divisor1 = 4;
      divisor2 = maxCustomers - 6;
    }
    tables[j] = Table(j);
    if (j < 5) {
      tables[j].get_body()->setPosition((100 + (600 / (divisor1)) * (j)), 50);
    } else {
      tables[j].get_body()->setPosition((100 + (600 / (divisor2)) * (j - 5)),
                                        200);
    }
  }

  // creating an array of customers
  customers = new Customer[maxCustomers];

  // assigning customers to the customer pointer array
  for (int i = 0; i < maxCustomers; i++) {
    int divisor1;
    int divisor2;
    if (maxCustomers < 5) {
      divisor1 = maxCustomers - 1;
    } else {
      divisor1 = 4;
      divisor2 = maxCustomers - 6;
    }
    customers[i] = Customer(tables[i], i);  // note first customer is customer0
    if (i < 5) {
      customers[i].get_body()->setPosition((100 + (600 / (divisor1)) * (i)),
                                           50);
    } else {
      customers[i].get_body()->setPosition((100 + (600 / (divisor2)) * (i - 5)),
                                           200);
    }
  }

  // releasing the first customer
  customers[0].set_isActive(true);
  numActiveCustomers = 1;
  activeCustomer = -1;

  // Add different types of employees
  employees.push_back(new Barista());
  employees.push_back(new Chef());
  employees.push_back(new Waiter());
  employees.push_back(new Cleaner());

  maxEmployees = 4;   // initialising number of employees
  employeeType = -1;  // initialising type of new employee (currently invalid)

  player = Player();

  // initialising number available to serve
  numFood = 0;
  numDrink = 0;
}

// getters and setters
int Cafe::get_maxCustomers() { return maxCustomers; }
void Cafe::set_maxCustomers(int maxCustomers) {
  this->maxCustomers = maxCustomers;
}

int Cafe::get_gameDuration() { return runTime; }
void Cafe::set_gameDuration() { runTime = maxCustomers * 120; }

void Cafe::set_activeCustomer(int customerNo) { activeCustomer = customerNo; }
int Cafe::get_activeCustomer() { return activeCustomer; }

int Cafe::get_numActiveCustomers() { return numActiveCustomers; }
void Cafe::set_numActiveCustomers(int activeCustomers) {
  numActiveCustomers = activeCustomers;
}

int Cafe::get_maxEmployees() { return maxEmployees; }
void Cafe::set_maxEmployees(int maxEmployees) {
  this->maxEmployees = maxEmployees;
}

Employee* Cafe::get_employee(int employeeNo) { return employees[employeeNo]; }

int Cafe::get_employeeType() { return employeeType; }
void Cafe::set_employeeType(int employeeType) {
  this->employeeType = employeeType;
}

int Cafe::get_numFood() { return numFood; }
void Cafe::increase_numFood() {
  numFood++;
  employees[1]->set_wasCalled(false);
}
void Cafe::decrease_numFood() { numFood--; }

int Cafe::get_numDrink() { return numDrink; }
void Cafe::increase_numDrink() {
  numDrink++;
  employees[0]->set_wasCalled(false);
}
void Cafe::decrease_numDrink() { numDrink--; }

// object getters
Customer Cafe::get_customer(int customerNumber) {
  return customers[customerNumber];  // returns the customer you want the
                                     // attributes of
}
Table Cafe::get_table(int tableNo) { return tables[tableNo]; }
Player Cafe::get_player() { return player; }

// object pointer getters
Customer* Cafe::get_customerPointer(int customerNumber) {
  return &customers[customerNumber];
}

// adds a new employee based on employeeType
void Cafe::add_newEmployee() {
  if (employeeType == 0) {
    employees.push_back(new Waiter());
  } else if (employeeType == 1) {
    employees.push_back(new Cleaner());
  }
}

// introduces the next customer based on the previous customer's stats
void Cafe::newCustomer() {
  for (int i = 1; i < maxCustomers; i++) {
    if ((!customers[i].get_isActive() &&
         customers[i - 1].get_happiness() >= 12) ||
        std::time_t(nullptr) >= customers[i - 1].get_endTime()) {
      customers[i].set_isActive(true);            // set next customer to active
      get_customerPointer(i)->set_disgustTime();  // set disgust time
      get_customerPointer(i)->set_startTime();    // set start time
      if (numActiveCustomers < maxCustomers) {
        numActiveCustomers++;  // increase number of active customers
        break;
      }
    }
  }
  if ((customers[maxCustomers - 1].get_isActive() &&
       customers[maxCustomers - 1].get_happiness() == 15) ||
      std::time_t(nullptr) >= customers[maxCustomers - 1].get_endTime()) {
    numActiveCustomers++;  // increment if last customer has
                           // left
  }
}

// customers will leave if they have a happiness of 15
void Cafe::customerLeaves() {
  for (int i = 0; i < maxCustomers; i++) {
    if ((customers[i].get_isActive() == true &&
         customers[i].get_happiness() == 15) ||
        std::time_t(nullptr) >= customers[i].get_endTime()) {
      customers[i].set_isActive(false);
    }
  }
}

// add a new employee
int Cafe::add_employee() {
  if (maxCustomers <= 2) {
    employeeType = -1;  // ensure there are enough customers
  } else if (!customers[1].get_isActive() && customers[2].get_isActive() &&
             maxEmployees == 4) {
    char employee;
    std::cout << "congrats! you can now add a new employee" << std::endl;
    std::cout << "press Z for waiter, or X for cleaner" << std::endl;
    std::cin >> employee;
    while (employee != 'z' && employee != 'x') {
      std::cout << "wrong key! please type a valid option" << std::endl;
      std::cin >> employee;
    }
    switch (employee) {
      case 'z':
        std::cout << "you selected: waiter" << std::endl;
        employees.push_back(new Waiter());  // add waiter to vector
        employeeType = 0;                   // set employee type to waiter

        break;
      case 'x':
        std::cout << "you selected: cleaner" << std::endl;
        employees.push_back(new Cleaner());  // add cleaner to vector
        employeeType = 1;                    // set employee type to cleaner

        break;
      default:
        std::cout << "you have not selected an employee" << std::endl;
        break;
    }
    maxEmployees++;                                   // increase no employees
    employees[4]->get_body()->setPosition(600, 400);  // set graphics posiiton
  }
  return employeeType;
}

// view the customer's scoring
void Cafe::viewPerformance() {
  std::cout << "active customers final: " << numActiveCustomers << std::endl;
  cout << "performance:" << endl;
  int count = 0;
  for (int i = 0; i < numActiveCustomers - 1; i++) {
    cout << "customer " << i + 1
         << " score: " << get_customer(i).get_happiness() << "/15" << endl;
    count += get_customer(i).get_happiness();
  }
  cout << "final score: " << count << "/" << (numActiveCustomers - 1) * 15
       << endl;
  ;
}

// destructor
Cafe::~Cafe() {
  delete[] customers;
  delete[] tables;
}