#include "Game.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Cafe.h"

using namespace sf;

Game::Game(std::string title, Cafe* cafe) {
  this->cafe = cafe;
  customerKey = 0;

  win = new ::sf::RenderWindow(sf::VideoMode(700, 700),
                               title);  // generates window

  // setting up font
  if (!font.loadFromFile("fonts/MyFont.ttf")) {
    std::cerr << "Failed to load font!" << std::endl;
  }

  // setting up waiterTimer
  waiterTimer.setFont(font);
  waiterTimer.setCharacterSize(15);
  waiterTimer.setFillColor(sf::Color::White);
  waiterTimer.setString("waiter");
  sf::FloatRect bounds = waiterTimer.getLocalBounds();
  waiterTimer.setOrigin(bounds.left + bounds.width / 2,
                        bounds.top + bounds.height / 2);

  waiterTimer.setPosition(360, 440);

  // setting up cleanerTimer
  cleanerTimer.setFont(font);
  cleanerTimer.setCharacterSize(15);
  cleanerTimer.setFillColor(sf::Color::White);
  cleanerTimer.setString("cleaner");
  bounds = cleanerTimer.getLocalBounds();
  cleanerTimer.setOrigin(bounds.left + bounds.width / 2,
                         bounds.top + bounds.height / 2);
  cleanerTimer.setPosition(480, 440);

  // setting up baristaTimer
  baristaTimer.setFont(font);
  baristaTimer.setCharacterSize(15);
  baristaTimer.setFillColor(sf::Color::White);
  baristaTimer.setString("barista");
  bounds = baristaTimer.getLocalBounds();
  baristaTimer.setOrigin(bounds.left + bounds.width / 2,
                         bounds.top + bounds.height / 2);
  baristaTimer.setPosition(120, 440);

  // setting up chefTimer
  chefTimer.setFont(font);
  chefTimer.setCharacterSize(15);
  chefTimer.setFillColor(sf::Color::White);
  chefTimer.setString("chef");
  bounds = chefTimer.getLocalBounds();
  chefTimer.setOrigin(bounds.left + bounds.width / 2,
                      bounds.top + bounds.height / 2);
  chefTimer.setPosition(240, 440);
}

void Game::drawFrame() {
  for (int i = 0; i < cafe->get_maxCustomers(); i++) {
    cafe->get_table(i).draw(win);  // draw tables
  }
  for (int j = 0; j < cafe->get_maxCustomers(); j++) {
    cafe->get_customer(j).draw(win);  // draw active customers
  }

  if (cafe->get_numFood() > 0) {
    cafe->get_chef().get_food().draw(win);  // draw food if available
  }

  if (cafe->get_numDrink() > 0) {
    cafe->get_barista().get_drink().draw(win);  // draw drink if available
  }

  baristaAction();
  chefAction();
  waiterAction();
  cleanerAction();

  for (int k = 0; k < cafe->get_maxCustomers(); k++) {
    // THIS SECTION IS TAKEN FROM CHAT GPT
    const Customer& customer = cafe->get_customer(k);  // get a single customer

    sf::Text label;
    label.setFont(font);
    label.setCharacterSize(16);
    label.setString(std::to_string(k + 1) + "\n" +
                    customer.get_customerAttributes());
    sf::FloatRect bounds = waiterTimer.getLocalBounds();
    label.setOrigin(bounds.left + bounds.width / 2,
                    bounds.top + bounds.height / 2);
    label.setPosition(customer.get_x(), customer.get_y() + 20);
    label.setFillColor(sf::Color::White);
    if (cafe->get_customer(k).get_isActive()) {
      win->draw(label);
    }
  }

  // draw objects
  // cafe->get_cleaner().draw(win);
  // cafe->get_chef().draw(win);
  // cafe->get_barista().draw(win);
  // cafe->get_waiter().draw(win);

  // draw employees
  for (int l = 0; l < cafe->get_maxEmployees(); l++) {
    cafe->get_employee(l)->draw(win);
  }

  // draw labels/timers
  win->draw(baristaTimer);
  win->draw(chefTimer);
  win->draw(waiterTimer);
  win->draw(cleanerTimer);
}

void Game::keyBindings(sf::Event e) {
  if (e.type == sf::Event::KeyPressed) {
    switch (e.key.code) {
      // numbers set the customer
      case Keyboard::Num1:
        cafe->set_activeCustomer(0);
        customerKey = 0;
        break;
      case Keyboard::Num2:
        cafe->set_activeCustomer(1);
        customerKey = 1;
        break;
      case Keyboard::Num3:
        cafe->set_activeCustomer(2);
        customerKey = 2;
        break;
      case Keyboard::Num4:
        cafe->set_activeCustomer(3);
        customerKey = 3;
        break;
      case Keyboard::Num5:
        cafe->set_activeCustomer(4);
        customerKey = 4;
        break;
      case Keyboard::Num6:
        cafe->set_activeCustomer(5);
        customerKey = 5;
        break;
      case Keyboard::Num7:
        cafe->set_activeCustomer(6);
        customerKey = 6;
        break;
      case Keyboard::Num8:
        cafe->set_activeCustomer(7);
        customerKey = 7;
        break;
      case Keyboard::Num9:
        cafe->set_activeCustomer(8);
        customerKey = 8;
        break;
      case Keyboard::Num0:
        cafe->set_activeCustomer(9);
        customerKey = 9;
        break;
      case Keyboard::Escape:
        cafe->set_activeCustomer(-1);
        break;

      //  Q W E R  set barista, chef, waiter, cleaner actions
      case Keyboard::Q:
        if (cafe->get_activeCustomer() >= 0) {
          // cafe->get_baristaPointer()->doTask(
          // cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
          cafe->get_employee(0)->doTask(
              cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
          cafe->set_activeCustomer(-1);
        }
        break;

      case Keyboard::W:
        if (cafe->get_activeCustomer() >= 0) {
          // cafe->get_chefPointer()->doTask(
          //     cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
          cafe->get_employee(1)->doTask(
              cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
          cafe->set_activeCustomer(-1);
        }
        break;

      case Keyboard::E:
        if (cafe->get_activeCustomer() >= 0) {
          // cafe->get_waiterPointer()->doTask(
          //     cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
          cafe->get_employee(2)->doTask(
              cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
          cafe->set_activeCustomer(-1);
        }
        break;

      case Keyboard::R:
        if (cafe->get_activeCustomer() >= 0) {
          // cafe->get_cleanerPointer()->doTask(
          //     cafe->get_customerPointer(cafe->get_activeCustomer()));
          cafe->get_employee(3)->doTask(
              cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
          cafe->set_activeCustomer(-1);
        }
        break;

      case Keyboard::P:
        cafe->viewPerformance();

      default:
        break;
    }
  }
}

void Game::run() {
  sf::Clock actionClock;  // clock for incrementing how often things are
                          // checked in while loops

  while (win->isOpen()) {
    sf::Event e;
    while (win->pollEvent(e)) {
      if (e.type == Event::Closed) {
        win->close();
      }
      keyBindings(e);
    }

    // if the cafe timer is below the game duration
    if (cafe->startTime.getElapsedTime().asSeconds() <
        cafe->get_gameDuration()) {
      // every 1 second
      if (actionClock.getElapsedTime().asSeconds() >= 1.0f) {
        cafe->newCustomer();
        cafe->customerLeaves();
        actionClock.restart();
        // decreases active customer's disgust based on their disgust timer
        for (int i = 0; i < cafe->get_maxCustomers(); i++) {
          if (cafe->get_customer(i).get_isActive() &&
              cafe->get_customer(i).get_disgustTime() <=
                  std::time(nullptr) - 10) {
            cafe->get_customerPointer(i)->decrease_disgust(
                cafe->get_table(i));
          }
        }
      }
    }

    win->clear();
    drawFrame();
    win->display();
  }
}

// generate drink if barista finished brewing, otherwise displays timer
void Game::baristaAction() {
  if (cafe->get_employee(0)->get_waitTime() <= std::time(nullptr) - 10 &&
      cafe->get_employee(0)->get_wasCalled()) {
    cafe->increase_numDrink();
    baristaTimer.setString("barista");
    cafe->get_employee(0)->set_wasCalled(false);
    std::cout << "number of drinks: " << cafe->get_numDrink() << std::endl;
  } else if (cafe->get_employee(0)->get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_employee(0)->get_wasCalled()) {
    baristaTimer.setString(
        "barista\n" +
        std::to_string(10 - (std::time(nullptr) -
                             cafe->get_employee(0)->get_waitTime())));
  }
}

// generate food is chef finished cooking, otherwise displays timer
void Game::chefAction() {
  if (cafe->get_employee(1)->get_waitTime() <= std::time(nullptr) - 10 &&
      cafe->get_employee(1)->get_wasCalled()) {
    cafe->increase_numFood();
    cafe->get_employee(1)->set_wasCalled(false);
    chefTimer.setString("chef");
    std::cout << "servings of food: " << cafe->get_numFood() << std::endl;
  } else if (cafe->get_employee(1)->get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_employee(1)->get_wasCalled()) {
    chefTimer.setString(
        "chef\n" +
        std::to_string(10 - (std::time(nullptr) -
                             cafe->get_employee(1)->get_waitTime())));
  }
}

//  NOTE: IF PLAYER PRESSES ANOTHER NUMBER, THIS WILL ASSIGN TO THE WRONG
// CUSTOMER
// serves food if waiter finished serving, otherwise displays timer
void Game::waiterAction() {
  if (cafe->get_employee(2)->get_waitTime() <= std::time(nullptr) - 10 &&
      cafe->get_employee(2)->get_wasCalled()) {
    cafe->get_employee(2)->set_wasCalled(false);
    waiterTimer.setString("waiter");
    if (cafe->get_customerPointer(customerKey)->get_hunger() < 5) {
      cafe->decrease_numFood();  // food is served!
      cafe->get_customerPointer(customerKey)
          ->increase_hunger();  // increase customer hunger
      std::cout << "servings of food: " << cafe->get_numFood() << std::endl;
    }
    if (cafe->get_customerPointer(customerKey)->get_thirst() < 5) {
      cafe->decrease_numDrink();  // drink is served!
      cafe->get_customerPointer(customerKey)
          ->increase_thirst();  // increase customer thirst
      std::cout << "number of drinks: " << cafe->get_numDrink() << std::endl;
    }
    // std::cout << "function was happily called!" << std::endl;
  } else if (cafe->get_employee(2)->get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_employee(2)->get_wasCalled()) {
    waiterTimer.setString(
        "waiter\n" +
        std::to_string(10 - (std::time(nullptr) -
                             cafe->get_employee(2)->get_waitTime())));
  }
}

// NOTE: IF PLAYER PRESSES ANOTHER NUMBER, THIS WILL ASSIGN TO THE WRONG
// CUSTOMER
// sets table to clean if cleaner finished cleaning, otherwise displays timer
void Game::cleanerAction() {
  if (cafe->get_employee(3)->get_waitTime() <= std::time(nullptr) - 10 &&
      cafe->get_employee(3)->get_wasCalled()) {
    cafe->get_cleanerPointer()->set_wasCalled(false);
    cafe->get_customerPointer(customerKey)->get_tableNo().set_isClean(true);
    cafe->get_customerPointer(customerKey)->increase_disgust();
    cleanerTimer.setString("cleaner");
  } else if (cafe->get_employee(3)->get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_employee(3)->get_wasCalled()) {
    cleanerTimer.setString(
        "cleaner\n" +
        std::to_string(10 - (std::time(nullptr) -
                             cafe->get_employee(3)->get_waitTime())));
  }
}

// destructor
Game::~Game() {}
