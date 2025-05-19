#include "Chef.h"

#include <chrono>
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
  if (customer->get_thirst() == 5) {
    std::cout << "Customer is not thirsty!" << std::endl;
  } else if (!customer->get_isActive()) {
    std::cout << "Customer is not in cafe!" << std::endl;
  } else {
    // check chef is not busy
    if (isBusy == true) {
      cout << "chef is busy!" << endl;
    } else {
      // wait for 15 seconds -> FROM CHAT GPT
      auto startTime = chrono::steady_clock::now();
      auto duration = chrono::seconds(15);

      // set chef to busy during 15 second wait period
      while (chrono::steady_clock::now() - startTime < duration) {
        isBusy = true;
      }

      // finished cooking!
      cafe->increase_numFood();

      isBusy = false;
    }
  }
}