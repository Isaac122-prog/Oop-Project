#include "Barista.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Cafe.h"
#include "Consumable.h"
#include "Customer.h"
#include "Employee.h"
#include "KitchenStaff.h"

using namespace std;

// constructor
Barista::Barista() : KitchenStaff() {
  body->setFillColor(sf::Color::Magenta);
  body->setPosition(140, 400);

  drink.get_body()->setPosition(145, 400);
}

// doTask: sets the barista to busy and sets their timer for brewing the drinks
void Barista::doTask(Customer* customer, Cafe* cafe) {
  if (!customer->get_isActive()) {
    std::cout << "Customer is not in cafe!" << std::endl;
  } else if (customer->get_thirst() == 5) {
    std::cout << "Customer is not thirsty!" << std::endl;
  } else {
    // check if barista's busy time has expired
    if (waitTime <= std::time(nullptr) - 10) {
      isBusy = false;
    }
    if (isBusy == true) {
      cout << "barista is busy!" << endl;
    } else {
      // start brewing process
      std::cout << "brewing..." << std::endl;
      isBusy = true;
      waitTime = std::time(nullptr);
      wasCalled = true;
    }
  }
}

// destructor
Barista::~Barista() {}