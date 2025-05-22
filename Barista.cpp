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
  body->setFillColor(sf::Color::Magenta);
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
    if (waitTime <= std::time(nullptr)-10 ) {
      isBusy = false;
    }
    // check barista is not busy
    if (isBusy == true) {
      cout << "barista is busy!" << endl;
    } else {
      std::cout << "brewing..." << std::endl;
      isBusy = true;
      waitTime = std::time(nullptr);
      wasCalled = true;
    }
  }
}

Barista::~Barista() {}