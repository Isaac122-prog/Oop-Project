#include "Customer.h"

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <random>

#include "Table.h"

Customer::Customer() {
  hunger = 0;
  thirst = 0;
  disgust = 0;
  happiness = 0;
  isActive = false;
  startTime = 0;
}

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

// sf::Font Customer::font;

sf::RectangleShape* Customer::get_body() { return body; }

// sf::Text* Customer::get_customerInfo() { return customerInfo; }

void Customer::set_customerAttributes() {
  customerAttributes = "hunger: " + std::to_string(hunger) + "/5\n";
  customerAttributes += "thirst: " + std::to_string(thirst) + "/5\n";
  customerAttributes += "disgust: " + std::to_string(disgust) + "/5\n";
  customerAttributes += "happiness: " + std::to_string(happiness) + "/15\n";
  // std::cout << text << std::endl;
}

std::string Customer::get_customerAttributes() const {
  return customerAttributes;
}

void Customer::draw(sf::RenderWindow* win) {
  if (isActive) {
    win->draw(*body);
  }
}

int Customer::get_x() const { return body->getPosition().x; }
int Customer::get_y() const { return body->getPosition().y; }
void Customer::set_position(sf::Vector2f position) {
  body->setPosition(position);
}

void Customer::set_isActive(bool state) {
  isActive = state;
}

bool Customer::get_isActive() { return isActive; }

void Customer::increase_hunger() {
  // hunger +3
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

void Customer::increase_thirst() {
  // thirst +3
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

void Customer::increase_disgust() {
  // disgust is maxed out to 5
  disgust = 5;
  happiness = hunger + thirst + disgust;
  set_customerAttributes();
}

void Customer::decrease_disgust(Table table) {
  sf::Clock disgustClock;
  if (disgustClock.getElapsedTime().asSeconds() >= 10.0f) {
    disgust--;
    if (disgust < 0) {
      disgust = 0;
    }
    if (disgust < 5) {
      table.set_isClean(false);
    }
    happiness = hunger + thirst + disgust;
    set_customerAttributes();
    disgustClock.restart();
  }
}

int Customer::get_disgust() { return disgust; }

int Customer::get_happiness() { return happiness; }

void Customer::print_attributes() {  // TO BE DELETED
  std::cout << "hunger: " << hunger << ", thirst: " << thirst
            << ", disgust: " << disgust << std::endl;
}

// I NEED TO REMEMBER WHAT'S GOING ON WITH TABLE NUMBER BC WTF
Table Customer::get_tableNo() { return tableNo; }

void Customer::set_tableNo(Table tableNo) { this->tableNo = tableNo; }

// void Customer::draw_text(sf::RenderWindow* win){
//   win->draw(customerInfo);
// }

// Drink Customer::get_drink(){ return drinkServing;}

// Food Customer::get_food(){ return foodServing;}

std::time_t Customer::get_startTime() { return startTime; }

std::time_t Customer::get_endTime() { return endTime; }

Customer::~Customer(){}