#ifndef HAND_H
#define HAND_H
#include <vector>

#include "Card.h"
using namespace std;

class Hand {
    public:
        void addCard(Card c);
        void clear();
        const vector<Card>& getCards() const;
        int getTotal() const;

    private:
        vector<Card> cards;
};

#endif