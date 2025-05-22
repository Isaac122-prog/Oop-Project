#include "Waiter.h"

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Cafe.h"
#include "Customer.h"
#include "Employee.h"
#include "KitchenStaff.h"

// ISSUE: BREWS/COOKS/SERVES TOO FAST, DOES NOT WAIT FOR BUSY TIMER

using namespace std;

Waiter::Waiter() : KitchenStaff() {
  
  body->setFillColor(sf::Color::Yellow);
  body->setPosition(300, 400);

  // info->setPosition(300,400);
}

// waiter will be called using button 'call waiter for table 2 or smth'

void Waiter::doTask(Customer* customer, Cafe* cafe) {
  // the waiter's task is to serve the food to the customer
  if (!customer->get_isActive()) {
    std::cout << "Customer is not in cafe!" << std::endl;
  } else {
    // check waiter is not busy
    if (waitTime <= std::time(nullptr)-10) {
      isBusy = false;
    }
    if (isBusy == true) {
      cout << "waiter is busy!" << endl;
    } else {
      // TRICKY: waiter can only serve food/drink if they have been made
      if (cafe->get_numFood() == 0 && cafe->get_numDrink() == 0) {
        cout << "no food or drink to be served!" << endl;
      }
      if (cafe->get_numFood() > 0 && customer->get_hunger() < 5) {
        std::cout << "serving food... " << std::endl;
        isBusy = true;
        waitTime = std::time(nullptr);
      }
      if (cafe->get_numDrink() > 0 && customer->get_thirst() < 5){
        std::cout << "serving drink..." << std::endl;
        isBusy = true;
        waitTime = std::time(nullptr);
      }
    }
  }
}

Waiter::~Waiter(){}