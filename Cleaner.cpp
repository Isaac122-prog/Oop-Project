#include "Cleaner.h"

#include <chrono>
#include <iostream>

#include "Employee.h"
#include "Table.h"
#include "Customer.h"

using namespace std;

// default constructor
Cleaner::Cleaner() : Employee() {
    body->setFillColor(sf::Color::Green);
    body->setPosition(400, 400);
}

void Cleaner::doTask(Customer* customer) {
  // the cleaner's task is to clean this specific customer's table
  if (customer->get_disgust() == 5) {
    std::cout << "Customer's table is clean!'"
              << std::endl;  // check if customer is disgusted
  } else if (!customer->get_isActive()) {
    std::cout << "Customer is not in cafe!"
              << std::endl;  // check customer is in cafe
  } else {
    // check cleaner is not busy
    if (isBusy == true) {
      cout << "cleaner is busy!" << endl;
    } else {
      // wait for 15 seconds -> FROM CHAT GPT
      auto startTime = chrono::steady_clock::now();
      auto duration = chrono::seconds(15);

      // set cleaner to busy during 15 second wait period
      while (chrono::steady_clock::now() - startTime < duration) {
        isBusy = true;
      }

      // setting the isClean property from table class to true
      customer->get_tableNo().set_isClean(true);
      // increase customer disgust
      customer->increase_disgust();

      isBusy = false;
    }
  }
}

Cleaner::~Cleaner(){}