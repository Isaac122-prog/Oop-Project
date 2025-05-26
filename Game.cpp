#include "Game.h"

#include <jsoncpp/json/json.h>

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

#include "Cafe.h"

using namespace sf;

Game::Game(std::string title, Cafe* cafe) {
  this->cafe = cafe;
  customerKey = 0;
  newEmployee = -1;
  customerSave = 3;  // players can save after every 3 customers

  win = new ::sf::RenderWindow(sf::VideoMode(800, 600),
                               title);  // generates 800x600 window

  // setting up font
  if (!font.loadFromFile("fonts/MyFont.ttf")) {
    std::cerr << "Failed to load font!" << std::endl;
  }

  // set no. graphics labels to match no. customers/employees
  employeeTimers.resize(cafe->get_maxEmployees());
  customerTexts.resize(cafe->get_maxCustomers());

  // this for loop was written with help from generative AI 24/05/2024
  for (int i = 0; i < cafe->get_maxEmployees(); i++) {
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
}

void Game::drawFrame() {
  for (int i = 0; i < cafe->get_maxCustomers(); i++) {
    cafe->get_table(i).draw(win);  // draw tables
  }
  for (int j = 0; j < cafe->get_maxCustomers(); j++) {
    cafe->get_customer(j).draw(win);  // draw active customers
  }

  if (cafe->get_numFood() > 0) {
    // written with help from generative AI 24/05/2025
    KitchenStaff* ks = dynamic_cast<KitchenStaff*>(cafe->get_employee(1));
    if (ks != nullptr && cafe->get_numFood() > 0) {
      ks->get_food().draw(win);  // draw food if available
    }
  }

  if (cafe->get_numDrink() > 0) {
    // written with help from generative AI 24/05/2025
    KitchenStaff* ks = dynamic_cast<KitchenStaff*>(cafe->get_employee(0));
    if (ks != nullptr && cafe->get_numDrink() > 0) {
      ks->get_drink().draw(win);  // draw drink if available
    }
  }

  // add employee if player has finished serving the 2nd customer
  newEmployee = cafe->add_employee();

  // add new employee graphics when user adds new employee to the game
  if (cafe->get_maxEmployees() > 4) {
    employeeTimers.resize(cafe->get_maxEmployees());
    employeeTimers[4].setFont(font);
    employeeTimers[4].setCharacterSize(15);
    employeeTimers[4].setFillColor(sf::Color::White);
    employeeTimers[4].setString(cafe->get_employee(4)->get_label());
    sf::FloatRect bounds = employeeTimers[4].getLocalBounds();
    employeeTimers[4].setOrigin(bounds.left + bounds.width / 2,
                                bounds.top + bounds.height / 2);
    employeeTimers[4].setPosition(600, 440);
  }

  // executes ongoing employee actions
  baristaAction(0);
  chefAction(1);
  waiterAction(2);
  cleanerAction(3);
  if (cafe->get_maxEmployees() > 4) {
    newEmployeeAction(4);
  }

  // generates and displays graphics for customers
  // this for loop was written with help from generative AI 24/05/2025
  for (int k = 0; k < cafe->get_maxCustomers(); k++) {
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

      //  Q W E R T executes barista, chef, waiter, cleaner, & employee doTask()
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

            // view the player's current performance
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
      keyBindings(e);  // set keybindings
    }

    // if the cafe timer is below the game duration
    if (cafe->startTime.getElapsedTime().asSeconds() <
        cafe->get_gameDuration()) {
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

    // give player option to save game file after 3 customers
    if (cafe->get_numActiveCustomers() % 3 == 0 &&
        cafe->get_numActiveCustomers() == customerSave) {
      // && cafe->get_customer(cafe->get_numActiveCustomers() -
      // 1).get_happiness() == 15
      int save = 0;
      customerSave += 3;
      std::cout << "press 1 if you want to save the game" << std::endl;
      std::cin >> save;
      if (save == 1) {
        saveFile();
      } else {
        std::cout << "game unsaved" << std::endl;
      }
    }

    win->clear();
    drawFrame();
    win->display();

    // close window when player has completed game and display final scores
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
    cafe->increase_numDrink();               // increase number of drinks
    employeeTimers[i].setString("barista");  // reset graphics
    cafe->get_employee(i)->set_wasCalled(false);
  } else if (cafe->get_employee(i)->get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_employee(i)->get_wasCalled()) {
    // set graphics to show timer
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
    cafe->increase_numFood();             // increase number of food servings
    employeeTimers[i].setString("chef");  // reset graphics
    cafe->get_employee(i)->set_wasCalled(false);
  } else if (cafe->get_employee(i)->get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_employee(i)->get_wasCalled()) {
    // set graphics to show timer
    employeeTimers[i].setString(
        "chef\n" +
        std::to_string(
            10 - (std::time(nullptr) - cafe->get_employee(i)->get_waitTime())));
  }
}

// serves food if waiter finished serving, otherwise displays timer
void Game::waiterAction(int i) {
  if (cafe->get_employee(i)->get_waitTime() <= std::time(nullptr) - 10) {
    cafe->get_employee(i)->get_body()->setPosition(
        employeeTimers[i].getPosition() +
        sf::Vector2f(0, -40));  // move waiter to original position
    if (cafe->get_employee(i)->get_wasCalled()) {
      cafe->get_employee(i)->set_wasCalled(false);
      employeeTimers[i].setString("waiter");
      if (cafe->get_customerPointer(cafe->get_employee(i)->get_customerNo())
              ->get_hunger() < 5) {
        cafe->get_customerPointer(cafe->get_employee(i)->get_customerNo())
            ->increase_hunger();  // increase customer hunger
      }
      if (cafe->get_customerPointer(cafe->get_employee(i)->get_customerNo())
              ->get_thirst() < 5) {
        cafe->get_customerPointer(cafe->get_employee(i)->get_customerNo())
            ->increase_thirst();  // increase customer thirst
      }
    }
  } else if (cafe->get_employee(i)->get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_employee(i)->get_wasCalled()) {
    // set graphics to show timer
    employeeTimers[i].setString(
        "waiter\n" +
        std::to_string(
            10 - (std::time(nullptr) - cafe->get_employee(i)->get_waitTime())));
    // move waiter to customer's table
    cafe->get_employee(i)->get_body()->setPosition(
        cafe->get_customer(cafe->get_employee(i)->get_customerNo())
            .get_body()
            ->getPosition() +
        sf::Vector2f(30, -10));
  }
}

// sets table to clean if cleaner finished cleaning, otherwise displays timer
void Game::cleanerAction(int i) {
  if (cafe->get_employee(i)->get_waitTime() <= std::time(nullptr) - 10) {
    cafe->get_employee(i)->get_body()->setPosition(
        employeeTimers[i].getPosition() + sf::Vector2f(0, -40));
    if (cafe->get_employee(i)->get_wasCalled()) {
      cafe->get_employee(i)->set_wasCalled(false);
      cafe->get_customerPointer(cafe->get_employee(i)->get_customerNo())
          ->get_tableNo()
          .set_isClean(true);  // set table to clean
      cafe->get_customerPointer(cafe->get_employee(i)->get_customerNo())
          ->increase_disgust();  // max out disgust
      employeeTimers[i].setString("cleaner");
    }
  } else if (cafe->get_employee(i)->get_waitTime() > std::time(nullptr) - 10 &&
             cafe->get_employee(i)->get_wasCalled()) {
    // set graphics to show timer
    employeeTimers[i].setString(
        "cleaner\n" +
        std::to_string(
            10 - (std::time(nullptr) - cafe->get_employee(i)->get_waitTime())));
    // move cleaner to customer's table
    cafe->get_employee(i)->get_body()->setPosition(
        cafe->get_customer(cafe->get_employee(i)->get_customerNo())
            .get_body()
            ->getPosition() +
        sf::Vector2f(-20, -10));
  }
}

// completes new employee's action based on employee type
void Game::newEmployeeAction(int i) {
  switch (newEmployee) {
    case 0:
      waiterAction(i);
      break;
    case 1:
      cleanerAction(i);
      break;
    default:
      break;
  }
}

// saves current progress to event_data.json
void Game::saveFile() {
  Json::Value data;  // initialise

  // set data
  data["maxCustomers"] = cafe->get_maxCustomers();
  data["numFood"] = cafe->get_numFood();
  data["numDrink"] = cafe->get_numDrink();
  data["numEmployees"] = cafe->get_maxEmployees();
  data["newEmployee"] = cafe->get_employeeType();

  // create customerArray to store each customer's info
  Json::Value customerArray(Json::arrayValue);

  for (int i = 0; i < cafe->get_maxCustomers(); i++) {
    Customer* cust = cafe->get_customerPointer(i);
    Json::Value customerJson;
    customerJson["thirst"] = cust->get_thirst();
    customerJson["hunger"] = cust->get_hunger();
    customerJson["disgust"] = cust->get_disgust();
    customerJson["isActive"] = cust->get_isActive();
    customerJson["happiness"] = cust->get_happiness();
    customerJson["number"] = i;
    customerArray.append(customerJson);
  }

  // store customerArray
  data["customers"] = customerArray;

  // upload to file
  std::string output_file_path = "event_data.json";
  std::ofstream file(output_file_path);

  Json::StreamWriterBuilder writer;
  writer["indentation"] = "    ";
  Json::StreamWriter* jsonWriter = writer.newStreamWriter();
  jsonWriter->write(data, &file);
  file.close();
  std::cout << "Data written to " << output_file_path << " as JSON."
            << std::endl;  // output message for confirmation
}

// getter for cafe attribute
Cafe* Game::get_cafe() { return cafe; }

// destructor
Game::~Game() {}
