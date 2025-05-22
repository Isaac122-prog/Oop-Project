#include "Barista.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Customer.h"
#include "Employee.h"
#include "KitchenStaff.h"
#include "Cafe.h"
#include "Consumable.h"

using namespace std;

Barista::Barista() : KitchenStaff() {
  body = new sf::RectangleShape(sf::Vector2f(10, 40));
  body->setFillColor(sf::Color::Magenta);
  body->setOrigin(10, 10);
  body->setPosition(100, 400);

  drink.get_body()->setPosition(100,400);
}

void Barista::doTask(Customer* customer, Cafe* cafe) {
  // the barista's task is to make the drinks
  if (!customer->get_isActive()){
    std::cout << "Customer is not in cafe!" << std:: endl;
  } else if (customer->get_thirst() == 5) {
    std::cout << "Customer is not thirsty!" << std::endl;
  } else {
    if (busyTimer.getElapsedTime().asSeconds() >= 15) {
      isBusy = false;
    }
    // check barista is not busy
    if (isBusy == true) {
      cout << "barista is busy!" << endl;
    } else {
      std::cout << "brewing..." << std::endl;
      isBusy = true;
      busyTimer.restart();
      // finished brewing!
      cafe->increase_numDrink();
    }
  }
}

Barista::~Barista() {}