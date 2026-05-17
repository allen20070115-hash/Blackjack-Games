<<<<<<< Updated upstream
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Hand.h"
#include <vector>
#include <string>

class game {
public:
    game();
    void run();

private:
    sf::RenderWindow window;
    sf::Font font;
    std::vector<Card> deck;
    Hand playerHand, dealerHand;
    bool isGameOver;
    std::string msg;

    void reset();
    void deal();
    void hit();
    void stand();
    void render();
};

#endif
=======
version https://git-lfs.github.com/spec/v1
oid sha256:8950305825ea08df245e53faa4e1a9b9b246e162de3ba1e34b5712b2c4d144b3
size 452
>>>>>>> Stashed changes
