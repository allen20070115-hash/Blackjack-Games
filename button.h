#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

class Button {
    private:
        sf::RectangleShape shape;
        sf::Text text;

    public:
        Button(sf::Vector2f position, sf::Vector2f size, const sf::Font& font,
               const std::string& btnText);

        void update(const sf::RenderWindow& window);

        bool isClicked(const sf::Event& event, const sf::RenderWindow& window);

        void draw(sf::RenderWindow& window) const;
};

#endif