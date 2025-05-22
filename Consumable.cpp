#include "Consumable.h"

Consumable::Consumable(){
    isActive = false;
    body = new sf::RectangleShape(sf::Vector2f(10, 10));
  body->setFillColor(sf::Color::White);
  body->setOrigin(5, 5);
  body->setPosition(0, 0);
}

bool Consumable::get_isActive(){
    return isActive;
}
void Consumable::set_isActive(bool status){
    isActive = status;
}

void Consumable::draw(sf::RenderWindow* win){ win->draw(*body); }

sf::Shape* Consumable::get_body(){return body;}
int Consumable::get_x() { return body->getPosition().x; }
int Consumable::get_y() { return body->getPosition().y; }
int Consumable::get_depth(){return depth;}
void Consumable::set_position(sf::Vector2f position) {
  body->setPosition(position);
}


Consumable::~Consumable(){}