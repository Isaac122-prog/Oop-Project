#include "Cafe.h"

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

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
  runTime = 0;
}

Cafe::Cafe(int max, int size, std::string title) {
  win = new ::sf::RenderWindow(sf::VideoMode(size, size), title);

  // maximum game duration will be 2 minutes for every customer
  maxCustomers = max;
  runTime = maxCustomers * 120;

  // creating an array of tables
  tables = new Table[maxCustomers];

  // assigning tables to the table pointer array
  for (int j = 0; j < maxCustomers; j++) {
    tables[j] = Table(j * 30);
  }

  customers = new Customer[maxCustomers];

  // assigning customers to the customer pointer array
  for (int i = 0; i < maxCustomers; i++) {
    customers[i] = Customer(tables[i], i);  // note first customer is customer0
  }

  // releasing the first customer
  customers[0].set_isActive(true);
  numActiveCustomers = 1;

  player = Player();
  waiter = Waiter();
  cleaner = Cleaner();
  chef = Chef();
  barista = Barista();
}

void Cafe::drawFrame() {
  for (int i = 0; i < maxCustomers; i++) {
    tables[i].draw(win);
  }
  for (int j = 0; j < maxCustomers; j++) {
    customers[j].draw(win);
  }
  cleaner.draw(win);
  chef.draw(win);
  barista.draw(win);
  waiter.draw(win);
}

int Cafe::get_maxCustomers() { return maxCustomers; }

int Cafe::get_gameDuration() { return runTime; }

// returns the customer you want the attributes of
Customer Cafe::get_customer(int customerNumber) {
  return customers[customerNumber];
}

// introduces the next customer based on the previous customer's stats
void Cafe::newCustomer() {
  for (int i = 1; i < maxCustomers; i++) {
    if (customers[i].get_isActive() == false &&
            customers[i - 1].get_isActive() == true &&
            customers[i - 1].get_happiness() >= 13 ||
        std::time_t(nullptr) >=
            customers[i].get_endTime()) {  // OR TIME RUNS OUT TO 0 -> SEE
                                           // CUSTOMER DATA MEMBERS
      customers[i].set_isActive(true);
      numActiveCustomers++;
      break;
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
Waiter Cafe::get_waiter() { return waiter; }
Chef Cafe::get_chef() { return chef; }
Barista Cafe::get_barista() { return barista; }

void Cafe::keyBindings() {
  if (Keyboard::isKeyPressed(Keyboard::Num1)) {  
    activeCustomer = 0;                          
  } else if (Keyboard::isKeyPressed(Keyboard::Num2)) {  
    activeCustomer = 1;                          
  } else if (Keyboard::isKeyPressed(Keyboard::Num3)) {  
    activeCustomer = 2;                          
  } else if (Keyboard::isKeyPressed(Keyboard::Num4)) {  
    activeCustomer = 3;                          
  } else if (Keyboard::isKeyPressed(Keyboard::Num5)) {  
    activeCustomer = 4;                          
  } else if (Keyboard::isKeyPressed(Keyboard::Num6)) {  
    activeCustomer = 5;                          
  } else if (Keyboard::isKeyPressed(Keyboard::Num7)) {  
    activeCustomer = 6;                          
  } else if (Keyboard::isKeyPressed(Keyboard::Num8)) {  
    activeCustomer = 7;                          
  } else if (Keyboard::isKeyPressed(Keyboard::Num9)) {  
    activeCustomer = 8;                          
  } else if (Keyboard::isKeyPressed(Keyboard::Num0)) {  
    activeCustomer = 9;                          
  }
}

void Cafe::run() {
  while (win->isOpen()) {
    sf::Event e;
    while (win->pollEvent(e)) {
      if (e.type == Event::Closed) {
        win->close();
      }
      if (Keyboard::isKeyPressed(Keyboard::Num1)) {  // key bindings
        activeCustomer = 1;                          // key bindings
      }
    }

    sf::Clock actionClock;  // clock for incrementing how often things are
                            // checked in while loops

    if (startTime.getElapsedTime().asSeconds() < runTime) {
      if (actionClock.getElapsedTime().asSeconds() >= 1.0f) {
        newCustomer();
        customerLeaves();
      }
    }

    win->clear();
    drawFrame();
    win->display();
  }
}

Cafe::~Cafe() {
  delete[] customers;
  delete[] tables;
}