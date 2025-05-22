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
  if (!customer->get_isActive()) {
    std::cout << "Customer is not in cafe!"
              << std::endl;  // check customer is in cafe
  } else if (customer->get_disgust() == 5) {
    std::cout << "Customer's table is clean!"
              << std::endl;  // check if customer is disgusted
  } else {
    if (waitTime <= std::time(nullptr)-10 ) {
      isBusy = false;
    }
    // check cleaner is not busy
    if (isBusy == true) {
      cout << "cleaner is busy!" << endl;
    } else {
            // setting the isClean property from table class to true
      
      std::cout << "cleaning..." << std::endl;
      isBusy = true;
      waitTime = std::time(nullptr);
      wasCalled = true;
    
    }
  }
}

Cleaner::~Cleaner(){}