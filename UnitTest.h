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
    // test 1: receive customer ID
    // test 2: assign task to employee
    // test 3: rest only goes back to max energy
    player.getEnergy();
    player.getMaxEnergy();
    if (Energy > maxEnergy) {
      cout << "Player test 3 failed!" << endl;
    }
  }

  void testTable() {
    Cafe tableCafe = Cafe(1);
    Table table;
    // test 1: table starts clean
    // test 2: table gets dirty
    // test 3: table gets clean when cleaned
  }

  void testCustomer() {
    Cafe customerCafe = Cafe(1);
    Customer customer;
    // test 1: max time of customer timer == 2mins
    // test 2: initial value of disgust == 5
    // test 3: intial value of hunger is between 0 and 5
    // test 4: initial value of thirst is between 0 and 5
    // test 5: initial value of happiness != 15
    // test 6: getting food increases hunger count
    // test 7: getting drink increases thirsty count
    // test 8: disgust not 5 means table not clean
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
    // test 1: customer in cafe check is working
    // test 2: customer disgust level agrees with cleanliness of table
    // test 3: having cleaned the table the customer disgust level increases
  }

  void testKitchenStaff() {
    Cafe kitchenstaffCafe = Cafe(1);
    KitchenStaff kitchenstaff;
  }

  void testChef() {
    Cafe chefCafe = Cafe(1);
    Chef chef;
    // test 1: customer in cafe check is working
    // test 2: cooking food increasing food count
  }

  void testBarista() {
    Cafe baristaCafe = Cafe(1);
    Barista barista;
    // test 1: customer in cafe check is working
    // test 2: brewing drinks increases drink count
  }

  void testWaiter() {
    Cafe waiterCafe = Cafe(1);
    Waiter waiter;
    // test 1: customer in cafe check is working
    // test 2: numfood + numdrink == 0 produces correct message
    // test 3: receive customer hunger correct
    // test 4: receive customer thirsty correct
    // test 5: serve a drink decreases numDrink
    // test 6: serve a drink increases customer thirst
    // test 7: serve a food decreases numFood
    // test 8: serve a food increases customer hunger
  }

};

#endif

