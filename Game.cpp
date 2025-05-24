#include "Game.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Cafe.h"

using namespace sf;

Game::Game(std::string title, Cafe* cafe) {
  this->cafe = cafe;
  customerKey = 0;
  newEmployee = -1;

  win = new ::sf::RenderWindow(sf::VideoMode(800, 600),
                               title);  // generates window

  // setting up font
  if (!font.loadFromFile("fonts/MyFont.ttf")) {
    std::cerr << "Failed to load font!" << std::endl;
  }

  employeeTimers.resize(cafe->get_maxEmployees());
  customerTexts.resize(cafe->get_maxCustomers());

  for (int i = 0; i < cafe->get_maxEmployees(); i++) {
    // THIS SECTION IS TAKEN FROM CHAT GPT
    Employee* employee = cafe->get_employee(i);  // get a single employee

    sf::Text label;
    label.setFont(font);
    label.setCharacterSize(16);
    label.setString(cafe->get_employee(i)->get_label());
    sf::FloatRect bounds = label.getLocalBounds();
    label.setOrigin(bounds.left + bounds.width / 2,
                    bounds.top + bounds.height / 2);
    label.setPosition(employee->get_x(), employee->get_y() + 40);
    label.setFillColor(sf::Color::White);

    employeeTimers[i] = label;
    win->draw(label);
  }

  // setting up waiterTimer
  // waiterTimer.setFont(font);
  // waiterTimer.setCharacterSize(15);
  // waiterTimer.setFillColor(sf::Color::White);
  // waiterTimer.setString("waiter");
  // sf::FloatRect bounds = waiterTimer.getLocalBounds();
  // waiterTimer.setOrigin(bounds.left + bounds.width / 2,
  //                       bounds.top + bounds.height / 2);

  // waiterTimer.setPosition(360, 440);

  // setting up cleanerTimer
  // cleanerTimer.setFont(font);
  // cleanerTimer.setCharacterSize(15);
  // cleanerTimer.setFillColor(sf::Color::White);
  // cleanerTimer.setString("cleaner");
  // bounds = cleanerTimer.getLocalBounds();
  // cleanerTimer.setOrigin(bounds.left + bounds.width / 2,
  //                        bounds.top + bounds.height / 2);
  // cleanerTimer.setPosition(480, 440);

  // setting up baristaTimer
  // baristaTimer.setFont(font);
  // baristaTimer.setCharacterSize(15);
  // baristaTimer.setFillColor(sf::Color::White);
  // baristaTimer.setString("barista");
  // bounds = baristaTimer.getLocalBounds();
  // baristaTimer.setOrigin(bounds.left + bounds.width / 2,
  //                        bounds.top + bounds.height / 2);
  // baristaTimer.setPosition(120, 440);

  // setting up chefTimer
  // chefTimer.setFont(font);
  // chefTimer.setCharacterSize(15);
  // chefTimer.setFillColor(sf::Color::White);
  // chefTimer.setString("chef");
  // bounds = chefTimer.getLocalBounds();
  // chefTimer.setOrigin(bounds.left + bounds.width / 2,
  //                     bounds.top + bounds.height / 2);
  // chefTimer.setPosition(240, 440);

  // setting up employeeTimer
  // employeeTimer.setFont(font);
  // employeeTimer.setCharacterSize(15);
  // employeeTimer.setFillColor(sf::Color::White);
  // employeeTimer.setString("");
  // bounds = chefTimer.getLocalBounds();
  // employeeTimer.setOrigin(bounds.left + bounds.width / 2,
  //                         bounds.top + bounds.height / 2);
  // employeeTimer.setPosition(600, 440);
}

void Game::drawFrame() {
  for (int i = 0; i < cafe->get_maxCustomers(); i++) {
    cafe->get_table(i).draw(win);  // draw tables
  }
  for (int j = 0; j < cafe->get_maxCustomers(); j++) {
    cafe->get_customer(j).draw(win);  // draw active customers
  }

  if (cafe->get_numFood() > 0) {
    // cafe->employees[1]->get_food().draw(win);  // draw food if available

    // FROM CHAT GPT
    KitchenStaff* ks = dynamic_cast<KitchenStaff*>(cafe->get_employee(1));
    if (ks != nullptr && cafe->get_numFood() > 0) {
      ks->get_food().draw(win);
    }
  }

  if (cafe->get_numDrink() > 0) {
    // cafe->employees[0]->get_drink().draw(win);  // draw drink if available

    // FROM CHAT GPT
    KitchenStaff* ks = dynamic_cast<KitchenStaff*>(cafe->get_employee(0));
    if (ks != nullptr && cafe->get_numDrink() > 0) {
      ks->get_drink().draw(win);
    }
  }

  // add employee is player has finished serving 2 customers
  newEmployee = cafe->add_employee();
  if (cafe->get_maxEmployees() > 4) {
    employeeTimers.resize(cafe->get_maxEmployees());
    employeeTimers[4].setString(cafe->get_employee(4)->get_label());

    employeeTimers[4].setFont(font);
    employeeTimers[4].setCharacterSize(15);
    employeeTimers[4].setFillColor(sf::Color::White);
    employeeTimers[4].setString(cafe->get_employee(4)->get_label());
    sf::FloatRect bounds = employeeTimers[4].getLocalBounds();
    employeeTimers[4].setOrigin(bounds.left + bounds.width / 2,
                                bounds.top + bounds.height / 2);
    employeeTimers[4].setPosition(600, 440);
  }

  baristaAction(0);
  chefAction(1);
  waiterAction(2);
  cleanerAction(3);
  if (cafe->get_maxEmployees() > 4) {
    newEmployeeAction(4);
  }

  for (int k = 0; k < cafe->get_maxCustomers(); k++) {
    // THIS SECTION IS TAKEN FROM CHAT GPT
    const Customer& customer = cafe->get_customer(k);  // get a single customer

    sf::Text label;
    label.setFont(font);
    label.setCharacterSize(16);
    label.setString(std::to_string(k + 1) + "\n" +
                    customer.get_customerAttributes());
    sf::FloatRect bounds = label.getLocalBounds();
    label.setOrigin(bounds.left + bounds.width / 2,
                    bounds.top + bounds.height / 2);
    label.setPosition(customer.get_x(), customer.get_y() + 80);
    label.setFillColor(sf::Color::White);
    customerTexts[k] = label;
    if (cafe->get_customer(k).get_isActive()) {
      win->draw(label);
    }
  }

  // draw employees and employee timers
  for (int l = 0; l < cafe->get_maxEmployees(); l++) {
    cafe->get_employee(l)->draw(win);
    win->draw(employeeTimers[l]);
  }

  // draw labels/timers
  //   for (int m=0; m<cafe->)
  //   win->draw(baristaTimer);
  //   win->draw(chefTimer);
  //   win->draw(waiterTimer);
  //   win->draw(cleanerTimer);
  //   win->draw(employeeTimer);
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
          if (cafe->get_numDrink() == 1) {
            std::cout << "barista has already brewed a drink!" << std::endl;
          } else {
            cafe->get_employee(0)->doTask(
                cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
            cafe->set_activeCustomer(-1);
          }
        }
        break;

      case Keyboard::W:
        if (cafe->get_activeCustomer() >= 0) {
          if (cafe->get_numFood() == 1) {
            std::cout << "chef has already cooked a serving!" << std::endl;
          } else {
            cafe->get_employee(1)->doTask(
                cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
            cafe->set_activeCustomer(-1);
          }
          break;

          case Keyboard::E:
            if (cafe->get_activeCustomer() >= 0) {
              cafe->get_employee(2)->doTask(
                  cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
              cafe->set_activeCustomer(-1);
            }
            break;

          case Keyboard::R:
            if (cafe->get_activeCustomer() >= 0) {
              cafe->get_employee(3)->doTask(
                  cafe->get_customerPointer(cafe->get_activeCustomer()), cafe);
              cafe->set_activeCustomer(-1);
            }
            break;

          case Keyboard::T:
            if (cafe->get_activeCustomer() >= 0 &&
                cafe->get_maxEmployees() > 4) {
              cafe->get_employee(4)->doTask(
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
      // if (actionClock.getElapsedTime().asSeconds() >= 1.0f) {
      cafe->newCustomer();
      cafe->customerLeaves();
      actionClock.restart();
      // decreases active customer's disgust based on their disgust timer
      for (int i = 0; i < cafe->get_maxCustomers(); i++) {
        if (cafe->get_customer(i).get_isActive() &&
            cafe->get_customer(i).get_disgustTime() <=
                std::time(nullptr) - 10) {
          cafe->get_customerPointer(i)->decrease_disgust(cafe->get_table(i));
        }
      }
    }
    // }

    win->clear();
    drawFrame();
    win->display();

    if ((cafe->get_numActiveCustomers() > cafe->get_maxCustomers() ||
         cafe->startTime.getElapsedTime().asSeconds() >
             cafe->get_gameDuration()) &&
        win->isOpen()) {
      std::cout << "Congratulations! you have finished the game" << std::endl;
      cafe->viewPerformance();
      win->close();
    }
  }
}

// generate drink if barista finished brewing, otherwise displays timer
void Game::baristaAction(int i) {
  if (cafe->get_employee(i)->get_waitTime() <= std::time(nullptr) - 10 &&
      cafe->get_employee(i)->get_wasCalled()) {
    cafe->increase_numDrink();
    employeeTimers[i].setString("barista");
    cafe->get_employee(i)->set_wasCalled(false);
    // std::cout << "number of drinks: " << cafe->get_numDrink() << std::endl;
  } else if (cafe->get_employee(i)->get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_employee(i)->get_wasCalled()) {
    employeeTimers[i].setString(
        "barista\n" +
        std::to_string(
            10 - (std::time(nullptr) - cafe->get_employee(i)->get_waitTime())));
  }
}

// generate food is chef finished cooking, otherwise displays timer
void Game::chefAction(int i) {
  if (cafe->get_employee(i)->get_waitTime() <= std::time(nullptr) - 10 &&
      cafe->get_employee(i)->get_wasCalled()) {
    cafe->increase_numFood();
    cafe->get_employee(i)->set_wasCalled(false);
    employeeTimers[i].setString("chef");
    // std::cout << "servings of food: " << cafe->get_numFood() << std::endl;
  } else if (cafe->get_employee(i)->get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_employee(i)->get_wasCalled()) {
    employeeTimers[i].setString(
        "chef\n" +
        std::to_string(
            10 - (std::time(nullptr) - cafe->get_employee(i)->get_waitTime())));
  }
}

//  NOTE: IF PLAYER PRESSES ANOTHER NUMBER, THIS WILL ASSIGN TO THE WRONG
// CUSTOMER
// serves food if waiter finished serving, otherwise displays timer
void Game::waiterAction(int i) {
  if (cafe->get_employee(i)->get_waitTime() <= std::time(nullptr) - 10) {
    cafe->get_employee(i)->get_body()->setPosition(
        employeeTimers[i].getPosition() + sf::Vector2f(0, -40));
    if (cafe->get_employee(i)->get_wasCalled()) {
      cafe->get_employee(i)->set_wasCalled(false);
      employeeTimers[i].setString("waiter");
      if (cafe->get_customerPointer(cafe->get_employee(i)->get_customerNo())
              ->get_hunger() < 5) {
        cafe->get_customerPointer(cafe->get_employee(i)->get_customerNo())
            ->increase_hunger();  // increase customer hunger
        // std::cout << "servings of food: " << cafe->get_numFood() <<
        // std::endl;
      }
      if (cafe->get_customerPointer(cafe->get_employee(i)->get_customerNo())
              ->get_thirst() < 5) {
        cafe->get_customerPointer(cafe->get_employee(i)->get_customerNo())
            ->increase_thirst();  // increase customer thirst
        // std::cout << "number of drinks: " << cafe->get_numDrink() <<
        // std::endl;
      }
      // std::cout << "function was happily called!" << std::endl;
    }
  } else if (cafe->get_employee(i)->get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_employee(i)->get_wasCalled()) {
    employeeTimers[i].setString(
        "waiter\n" +
        std::to_string(
            10 - (std::time(nullptr) - cafe->get_employee(i)->get_waitTime())));
    cafe->get_employee(i)->get_body()->setPosition(
        cafe->get_customer(cafe->get_employee(i)->get_customerNo())
            .get_body()
            ->getPosition() +
        sf::Vector2f(30, -10));
  }
}

// NOTE: IF PLAYER PRESSES ANOTHER NUMBER, THIS WILL ASSIGN TO THE WRONG
// CUSTOMER
// sets table to clean if cleaner finished cleaning, otherwise displays timer
void Game::cleanerAction(int i) {
  if (cafe->get_employee(i)->get_waitTime() <= std::time(nullptr) - 10) {
    cafe->get_employee(i)->get_body()->setPosition(
        employeeTimers[i].getPosition() + sf::Vector2f(0, -40));
    if (cafe->get_employee(i)->get_wasCalled()) {
      cafe->get_employee(i)->set_wasCalled(false);
      cafe->get_customerPointer(cafe->get_employee(i)->get_customerNo())
          ->get_tableNo()
          .set_isClean(true);
      cafe->get_customerPointer(cafe->get_employee(i)->get_customerNo())
          ->increase_disgust();
      employeeTimers[i].setString("cleaner");
    }
  } else if (cafe->get_employee(i)->get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_employee(i)->get_wasCalled()) {
    employeeTimers[i].setString(
        "cleaner\n" +
        std::to_string(
            10 - (std::time(nullptr) - cafe->get_employee(i)->get_waitTime())));
    // cafe->get_customerPointer(cafe->get_employee(i)->get_customerNo())
    //     ->get_body()
    //     ->setPosition(cafe->get_customer(i).get_body()->getPosition());
    cafe->get_employee(i)->get_body()->setPosition(
        cafe->get_customer(cafe->get_employee(i)->get_customerNo())
            .get_body()
            ->getPosition() +
        sf::Vector2f(-20, -10));
  }
}

void Game::newEmployeeAction(int i) {
  switch (newEmployee) {
    case 0:
      baristaAction(i);
      break;
    case 1:
      chefAction(i);
      break;
    case 2:
      waiterAction(i);
      break;
    case 3:
      cleanerAction(i);
      break;
    default:
      break;
  }
}

// destructor
Game::~Game() {}
