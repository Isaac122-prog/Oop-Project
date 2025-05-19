#ifndef DRINK_H
#define DRINK_H

class Drink {
 private:
  int numDrink;
  bool isActive;

 public:
  Drink();

  bool get_isActive();
  void set_isActive(bool status);
  
  ~Drink();
};

#endif