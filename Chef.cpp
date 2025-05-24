#include "Chef.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Cafe.h"
#include "Consumable.h"
#include "Customer.h"
#include "Employee.h"
#include "KitchenStaff.h"

using namespace std;

// constructor
Chef::Chef() : KitchenStaff() {
  body->setFillColor(sf::Color::Cyan);
  body->setPosition(240, 400);
  label = "chef";

  food.get_body()->setPosition(285, 400);
}

// doTask: sets the chef to busy and sets their timer for cooking the food
void Chef::doTask(Customer* customer, Cafe* cafe) {
  if (!customer->get_isActive()) {
    std::cout << "Customer is not in cafe!" << std::endl;
  } else if (customer->get_hunger() == 5) {
    std::cout << "Customer is not hungry!" << std::endl;
  } else {
    // check if chef's busy time has expired
    if (waitTime <= std::time(nullptr) - 10) {
      isBusy = false;
    }
    if (isBusy == true) {
      std::cout << "chef is busy!" << std::endl;
    } else {
      // begin cooking process
      std::cout << "cooking..." << std::endl;
      isBusy = true;
      waitTime = std::time(nullptr);
      wasCalled = true;
      this-> customerNo = customer->get_customerNo();
    }
  }
}

// destructor
Chef::~Chef() {}