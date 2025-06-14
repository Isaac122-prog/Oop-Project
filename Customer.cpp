#include "Customer.h"

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <random>

#include "Table.h"

// default constructor
Customer::Customer() {
  hunger = 0;
  thirst = 0;
  disgust = 0;
  happiness = 0;
  isActive = false;
  startTime = 0;
}

// constructor
Customer::Customer(Table tableNo, int customerNo) {
  hunger = std::rand() % 5;  // generate random integer from 0 to 5
  disgust = 5;
  thirst = std::rand() % 5;

  this->tableNo = tableNo;
  this->customerNo = customerNo;

  // to ensure customer score is not 15 on entry to the cafe
  if (hunger == 5 && thirst == 5) {
    thirst = 4;
  }
  happiness = hunger + thirst + disgust;

  // set customerAttributes for label
  customerAttributes  = std::string("thirst:") + std::to_string(thirst) + "/5\n";
  customerAttributes += std::string("hunger:") + std::to_string(hunger) + "/5\n";
  customerAttributes += std::string("disgust:") + std::to_string(disgust) + "/5\n";
  customerAttributes += std::string("happiness:") + std::to_string(happiness) + "/15\n";

  // set to inactive
  isActive = false; 

  // set start/end times for timers
  startTime = std::time(nullptr);
  endTime = startTime + 120;

  disgustTime = std::time(nullptr);

  // set graphics
  body = new sf::RectangleShape(sf::Vector2f(10, 40));
  body->setFillColor(sf::Color::Red);
  body->setOrigin(5, 20);
}

// getters and setters
void Customer::set_customerAttributes() {
  customerAttributes.clear();
  customerAttributes  = std::string("thirst:") + std::to_string(thirst) + "/5\n";
  customerAttributes += std::string("hunger:") + std::to_string(hunger) + "/5\n";
  customerAttributes += std::string("disgust:") + std::to_string(disgust) + "/5\n";
  customerAttributes += std::string("happiness:") + std::to_string(happiness) + "/15\n";
}
std::string Customer::get_customerAttributes() const {
  return customerAttributes;
}

void Customer::set_isActive(bool state) { isActive = state; }
bool Customer::get_isActive() { return isActive; }

Table Customer::get_tableNo() { return tableNo; }
void Customer::set_tableNo(Table tableNo) { this->tableNo = tableNo; }

int Customer::get_customerNo() { return customerNo; }

int Customer::get_happiness() {
  happiness = hunger + thirst + disgust;
  return happiness;
}
void Customer::set_happiness(int happiness) { this->happiness = happiness; }

std::time_t Customer::get_startTime() { return startTime; }
std::time_t Customer::get_endTime() { return endTime; }
void Customer::set_startTime() {
  startTime = std::time(nullptr);
  endTime = startTime + 120;
}
std::time_t Customer::get_disgustTime() { return disgustTime; }
void Customer::set_disgustTime() { disgustTime = std::time(nullptr); }

// getters and setters: hunger
void Customer::increase_hunger() {
  hunger += 3;
  if (hunger > 5) {
    hunger = 5;
  }
  happiness = hunger + thirst + disgust;
  set_customerAttributes();
}
void Customer::decrease_hunger() {
  hunger--;
  if (hunger < 0) {
    hunger = 0;
  }
  happiness = hunger + thirst + disgust;
  set_customerAttributes();
}
void Customer::set_hunger(int hunger) {
  this->hunger = hunger;
  happiness = hunger + thirst + disgust;
  set_customerAttributes();
}
int Customer::get_hunger() { return hunger; }

// getters and setters: thirst
void Customer::increase_thirst() {
  thirst += 3;
  if (thirst > 5) {
    thirst = 5;
  }
  happiness = hunger + thirst + disgust;
  set_customerAttributes();
}
void Customer::decrease_thirst() {
  thirst--;
  if (thirst < 0) {
    thirst = 0;
  }
  happiness = hunger + thirst + disgust;
  set_customerAttributes();
}
void Customer::set_thirst(int thirst) {
  this->thirst = thirst;
  happiness = hunger + thirst + disgust;
  set_customerAttributes();
}
int Customer::get_thirst() { return thirst; }

// getters and setters: disgust
void Customer::increase_disgust() {
  disgust = 5;
  happiness = hunger + thirst + disgust;
  set_customerAttributes();
}
void Customer::decrease_disgust(Table table) {
  disgust--;
  if (disgust < 0) {
    disgust = 0;
  }
  if (disgust < 5) {
    table.set_isClean(false);
  }
  happiness = hunger + thirst + disgust;
  set_customerAttributes();
  disgustTime = std::time(nullptr);
}
void Customer::set_disgust(int disgust) {
  this->disgust = disgust;
  happiness = hunger + thirst + disgust;
  set_customerAttributes();
}
int Customer::get_disgust() { return disgust; }

// draw customer
void Customer::draw(sf::RenderWindow* win) {
  if (isActive) {
    win->draw(*body);
  }
}

// graphics getters and setters
sf::RectangleShape* Customer::get_body() { return body; }
int Customer::get_x() const { return body->getPosition().x; }
int Customer::get_y() const { return body->getPosition().y; }
void Customer::set_position(sf::Vector2f position) {
  body->setPosition(position);
}

// destructor
Customer::~Customer() {}