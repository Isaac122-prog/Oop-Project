#include "Customer.h"

#include <ctime>
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

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
  isActive = false;

  startTime = std::time(nullptr);
  endTime = startTime + 120;

  body = new sf::RectangleShape(sf::Vector2f(10, 40));
  body->setFillColor(sf::Color::Red);
  body->setOrigin(5, 20);
  body->setPosition(customerNo * 30 + 100, 30);
}

void Customer::draw(sf::RenderWindow* win) {
  if (isActive) {
    win->draw(*body);
  } 
}

void Customer::set_isActive(bool state) { isActive = state; }

bool Customer::get_isActive() { return isActive; }

void Customer::increase_hunger() {
  // hunger +3
  hunger += 3;
  if (hunger > 5) {
    hunger = 5;
  }
  happiness = hunger + thirst + disgust;
}

void Customer::decrease_hunger() {
  hunger--;
  if (hunger < 0) {
    hunger = 0;
  }
  happiness = hunger + thirst + disgust;
}

int Customer::get_hunger() { return hunger; }

void Customer::increase_thirst() {
  // thirst +3
  thirst += 3;
  if (thirst > 5) {
    thirst = 5;
  }
  happiness = hunger + thirst + disgust;
}

void Customer::decrease_thirst() {
  thirst--;
  if (thirst < 0) {
    thirst = 0;
  }
  happiness = hunger + thirst + disgust;
}

int Customer::get_thirst() { return thirst; }

void Customer::increase_disgust() {
  // disgust is maxed out to 5
  disgust = 5;
  happiness = hunger + thirst + disgust;
}

void Customer::decrease_disgust(Table table) {
  disgust--;
  if (disgust < 0) {
    disgust = 0;
  }
  if (disgust < 5){
    table.set_isClean(false);
  }
  happiness = hunger + thirst + disgust;
}

int Customer::get_disgust() { return disgust; }

int Customer::get_happiness() { return happiness; }

void Customer::print_attributes(){
  std::cout << "hunger: " << hunger << ", thirst: " << thirst << ", disgust: " << disgust << std::endl;
}

// I NEED TO REMEMBER WHAT'S GOING ON WITH TABLE NUMBER BC WTF
Table Customer::get_tableNo() { return tableNo; }

void Customer::set_tableNo(Table tableNo) { this->tableNo = tableNo; }

// Drink Customer::get_drink(){ return drinkServing;}

// Food Customer::get_food(){ return foodServing;}

std::time_t Customer::get_startTime() { return startTime; }

std::time_t Customer::get_endTime() { return endTime; }