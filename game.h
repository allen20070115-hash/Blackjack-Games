#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Hand.h"
#include "coin.h"

class game {
    public:
        game();
        void run();
        Coin player;
        Coin dealer;
        int bet;

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
        void gameOver();
};

#endif
