#include <chrono>
#include <iostream>

#include "Cafe.h"
#include "Customer.h"
#include "Player.h"
#include "Table.h"

using namespace std;

int main() {
  int maxCustomers;
  cout << "How many customers do you want?" << endl;
  cin >> maxCustomers;

  Cafe gameCafe = Cafe(maxCustomers);

  Player player = Player();

  // player.viewPerformance();

  for (int i = 0; i < gameCafe.get_maxCustomers(); i++) {
    cout << "customer " << i << "score: " << gameCafe.get_customer(i).get_happiness()
         << endl;
  }

  return 0;
}