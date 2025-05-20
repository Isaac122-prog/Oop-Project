#include "Chef.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Customer.h"
#include "Employee.h"
#include "KitchenStaff.h"
#include "Cafe.h"

using namespace std;

Chef::Chef() : KitchenStaff() {
  body = new sf::RectangleShape(sf::Vector2f(10, 40));
  body->setFillColor(sf::Color::Cyan);
  body->setOrigin(10, 10);
  body->setPosition(200, 400);
}

void Chef::doTask(Customer* customer, Cafe* cafe) {
  // the chef's task is to make the food servings
  if (customer->get_hunger() == 5) {
    std::cout << "Customer is not hungry!" << std::endl;
  } else if (!customer->get_isActive()) {
    std::cout << "Customer is not in cafe!" << std::endl;
  } else {
    if (busyTimer.getElapsedTime().asSeconds() >= 15) {
      isBusy = false;
    }
    // check chef is not busy
    if (isBusy == true) {
      std::cout << "chef is busy!" << std::endl;
    } else {
      std::cout << "cooking..." << std::endl;
      isBusy = true;
      busyTimer.restart();
      // finished cooking!
      cafe->increase_numFood();

    }
  }
}