#include "Waiter.h"

#include <chrono>
#include <iostream>

#include "Employee.h"
#include "KitchenStaff.h"
#include "Cafe.h"
#include "Customer.h"

using namespace std;

Waiter::Waiter() : KitchenStaff() {
  body = new sf::RectangleShape(sf::Vector2f(10, 40));
  body->setFillColor(sf::Color::Yellow);
  body->setOrigin(10, 10);
  body->setPosition(300, 400);
}

// waiter will be called using button 'call waiter for table 2 or smth'

void Waiter::doTask(Customer* customer, Cafe* cafe) {
  // the waiter's task is to serve the food to the customer
  if (!customer->get_isActive()) {
    std::cout << "Customer is not in cafe!" << std::endl;
  } else {
    // check waiter is not busy
    if (isBusy == true) {
      cout << "waiter is busy!" << endl;
    } else {
      // TRICKY: waiter can only serve food/drink if they have been made
      if (cafe->get_numFood() == 0 && cafe->get_numDrink() == 0) {
        cout << "no food or drink to be served!" << endl;
      }
      if (cafe->get_numFood() > 0 && customer->get_hunger() < 5) {
        // wait for 15 seconds -> FROM CHAT GPT
        auto startTime = chrono::steady_clock::now();
        auto duration = chrono::seconds(15);

        // set waiter to busy during 15 second wait period
        while (chrono::steady_clock::now() - startTime < duration) {
          isBusy = true;
        }

        // food is served!
        cafe->decrease_numFood();
        // customer.get_Food().set_isActive(true);
        // increase customer hunger
        customer->increase_hunger();
      }

      if (cafe->get_numDrink() > 0 &&
          customer->get_thirst() < 5) {  // AND IF THE CUSTOMER'S THIRST IS NOT 5
        // wait for 15 seconds -> FROM CHAT GPT
        auto startTime = chrono::steady_clock::now();
        auto duration = chrono::seconds(15);

        // set waiter to busy during 15 second wait period
        while (chrono::steady_clock::now() - startTime < duration) {
          isBusy = true;
        }

        // drink is served!
        cafe->decrease_numDrink();
        // customer.get_drink().set_isActive(true);
        // increase customer thirst
        customer->increase_thirst();
      }

      isBusy = false;
    }
  }
}
