#include "Barista.h"

#include <chrono>
#include <iostream>

#include "Customer.h"
#include "Employee.h"
#include "KitchenStaff.h"

using namespace std;

Barista::Barista() : KitchenStaff() {
  body = new sf::RectangleShape(sf::Vector2f(10, 40));
  body->setFillColor(sf::Color::Magenta);
  body->setOrigin(10, 10);
  body->setPosition(100, 400);
}

void Barista::doTask(Customer* customerNo) {
  // the barista's task is to make the drinks

  // check barista is not busy
  if (isBusy = true) {
    cout << "chef is busy!" << endl;
  } else {
    // wait for 15 seconds -> FROM CHAT GPT
    auto startTime = chrono::steady_clock::now();
    auto duration = chrono::seconds(15);

    // set barista to busy during 15 second wait period
    while (chrono::steady_clock::now() - startTime < duration) {
      isBusy = true;
    }

    // finished brewing!
    numDrink++;

    isBusy = false;
  }
}

Barista::~Barista() {}