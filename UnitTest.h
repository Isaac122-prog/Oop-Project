#ifndef UNITTEST_H
#define UNITTEST_H

#include <iostream>

#include "Cafe.h"
#include "Player.h"

using namespace std;

class UnitTest {
 public:
  void runTests() { testCafe(); }

 private:
  int testCafe() {
    // standard cafe with 5 customers
    Cafe cafe = Cafe(5);

    // example of a unit test
    // if (addition.add(1, 2) != 3) {
    //     std::cout << "Test 1 failed!" << std::endl;
    // }

    // test 1: set all attributes to 5, happiness = 15
    while (cafe.get_customer(0).get_disgust() < 5 ||
           cafe.get_customer(0).get_hunger() < 5 ||
           cafe.get_customer(0).get_thirst() < 5) {
      cafe.get_customer(0).increase_disgust();
      cafe.get_customer(0).increase_hunger();
      cafe.get_customer(0).increase_thirst();
    }
    if (cafe.get_customer(0).get_disgust() != 5 ||
        cafe.get_customer(0).get_hunger() != 5 ||
        cafe.get_customer(0).get_thirst() != 5) {
      cout << "Cafe test 1 failed!" << endl;
    }
    // test 2: game duration
    if (cafe.get_gameDuration().count() !=300){
      cout << "Cafe test 2 failed!" << endl;
    }
    // test 3: newCustomer()
    cafe.newCustomer();
    if (cafe.get_customer(1).get_isActive() == false){
      cout << "Cafe test 3 failed!" << endl;
    }
    // test 4: CustomerLeaves()
    cafe.CustomerLeaves();
    if (cafe.get_customer(0).get_isActive() == true){
      cout << "Cafe test 4 failed!" << endl;
    }
    return 0;
  }



  void testPlayer() {
    Cafe playerCafe = Cafe(1);
    Player player;
    // test 1: tasks are done and energy decreases by 10 when task list non empty and energy above 10
    int prePerformTask = player.getEnergy();
    player.performTask();
    int currentEnergy = player.getEnergy();
    int theoreticalEnergy = prePerformTask - 10;
    if (currentEnergy > 10) {
      if (currentEnergy != theoreticalEnergy) {
        cout << "Player test 1 failed!" << endl;
      }
    }
    // test 2: performTask not done if energy less then 10
    player.performTask();
    if (player.getEnergy() < 0) {
      cout << "Player test 2 failed!" << endl;
    }
    // test 3: rest only gets energy back to max energy
    if (player.getEnergy() > player.getMaxEnergy()) {
      cout << "Player test 3 failed!" << endl;
    }
  }



  void testTable() {
    Cafe tableCafe = Cafe(1);
    Table table;
    // test 1: table gets clean when cleaned
    cleaner.doTask();
    if (table.get_isClean() != true) {
      cout << "Table test 1 failed!" << endl;
    }
  }



  void testCustomer() {
    Cafe customerCafe = Cafe(1);
    Customer customer;
    // test 1: max time of customer timer == 2mins
    if (customer.get_endTime() - customer.get_startTime() != 120) {
      cout << "Customer test 1 failed!" << endl;
    }
    // test 2: happiness does not exceed 15
    if (customer.get_happiness() > 15) {
      cout << "Customer test 2 failed!" << endl;
    }
    // test 3: getting food increases hunger count
    int initialHunger = customer.get_hunger();
    while (cafe.get_customer(0).get_hunger() != 5){
      
    }
    // test 4: getting drink increases thirsty count

    // test 5: table clean means disgust == 5
    if (table.get_isClean() == true) {
      if (customer.get_disgust() != 5) {
        cout << "Customer test 5 failed!" << endl;
      }
    }
  }



  void testEmployee() {
    Cafe employeeCafe = Cafe(1);
    Employee employee;
    // test 1: set is busy and returned value are the same
    // test 2: set is called and returned value are the same
    // test 3: get wait time
    // test 4: get label
    // test 5: get customer number
  }



  void testCleaner() {
    Cafe cleanerCafe = Cafe(1);
    Cleaner cleaner;
    // test 1: customer disgust level agrees with cleanliness of table
    // test 2: having cleaned the table the customer disgust level increases
  }



  void testChef() {
    Cafe chefCafe = Cafe(1);
    Chef chef;
    // test 1: cooking food increasing food count
    int initialNumFood = cafe.get_numFood();
    int expectedNumFood = initialNumFood + 1;
    chef.doTask();
    while (cafe.get_customer(0).get_hunger() < 5){
      int currentNumFood = cafe.get_numFood();
      if (currentNumFood != expectedNumFood) {
        cout << "Chef test 1 failed!" << endl;
      }
    }
  }



  void testBarista() {
    Cafe baristaCafe = Cafe(1);
    Barista barista;
    // test 1: brewing drinks increases drink count
    int initialNumDrink = cafe.get_numDrink();
    int expectedNumDrink = initialNumDrink + 1;
    barista.doTask();
    while (cafe.get_customer(0).get_thirst() < 5){
      int currentNumDrink = cafe.get_numDrink();
      if (currentNumDrink != expectedNumDrink) {
        cout << "Chef test 1 failed!" << endl;
      }
    }

  }



  void testWaiter() {
    Cafe waiterCafe = Cafe(1);
    Waiter waiter;
    // test 1: serve a drink decreases numDrink
    // test 2: serve a drink increases customer thirst
    // test 3: serve a food decreases numFood
    // test 4: serve a food increases customer hunger
  }
};

#endif

