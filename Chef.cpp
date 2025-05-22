#include "Chef.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Cafe.h"
#include "Consumable.h"
#include "Customer.h"
#include "Employee.h"
#include "KitchenStaff.h"

using namespace std;

Chef::Chef() : KitchenStaff() {
  body->setFillColor(sf::Color::Cyan);
  body->setPosition(200, 400);

  food.get_body()->setPosition(200, 400);
}

void Chef::doTask(Customer* customer, Cafe* cafe) {
  // the chef's task is to make the food servings
  if (!customer->get_isActive()) {
    std::cout << "Customer is not in cafe!" << std::endl;
  } else if (customer->get_hunger() == 5) {
    std::cout << "Customer is not hungry!" << std::endl;
  } else {
    if (waitTime <= std::time(nullptr)-10) {
      isBusy = false;
    }
    // check chef is not busy
    if (isBusy == true) {
      std::cout << "chef is busy!" << std::endl;
    } else {
      std::cout << "cooking..." << std::endl;
      isBusy = true;
      waitTime = std::time(nullptr);
      wasCalled = true;
    }
  }
}

Chef::~Chef() {}