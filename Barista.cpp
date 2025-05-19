#include "Barista.h"

#include <chrono>
#include <iostream>

#include "Customer.h"
#include "Employee.h"
#include "KitchenStaff.h"
#include "Cafe.h"

using namespace std;

Barista::Barista() : KitchenStaff() {
  body = new sf::RectangleShape(sf::Vector2f(10, 40));
  body->setFillColor(sf::Color::Magenta);
  body->setOrigin(10, 10);
  body->setPosition(100, 400);
}

void Barista::doTask(Customer* customer, Cafe* cafe) {
  // the barista's task is to make the drinks
  if (customer->get_thirst() == 5) {
    std::cout << "Customer is not thirsty!" << std::endl;
  } else if (!customer->get_isActive()){
    std::cout << "Customer is not in cafe!" << std:: endl;
  } else {
    // check barista is not busy
    if (isBusy == true) {
      cout << "barista is busy!" << endl;
    } else {
      // wait for 15 seconds -> FROM CHAT GPT
      auto startTime = chrono::steady_clock::now();
      auto duration = chrono::seconds(15);

      // set barista to busy during 15 second wait period
      while (chrono::steady_clock::now() - startTime < duration) {
        isBusy = true;
      }

      // finished brewing!
      cafe->increase_numDrink();

      isBusy = false;
    }
  }
}

Barista::~Barista() {}