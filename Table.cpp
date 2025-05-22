#include "Table.h"

#include <SFML/Graphics.hpp>

Table::Table(){
    depth = 0;
    isClean = true;
}

Table::Table(int depth){
    // table is clean 
    isClean = true;
    this->depth = depth;
    body = new sf::RectangleShape(sf::Vector2f(20, 20));
    body -> setFillColor(sf::Color::Blue);
    body -> setOrigin(10, 10);
}

 sf::RectangleShape* Table::get_body(){
    return body;
 }

void Table::draw(sf::RenderWindow* win){
    win -> draw(*body);
}


void Table::set_isClean(bool cleanliness){
    isClean = cleanliness;
}

bool Table::get_isClean(){
    return isClean;
}

// void Table::set_isOccupied(bool occupation){
//     isOccupied = occupation;
// }

// bool Table::get_isOccupied(){
//     return isOccupied;
// }

Table::~Table(){}