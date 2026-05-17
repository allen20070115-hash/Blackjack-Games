#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include <vector>
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