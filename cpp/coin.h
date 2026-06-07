#ifndef COIN_H
#define COIN_H

class Coin {
    private:
        int value;

    public:
        Coin();
        Coin(int v);
        int getValue() const;
        void setValue(int v);
};

#endif
