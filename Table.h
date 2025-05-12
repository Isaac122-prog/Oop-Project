#ifndef TABLE_H
#define TABLE_H

class Table{
    protected:
        bool isClean;
        // bool isOccupied; only need if customers are assigned tables randomly
    public:
        Table();

        void set_isClean(bool cleanliness);
        bool get_isClean();

        // void set_isOccupied(bool occupation);
        // bool get_isOccupied();
};

#endif