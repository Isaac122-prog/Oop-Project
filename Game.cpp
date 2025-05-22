#include "Game.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Cafe.h"

using namespace sf;

Game::Game(int size, std::string title, Cafe* cafe) {
  win = new ::sf::RenderWindow(sf::VideoMode(size, size), title);
  this->cafe = cafe;

  // setting up font
  if (!font.loadFromFile("fonts/MyFont.ttf")) {
    std::cerr << "Failed to load font!" << std::endl;
  }
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

  // if (cafe->get_waiter().get_isBusy()) {
  //   std::string msg;
  //   msg = std::to_string(cafe->get_waiter().get_busyTimer());
  //   cafe->get_waiter().get_info()->setString(
  //       msg);  // display the waiter's timer when they are busy
  // } else {
  //   cafe->get_waiter().get_info()->setString("");
  // }

  for (int k = 0; k < cafe->get_maxCustomers(); k++) {
    if (cafe->get_customer(k).get_isActive() == true) {
      cafe->get_customer(k).get_customerInfo().setPosition(
          cafe->get_customer(k).get_x(), cafe->get_customer(k).get_y());
          cafe->get_customerPointer(k)->draw_text(win);
    }
  }

  cafe->get_cleaner().draw(win);
  cafe->get_chef().draw(win);
  cafe->get_barista().draw(win);
  cafe->get_waiter().draw(win);
}

void Game::keyBindings(sf::Event e) {
  if (e.type == sf::Event::KeyPressed) {
    switch (e.key.code) {
      case Keyboard::Num1:
        cafe->set_activeCustomer(0);
        break;
      case Keyboard::Num2:
        cafe->set_activeCustomer(1);
        break;
      case Keyboard::Num3:
        cafe->set_activeCustomer(2);
        break;
      case Keyboard::Num4:
        cafe->set_activeCustomer(3);
        break;
      case Keyboard::Num5:
        cafe->set_activeCustomer(4);
        break;
      case Keyboard::Num6:
        cafe->set_activeCustomer(5);
        break;
      case Keyboard::Num7:
        cafe->set_activeCustomer(6);
        break;
      case Keyboard::Num8:
        cafe->set_activeCustomer(7);
        break;
      case Keyboard::Num9:
        cafe->set_activeCustomer(8);
        break;
      case Keyboard::Num0:
        cafe->set_activeCustomer(9);
        break;
      case Keyboard::Escape:
        cafe->set_activeCustomer(-1);
        break;

      case Keyboard::Q:
        if (cafe->get_activeCustomer() >= 0) {
          cafe->get_barista().doTask(
              cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
          cafe->get_customer(cafe->get_activeCustomer()).print_attributes();
          std::cout << "number of drinks: " << cafe->get_numDrink()
                    << std::endl;
          cafe->set_activeCustomer(-1);
        }
        break;

      case Keyboard::W:
        if (cafe->get_activeCustomer() >= 0) {
          cafe->get_chef().doTask(
              cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
          cafe->get_customer(cafe->get_activeCustomer()).print_attributes();
          std::cout << "servings of food: " << cafe->get_numFood() << std::endl;
          cafe->set_activeCustomer(-1);
        }
        break;

      case Keyboard::E:
        if (cafe->get_activeCustomer() >= 0) {
          cafe->get_waiter().doTask(
              cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
          cafe->get_customer(cafe->get_activeCustomer()).print_attributes();
          std::cout << "number of drinks: " << cafe->get_numDrink()
                    << std::endl;
          cafe->set_activeCustomer(-1);
        }
        break;

      case Keyboard::R:
        if (cafe->get_activeCustomer() >= 0) {
          cafe->get_cleaner().doTask(
              cafe->get_customerPointer(cafe->get_activeCustomer()));
          cafe->get_customer(cafe->get_activeCustomer()).print_attributes();
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
        // for (int i=0; i<cafe->get_maxCustomers(); i++){
        //   if(cafe->get_customer(i).get_isActive()){
        //     cafe->get_customerPointer(i)->decrease_disgust(cafe->get_customerPointer(i)->get_tableNo());
        //   }
        // }
      }
    }

    win->clear();
    drawFrame();
    // for (int k = 0; k < cafe->get_maxCustomers(); k++) {
    //   if (cafe->get_customer(k).get_isActive() == true) {
    //     win->draw(cafe->get_customer(k).get_customerInfo());
    //   }
    // }
    win->display();
  }
}
