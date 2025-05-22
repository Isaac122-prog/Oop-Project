#include "Cafe.h"

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

using namespace sf;

Cafe::Cafe() {
  maxCustomers = 0;
  customers = new Customer[maxCustomers];
  tables = new Table[maxCustomers];
  // foodServings = new Food[maxCustomers+1];
  // drinks = new Drink[maxCustomers+1];
  numFood = 0;
  numDrink = 0;
  numActiveCustomers = 0;
  player = Player();
  waiter = Waiter();
  cleaner = Cleaner();
  chef = Chef();
  barista = Barista();
  runTime = 0;
}

Cafe::Cafe(int max) {
  // maximum game duration will be 2 minutes for every customer
  maxCustomers = max;
  runTime = maxCustomers * 120;

  // creating an array of tables
  tables = new Table[maxCustomers];

  // assigning tables to the table pointer array
  for (int j = 0; j < maxCustomers; j++) {
    tables[j] = Table(j);
    tables[j].get_body()->setPosition((500 / (maxCustomers + 1)) * (j + 1), 30);
  }

  // // creating an array of food servings
  // foodServings = new Food[maxCustomers+1];

  // // assigning food
  // for (int k = 0; k < maxCustomers+1; k++) {
  //   foodServings[k] = Food();
  // }

  // // creating an array of drinks
  // drinks = new Drink[maxCustomers+1];

  // // assigning drinks
  // for (int l=0; l<maxCustomers+1; l++){
  //   drinks[l] = Drink();
  // }

  numFood = 0;
  numDrink = 0;

  customers = new Customer[maxCustomers];

  // assigning customers to the customer pointer array
  for (int i = 0; i < maxCustomers; i++) {
    customers[i] = Customer(tables[i], i);  // note first customer is customer0
    customers[i].get_body()->setPosition((500 / (maxCustomers + 1)) * (i + 1),
                                         30);
  }

  // releasing the first customer
  customers[0].set_isActive(true);
  numActiveCustomers = 1;
  customers[0].print_attributes();  // TO BE DELETED LATER
  activeCustomer = -1;

  player = Player();
  waiter = Waiter();
  cleaner = Cleaner();
  chef = Chef();
  barista = Barista();
}

int Cafe::get_maxCustomers() { return maxCustomers; }

int Cafe::get_gameDuration() { return runTime; }

// returns the customer you want the attributes of
Customer Cafe::get_customer(int customerNumber) {
  return customers[customerNumber];
}

Customer* Cafe::get_customerPointer(int customerNumber) {
  return &customers[customerNumber];
}

// introduces the next customer based on the previous customer's stats
void Cafe::newCustomer() {
  for (int i = 1; i < maxCustomers; i++) {
    if (customers[i].get_isActive() == false &&
            customers[i - 1].get_happiness() >= 13 ||
        std::time_t(nullptr) >= customers[i].get_endTime()) {
      if (numActiveCustomers < maxCustomers) {
        customers[i].set_isActive(true);
        numActiveCustomers++;
        customers[i].print_attributes();  // TO BE DELETED LATER AND REPLACED
                                          // WITH A SCREEN DISPLAY
        break;
      }
    }
  }
}

// customers will leave if they have a happiness of 15
void Cafe::customerLeaves() {
  for (int i = 0; i < maxCustomers; i++) {
    if (customers[i].get_isActive() == true &&
            customers[i].get_happiness() == 15 ||
        std::time_t(nullptr) >= customers[i].get_endTime()) {
      customers[i].set_isActive(false);
      // numActiveCustomers--; TESTING SOMETHING HERE
    }
  }
} // FINAL CUSTOMER WON'T LEAVE WHY IS THAT...

// view the customer's scoring
void Cafe::viewPerformance() {
  cout << maxCustomers << endl;

  for (int i = 0; i < maxCustomers; i++) {
    cout << "customer " << i << " score: " << get_customer(i).get_happiness()
         << endl;
  }
}

// getters
Cleaner Cafe::get_cleaner() { return cleaner; }
Table Cafe::get_table(int tableNo) { return tables[tableNo]; }
Player Cafe::get_player() { return player; }
Waiter Cafe::get_waiter() { return waiter; }
Chef Cafe::get_chef() { return chef; }
Barista Cafe::get_barista() { return barista; }

int Cafe::get_numFood() { return numFood; }
void Cafe::increase_numFood() { numFood++; }
void Cafe::decrease_numFood() { numFood--; }

int Cafe::get_numDrink() { return numDrink; }
void Cafe::increase_numDrink() { numDrink++; }
void Cafe::decrease_numDrink() { numDrink--; }

void Cafe::set_activeCustomer(int customerNo) { activeCustomer = customerNo; }
int Cafe::get_activeCustomer() { return activeCustomer; }

Cafe::~Cafe() {
  delete[] customers;
  delete[] tables;
}