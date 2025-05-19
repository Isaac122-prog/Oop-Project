#include "Chef.h"

#include <chrono>
#include <iostream>

#include "Customer.h"
#include "Employee.h"
#include "KitchenStaff.h"

using namespace std;

Chef::Chef() : KitchenStaff() {
  body = new sf::RectangleShape(sf::Vector2f(10, 40));
  body->setFillColor(sf::Color::Cyan);
  body->setOrigin(10, 10);
  body->setPosition(200, 400);
}

void Chef::doTask(Customer* customerNo) {
  // the chef's task is to make the food servings

  // check chef is not busy
  if (isBusy = true) {
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
    numFood++;

    isBusy = false;
  }
}