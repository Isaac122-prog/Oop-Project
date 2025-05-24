#include "Cleaner.h"

#include <chrono>
#include <iostream>

#include "Customer.h"
#include "Employee.h"
#include "Table.h"

using namespace std;

// constructor
Cleaner::Cleaner() : Employee() {
  body->setFillColor(sf::Color::Green);
  body->setPosition(480, 400);
  label = "cleaner";
}

// doTask: sets the cleaner to busy and sets their timer for cleaning the
// customer's table
void Cleaner::doTask(Customer* customer, Cafe* cafe) {
  if (!customer->get_isActive()) {
    std::cout << "Customer is not in cafe!" << std::endl;
  } else if (customer->get_disgust() == 5) {
    std::cout << "Customer's table is clean!" << std::endl;
  } else {
    // check if cleaner's busy time has expired
    if (waitTime <= std::time(nullptr) - 10) {
      isBusy = false;
    }
    if (isBusy == true) {
      cout << "cleaner is busy!" << endl;
    } else {
      // being cleaning process
      std::cout << "cleaning..." << std::endl;
      isBusy = true;
      waitTime = std::time(nullptr);
      wasCalled = true;
      this-> customerNo = customer->get_customerNo();
    }
  }
}

// destructor
Cleaner::~Cleaner() {}