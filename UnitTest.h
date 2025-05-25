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
      cout << "test 1 failed!" << endl;
    }
    // test 2: game duration
    if (cafe.get_gameDuration().count() !=300){
      cout << "test 2 failed!" << endl;
    }
    // test 3: newCustomer()
    cafe.newCustomer();
    if (cafe.get_customer(1).get_isActive() == false){
      cout << "test 3 failed!" << endl;
    }
    // test 4: CustomerLeaves()
    cafe.CustomerLeaves();
    if (cafe.get_customer(0).get_isActive() == true){
      cout << "test 4 failed!" << endl;
    }
    return 0;
  }

  void testPlayer() {
    Cafe playerCafe = Cafe(1);
    Player player;
  }

  void testTable() {
    Cafe tableCafe = Cafe(1);
    Table table;
  }

  void testCustomer() {
    Cafe customerCafe = Cafe(1);
    Customer customer;
  }

  void testEmployee() {
    Cafe employeeCafe = Cafe(1);
    Employee employee;
  }

  void testCleaner() {
    Cafe cleanerCafe = Cafe(1);
    Cleaner cleaner;
  }

  void testKitchenStaff() {
    Cafe kitchenstaffCafe = Cafe(1);
    KitchenStaff kitchenstaff;
  }

  void testChef() {
    Cafe chefCafe = Cafe(1);
    Chef chef;
  }

  void testBarista() {
    Cafe baristaCafe = Cafe(1);
    Barista barista;
  }

  void testWaiter() {
    Cafe waiterCafe = Cafe(1);
    Waiter waiter;
  }

};

#endif

