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
    if (cafe.get_gameDuration() !=300){
      cout << "Cafe test 2 failed!" << endl;
    }
    // test 3: newCustomer()
    cafe.newCustomer();
    if (cafe.get_customer(1).get_isActive() == false){
      cout << "Cafe test 3 failed!" << endl;
    }
    // test 4: CustomerLeaves()
    cafe.customerLeaves();
    if (cafe.get_customer(0).get_isActive() == true){
      cout << "Cafe test 4 failed!" << endl;
    }
    return 0;
  }



  int testPlayer() {
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
    return 0;
  }



  int testTable() {
    Cafe tableCafe = Cafe(1);
    Table table;
    Cleaner cleaner;
    // test 1: table gets clean when cleaned
    cleaner.doTask(0,0);
    if (table.get_isClean() != true) {
      cout << "Table test 1 failed!" << endl;
    }
    return 0;
  }



  int testCustomer() {
    Cafe customerCafe = Cafe(1);
    Customer customer;
    Cafe cafe;
    Table table;
    Chef chef;
    Waiter waiter;
    Barista barista;
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
      chef.doTask(0,0);
      waiter.doTask(0,0);
      if (customer.get_hunger() < initialHunger) {
        cout << "Customer test 3 failed!" << endl;
      }
    }
    // test 4: getting drink increases thirsty count
    int initialThirst = customer.get_thirst();
    while (cafe.get_customer(0).get_thirst() != 5){
      barista.doTask(0,0);
      waiter.doTask(0,0);
      if (customer.get_thirst() < initialThirst) {
        cout << "Customer test 4 failed!" << endl;
      }
    }
    // test 5: table clean means disgust == 5
    if (table.get_isClean() == true) {
      if (customer.get_disgust() != 5) {
        cout << "Customer test 5 failed!" << endl;
      }
    }
    return 0;
  }





  int testCleaner() {
    Cafe cleanerCafe = Cafe(1);
    Cleaner cleaner;
    // test 1: customer disgust level agrees with cleanliness of table
    // test 2: having cleaned the table the customer disgust level increases
    return 0;
  }



  int testChef() {
    Cafe chefCafe = Cafe(1);
    Chef chef;
    Cafe cafe;
    // test 1: cooking food increasing food count
    int initialNumFood = cafe.get_numFood();
    int expectedNumFood = initialNumFood + 1;
    chef.doTask(0,0);
    while (cafe.get_customer(0).get_hunger() < 5){
      int currentNumFood = cafe.get_numFood();
      if (currentNumFood != expectedNumFood) {
        cout << "Chef test 1 failed!" << endl;
      }
    }
    return 0;
  }



  int testBarista() {
    Cafe baristaCafe = Cafe(1);
    Barista barista;
    Cafe cafe;
    // test 1: brewing drinks increases drink count
    int initialNumDrink = cafe.get_numDrink();
    int expectedNumDrink = initialNumDrink + 1;
    barista.doTask(0,0);
    while (cafe.get_customer(0).get_thirst() < 5){
      int currentNumDrink = cafe.get_numDrink();
      if (currentNumDrink != expectedNumDrink) {
        cout << "Chef test 1 failed!" << endl;
      }
    }
    return 0;
  }



  int testWaiter() {
    Cafe waiterCafe = Cafe(1);
    Waiter waiter;
    // test 1: serve a drink decreases numDrink
    // test 2: serve a drink increases customer thirst
    // test 3: serve a food decreases numFood
    // test 4: serve a food increases customer hunger
    return 0;
  }
};

#endif

