#ifndef DATA_H
#define DATA_H

class Data
{
    private:
        int _x;
        int _y;

    public:
        Data();
        Data(int x, int y);
        Data(const Data & other);
        ~Data();
        Data & operator=(const Data & other);

        int getY() const;
        int getX() const;
} ;

#endif