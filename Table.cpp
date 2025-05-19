#include "Table.h"

Table::Table(){
    // table is clean 
    isClean = true;
    // body = new sf::RectangleShape(sf::Vector2f(10,5));
    // body -> setFillColour(sf::Color::Blue);
    // body -> setPosition(-1,-1);
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