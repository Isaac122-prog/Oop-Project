#ifndef TABLE_H
#define TABLE_H

class Table{
    protected:
        bool isClean;
    public:
        Table();

        void set_isClean(bool cleanliness);
        bool get_isClean();
};

#endif