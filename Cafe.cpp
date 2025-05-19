#include "Cafe.h"

#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Barista.h"
#include "Chef.h"
#include "Cleaner.h"
#include "Customer.h"
#include "Employee.h"
#include "KitchenStaff.h"
#include "Waiter.h"

using namespace sf;

Cafe::Cafe() {
  maxCustomers = 0;
  customers = new Customer[maxCustomers];
  tables = new Table[maxCustomers];
  numActiveCustomers = 0;
  player = Player();
  waiter = Waiter();
  cleaner = Cleaner();
  chef = Chef();
  barista = Barista();
}

Cafe::Cafe(int max, int size, std::string title) {
  win = new ::sf::RenderWindow(sf::VideoMode(size, size), title);

  maxCustomers = max;
  // maximum game duration will be 2 minutes for every customer
  gameDuration = chrono::seconds(maxCustomers * 120);

  // releasing the first customer
  customers[0].set_isActive(true);
  numActiveCustomers = 1;

  // creating an array of tables
  tables = new Table[maxCustomers];

  // assigning tables to the table pointer array
  for (int j = 0; j < maxCustomers; j++) {
    tables[j] = Table();
  }

  customers = new Customer[maxCustomers];

  // assigning customers to the customer pointer array
  for (int i = 0; i < maxCustomers; i++) {
    customers[i] = Customer(tables[i]);
  }

  player = Player();
  waiter = Waiter();
  cleaner = Cleaner();
  chef = Chef();
  barista = Barista();
}

void Cafe::drawFrame(){
    
}

void Cafe::run(){
  while (win->isOpen()){
    sf::Event e;
    while (win->pollEvent(e)) {
      if (e.type == Event::Closed) {
        win->close();
      }
      if (Keyboard::isKeyPressed(Keyboard::A)) {  // key bindings
          // key bindings
      }
    }
    win->clear();
    drawFrame();
    win->display();
  }
}

int Cafe::get_maxCustomers() { return maxCustomers; }

chrono::seconds Cafe::get_gameDuration() { return gameDuration; }

// returns the customer you want the attributes of
Customer Cafe::get_customer(int customerNumber) {
  return customers[customerNumber];
}

// introduces the next customer based on the previous customer's stats
void Cafe::newCustomer() {
  for (int i = 1; i < maxCustomers; i++) {
    if (customers[i].get_isActive() == false &&
        customers[i - 1].get_isActive() == true &&
        customers[i - 1].get_happiness() >=
            13) {  // OR TIME RUNS OUT TO 0 -> SEE CUSTOMER DATA MEMBERS
      customers[i].set_isActive(true);
      numActiveCustomers++;
      break;
    }
  }
}

// customers will leave if they have a happiness of 15
void Cafe::CustomerLeaves() {
  for (int i = 0; i < maxCustomers; i++) {
    if (customers[i].get_isActive() == true &&
        customers[i].get_happiness() == 15) {
      customers[i].set_isActive(false);
      numActiveCustomers--;
    }
  }
}

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
Cleaner Cafe::get_cleaner() { return cleaner; }
Waiter Cafe::get_waiter() { return waiter; }
Chef Cafe::get_chef() { return chef; }
Barista Cafe::get_barista() { return barista; }