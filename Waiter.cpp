#include "Waiter.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Cafe.h"
#include "Customer.h"
#include "Employee.h"
#include "KitchenStaff.h"

using namespace std;

// constructor
Waiter::Waiter() : Employee() {
  body->setFillColor(sf::Color::Yellow);
  body->setPosition(360, 400);
}

// doTask: sets the waiter to busy and sets their timer for serving the
// consumables
void Waiter::doTask(Customer* customer, Cafe* cafe) {
  if (!customer->get_isActive()) {
    std::cout << "Customer is not in cafe!" << std::endl;
  } else {
    if (waitTime <= std::time(nullptr) - 10) {
      isBusy = false;
    }
    if (isBusy == true) {
      cout << "waiter is busy!" << endl;
    } else {
      if (cafe->get_numFood() == 0 && cafe->get_numDrink() == 0) {
        cout << "no food or drink to be served!" << endl;
      }
      if (cafe->get_numFood() > 0 && customer->get_hunger() < 5) {
        // begin serving food
        std::cout << "serving food... " << std::endl;
        isBusy = true;
        waitTime = std::time(nullptr);
        wasCalled = true;
      }
      if (cafe->get_numDrink() > 0 && customer->get_thirst() < 5) {
        // begin serving drink
        std::cout << "serving drink..." << std::endl;
        isBusy = true;
        waitTime = std::time(nullptr);
        wasCalled = true;
      }
    }
  }
}

// destructor
Waiter::~Waiter() {}