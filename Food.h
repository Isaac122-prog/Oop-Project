#ifndef FOOD_H
#define FOOD_H

class Food {
 private:
  bool isActive;

 public:
  Food();

  bool get_isActive();
  void set_isActive(bool status);

  ~Food();
};

#endif