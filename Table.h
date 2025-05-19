#ifndef TABLE_H
#define TABLE_H

#include <SFML/Graphics.hpp>

class Table{
    protected:
        sf::RectangleShape* body;
        bool isClean;
        int depth;
        // bool isOccupied; only need if customers are assigned tables randomly
    public:
        Table();
        Table(int depth);

        void draw(sf::RenderWindow* win);
    

        void set_isClean(bool cleanliness);
        bool get_isClean();

        // void set_isOccupied(bool occupation);
        // bool get_isOccupied();
};

#endif