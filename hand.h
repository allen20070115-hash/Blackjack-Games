<<<<<<< Updated upstream
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
=======
version https://git-lfs.github.com/spec/v1
oid sha256:440f1bea38ad391b0fbf790f9b1254a0db43e2d60212decdf9041006eb276ebe
size 280
>>>>>>> Stashed changes
