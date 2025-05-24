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
    if (maxCustomers > 5){
      divisor1 = 4;
      divisor2 = maxCustomers-6;
    } else {
      divisor1 = maxCustomers;
    }
    tables[j] = Table(j);
    if (j < 5) {
      tables[j].get_body()->setPosition((50 + (600 / (divisor1)) * j), 50);
    } else {
      tables[j].get_body()->setPosition((50 + (600 / (divisor2)) * (j - 5)), 250);
    }
  }

  // creating an array of customers
  customers = new Customer[maxCustomers];

  // assigning customers to the customer pointer array
  for (int i = 0; i < maxCustomers; i++) {
    customers[i] = Customer(tables[i], i);  // note first customer is customer0
    if (i < 5) {
      customers[i].get_body()->setPosition((50 + (600 / (4)) * i), 50);
    } else {
      customers[i].get_body()->setPosition((50 + (600 / (4)) * (i - 5)), 250);
    }
  }

  // releasing the first customer
  customers[0].set_isActive(true);
  numActiveCustomers = 1;
  activeCustomer = -1;

  // Add different types of employees
  employees.push_back(new Chef());
  employees.push_back(new Barista());
  employees.push_back(new Waiter());
  employees.push_back(new Cleaner());

  maxEmployees = 4;

  player = Player();
  waiter = Waiter();
  cleaner = Cleaner();
  chef = Chef();
  barista = Barista();

  numFood = 0;
  numDrink = 0;
}

// getters and setters
int Cafe::get_maxCustomers() { return maxCustomers; }
int Cafe::get_gameDuration() { return runTime; }

void Cafe::set_activeCustomer(int customerNo) { activeCustomer = customerNo; }
int Cafe::get_activeCustomer() { return activeCustomer; }

int Cafe::get_maxEmployees(){ return maxEmployees;}
Employee* Cafe::get_employee(int i){ return employees[i];}

int Cafe::get_numFood() { return numFood; }
void Cafe::increase_numFood() {
  numFood++;
  chef.set_wasCalled(false);
}
void Cafe::decrease_numFood() { numFood--; }

int Cafe::get_numDrink() { return numDrink; }
void Cafe::increase_numDrink() {
  numDrink++;
  barista.set_wasCalled(false);
}
void Cafe::decrease_numDrink() { numDrink--; }

// object getters
Customer Cafe::get_customer(int customerNumber) {
  return customers[customerNumber];  // returns the customer you want the
                                     // attributes of
}
Table Cafe::get_table(int tableNo) { return tables[tableNo]; }
Player Cafe::get_player() { return player; }
Cleaner Cafe::get_cleaner() { return cleaner; }
Waiter Cafe::get_waiter() { return waiter; }
Chef Cafe::get_chef() { return chef; }
Barista Cafe::get_barista() { return barista; }

// object pointer getters
Customer* Cafe::get_customerPointer(int customerNumber) {
  return &customers[customerNumber];
}
Cleaner* Cafe::get_cleanerPointer() { return &cleaner; }
Waiter* Cafe::get_waiterPointer() { return &waiter; }
Chef* Cafe::get_chefPointer() { return &chef; }
Barista* Cafe::get_baristaPointer() { return &barista; }

// introduces the next customer based on the previous customer's stats
void Cafe::newCustomer() {
  for (int i = 1; i < maxCustomers; i++) {
    if ((customers[i].get_isActive() == false &&
         customers[i - 1].get_happiness() >= 13) ||
        std::time_t(nullptr) >= customers[i].get_endTime()) {
      if (numActiveCustomers < maxCustomers) {
        customers[i].set_isActive(true);
        // get_customerPointer(i)->set_disgustTime();
        // get_customerPointer(i)->set_startTime();
        numActiveCustomers++;
        break;
      }
    }
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
void Cafe::add_employee() {
  if (numActiveCustomers > 2) {
    char employee;
    std::cout << "congrats! you can now add a new employee" << std::endl;
    std::cout
        << "press Z for barista, X for chef, C for waiter, and V for cleaner"
        << std::endl;
    cin >> employee;
    while (employee != 'z' && employee != 'x' && employee != 'c' &&
           employee != 'v') {
      std::cout << "wrong key! please type a valid option" << std::endl;
    }
    switch (employee) {
      case 'z':
        std::cout << "you selected: barista" << std::endl;
        employees.push_back(new Barista());
        // employees[4]->get_drink().get_body()->setPosition(145, 400);
        break;
      case 'x':
      std::cout << "you selected: chef" << std::endl;
        employees.push_back(new Chef());
        break;
      case 'c':
      std::cout << "you selected: waiter" << std::endl;
        employees.push_back(new Waiter());
        break;
      case 'v':
      std::cout << "you selected: cleaner" << std::endl;
        employees.push_back(new Cleaner());
        break;
      default:
        break;
    }
    maxEmployees++;
    employees[4]->get_body()->setPosition(600, 400);
  }
}

// view the customer's scoring
void Cafe::viewPerformance() {
  cout << "performance:" << endl;
  int count = 0;
  for (int i = 0; i < numActiveCustomers; i++) {
    cout << "customer " << i << " score: " << get_customer(i).get_happiness()
         << "/15" << endl;
    count += get_customer(i).get_happiness();
  }
  cout << "final score: " << count << "/" << numActiveCustomers * 15 << endl;
  ;
}

// destructor
Cafe::~Cafe() {
  delete[] customers;
  delete[] tables;
}