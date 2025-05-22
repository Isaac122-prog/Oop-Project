#include "Game.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Cafe.h"

using namespace sf;

Game::Game(int size, std::string title, Cafe* cafe) {
  win = new ::sf::RenderWindow(sf::VideoMode(size, size), title);
  this->cafe = cafe;

  customerKey = 0;

  // setting up font
  if (!font.loadFromFile("fonts/MyFont.ttf")) {
    std::cerr << "Failed to load font!" << std::endl;
  }

  waiterTimer.setFont(font);
  waiterTimer.setCharacterSize(15);
  waiterTimer.setFillColor(sf::Color::White);
  waiterTimer.setString("waiter");
  waiterTimer.setPosition(300, 400);

  cleanerTimer.setFont(font);
  cleanerTimer.setCharacterSize(15);
  cleanerTimer.setFillColor(sf::Color::White);
  cleanerTimer.setString("cleaner");
  cleanerTimer.setPosition(400, 400);

  baristaTimer.setFont(font);
  baristaTimer.setCharacterSize(15);
  baristaTimer.setFillColor(sf::Color::White);
  baristaTimer.setString("barista");
  baristaTimer.setPosition(100, 400);

  chefTimer.setFont(font);
  chefTimer.setCharacterSize(15);
  chefTimer.setFillColor(sf::Color::White);
  chefTimer.setString("chef");
  chefTimer.setPosition(200, 400);
}

void Game::drawFrame() {
  for (int i = 0; i < cafe->get_maxCustomers(); i++) {
    cafe->get_table(i).draw(win);
  }
  for (int j = 0; j < cafe->get_maxCustomers(); j++) {
    cafe->get_customer(j).draw(win);
  }

  if (cafe->get_numFood() > 0) {
    cafe->get_chef().get_food().draw(win);
  }

  if (cafe->get_numDrink() > 0) {
    cafe->get_barista().get_drink().draw(win);
  }

  if (cafe->get_barista().get_waitTime() <= std::time(nullptr) - 10 &&
      cafe->get_barista().get_wasCalled()) {
    cafe->increase_numDrink();
    baristaTimer.setString("barista");
    std::cout << "number of drinks: " << cafe->get_numDrink() << std::endl;
  } else if (cafe->get_barista().get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_barista().get_wasCalled()) {
              baristaTimer.setString("barista\n" + std::to_string(10-(std::time(nullptr) - cafe->get_baristaPointer()->get_waitTime())));
  }

  if (cafe->get_chef().get_waitTime() <= std::time(nullptr) - 10 &&
      cafe->get_chef().get_wasCalled()) {
    cafe->increase_numFood();
    chefTimer.setString("chef");
    std::cout << "servings of food: " << cafe->get_numFood() << std::endl;
  } else if (cafe->get_chef().get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_chef().get_wasCalled()) {
              chefTimer.setString("chef\n" + std::to_string(10-(std::time(nullptr) - cafe->get_chefPointer()->get_waitTime())));
  }

  // NOTE: IF PLAYER PRESSES ANOTHER NUMBER, THIS WILL ASSIGN TO THE WRONG
  // CUSTOMER
  if (cafe->get_cleaner().get_waitTime() <= std::time(nullptr) - 10 &&
      cafe->get_cleaner().get_wasCalled()) {
    cafe->get_cleanerPointer()->set_wasCalled(false);
    cafe->get_customerPointer(customerKey)->get_tableNo().set_isClean(true);
    cafe->get_customerPointer(customerKey)->increase_disgust();
    cleanerTimer.setString("cleaner");
    // std::cout << "function was happily called!" << std::endl;
  } else if (cafe->get_cleaner().get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_cleaner().get_wasCalled()) {
              cleanerTimer.setString("cleaner\n" + std::to_string(10-(std::time(nullptr) - cafe->get_cleanerPointer()->get_waitTime())));
  }

  // NOTE: IF PLAYER PRESSES ANOTHER NUMBER, THIS WILL ASSIGN TO THE WRONG
  // CUSTOMER
  if (cafe->get_waiter().get_waitTime() <= std::time(nullptr) - 5 &&
      cafe->get_waiter().get_wasCalled()) {
    cafe->get_waiterPointer()->set_wasCalled(false);

    if (cafe->get_customerPointer(customerKey)->get_hunger() < 5) {
      // food is served!
      cafe->decrease_numFood();
      // customer.get_Food().set_isActive(true);
      // increase customer hunger
      cafe->get_customerPointer(customerKey)->increase_hunger();
    }
    if (cafe->get_customerPointer(customerKey)->get_thirst() < 5) {
      // drink is served!
      cafe->decrease_numDrink();
      // customer.get_drink().set_isActive(true);
      // increase customer thirst
      cafe->get_customerPointer(customerKey)->increase_thirst();
    }
    std::cout << "function was happily called!" << std::endl;
    std::cout << "number of drinks: " << cafe->get_numDrink() << std::endl;
    std::cout << "servings of food: " << cafe->get_numFood() << std::endl;
  } else if (cafe->get_waiter().get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_waiter().get_wasCalled()) {
              waiterTimer.setString("waiter\n" + std::to_string(10-(std::time(nullptr) - cafe->get_waiterPointer()->get_waitTime())));
  }


  for (int k = 0; k < cafe->get_maxCustomers(); k++) {
    // THIS SECTION IS TAKEN FROM CHAT GPT
    const Customer& customer = cafe->get_customer(k);  // get a single customer

    sf::Text label;
    label.setFont(font);
    label.setCharacterSize(16);
    label.setString(std::to_string(k+1) + "\n" + customer.get_customerAttributes());
    label.setPosition(customer.get_x(), customer.get_y() - 20);
    label.setFillColor(sf::Color::White);
    if (cafe->get_customer(k).get_isActive()) {
      win->draw(label);
    }
  }

  cafe->get_cleaner().draw(win);
  cafe->get_chef().draw(win);
  cafe->get_barista().draw(win);
  cafe->get_waiter().draw(win);

  win->draw(baristaTimer);
  win->draw(chefTimer);
  win->draw(waiterTimer);
  win->draw(cleanerTimer);
}

void Game::keyBindings(sf::Event e) {
  if (e.type == sf::Event::KeyPressed) {
    switch (e.key.code) {
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

      case Keyboard::Q:
        if (cafe->get_activeCustomer() >= 0) {
          cafe->get_baristaPointer()->doTask(
              cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
          // cafe->get_customer(cafe->get_activeCustomer()).print_attributes();
          // std::cout << "number of drinks: " << cafe->get_numDrink()
          //           << std::endl;
          cafe->set_activeCustomer(-1);
        }
        break;

      case Keyboard::W:
        if (cafe->get_activeCustomer() >= 0) {
          cafe->get_chefPointer()->doTask(
              cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
          // cafe->get_customer(cafe->get_activeCustomer()).print_attributes();
          // std::cout << "servings of food: " << cafe->get_numFood() <<
          // std::endl;
          cafe->set_activeCustomer(-1);
        }
        break;

      case Keyboard::E:
        if (cafe->get_activeCustomer() >= 0) {
          cafe->get_waiterPointer()->doTask(
              cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
          // cafe->get_customer(cafe->get_activeCustomer()).print_attributes();
          cafe->set_activeCustomer(-1);
        }
        break;

      case Keyboard::R:
        if (cafe->get_activeCustomer() >= 0) {
          cafe->get_cleanerPointer()->doTask(
              cafe->get_customerPointer(cafe->get_activeCustomer()));
          // cafe->get_customer(cafe->get_activeCustomer()).print_attributes();
          cafe->set_activeCustomer(-1);
        }
        break;

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
      if (actionClock.getElapsedTime().asSeconds() >=
          1.0f) {  // should this be in Game::run or Game::drawFrame
        cafe->newCustomer();
        cafe->customerLeaves();
        actionClock.restart();
        for (int i = 0; i < cafe->get_maxCustomers(); i++) {
          if (cafe->get_customer(i).get_isActive() &&
              cafe->get_customer(i).get_disgustTime() <=
                  std::time(nullptr) - 10) {
            cafe->get_customerPointer(i)->decrease_disgust(
                cafe->get_customerPointer(i)->get_tableNo());
          }
        }
      }
    }

    win->clear();
    drawFrame();
    win->display();
  }
}
