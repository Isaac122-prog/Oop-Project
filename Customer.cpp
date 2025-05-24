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
  srand(time(0));

  hunger = std::rand() % 5;  // generate random integer from 0 to 5
  disgust = 5;
  thirst = std::rand() % 5;

  tableNo = this->tableNo;

  // to ensure customer score is not 15 on entry to the cafe
  if (hunger == 5 && thirst == 5) {
    thirst = 4;
  }
  happiness = hunger + thirst + disgust;

  customerAttributes = "hunger: " + std::to_string(hunger) + "/5\n";
  customerAttributes += "thirst: " + std::to_string(thirst) + "/5\n";
  customerAttributes += "disgust: " + std::to_string(disgust) + "/5\n";
  customerAttributes += "happiness: " + std::to_string(happiness) + "/15\n";

  isActive = false;

  startTime = std::time(nullptr);
  endTime = startTime + 120;

  disgustTime = std::time(nullptr);

  body = new sf::RectangleShape(sf::Vector2f(10, 40));
  body->setFillColor(sf::Color::Red);
  body->setOrigin(5, 20);

  // if (!font.loadFromFile("fonts/MyFont.ttf")) {
  //   std::cerr << "Failed to load font!" << std::endl;
  // }

  // customerInfo->setFont(font);
  // customerInfo->setFillColor(sf::Color::White);
  // customerInfo->setCharacterSize(20);
  // customerInfo->setString("TEST");
}

// getters and setters
void Customer::set_customerAttributes() {
  customerAttributes = "hunger:" + std::to_string(hunger) + "/5\n";
  customerAttributes += "thirst:" + std::to_string(thirst) + "/5\n";
  customerAttributes += "disgust:" + std::to_string(disgust) + "/5\n";
  customerAttributes += "happiness:" + std::to_string(happiness) + "/15\n";
}
std::string Customer::get_customerAttributes() const {
  return customerAttributes;
}

void Customer::set_isActive(bool state) { isActive = state; }
bool Customer::get_isActive() { return isActive; }

// I NEED TO REMEMBER WHAT'S GOING ON WITH TABLE NUMBER BC WTF
Table Customer::get_tableNo() { return tableNo; }
void Customer::set_tableNo(Table tableNo) { this->tableNo = tableNo; }

int Customer::get_happiness() { return happiness; }

std::time_t Customer::get_startTime() { return startTime; }
std::time_t Customer::get_endTime() { return endTime; }
std::time_t Customer::get_disgustTime() { return disgustTime; }

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
int Customer::get_disgust() { return disgust; }

// for debugging: print customer stats
void Customer::print_attributes() {
  std::cout << "hunger: " << hunger << ", thirst: " << thirst
            << ", disgust: " << disgust << std::endl;
}

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