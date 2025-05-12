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
  void testCafe() {
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
      cout << "test 1 failed!";
    }
    // test 2
  }
  void testPlayer() {
    Cafe playerCafe = Cafe(1);
    Player player;
  }
};

#endif