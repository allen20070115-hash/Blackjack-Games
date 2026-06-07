#include "Card.h"
using namespace std;

Card::Card(int v, Suit s, string n) {
    value = v;
    suit = s;
    name = n;
}

void Card::draw(sf::RenderWindow& window, sf::Vector2f pos, bool faceUp,
                const sf::Font& font) const {
    sf::RectangleShape rect({120.f, 180.f}); // 卡片大小
    rect.setPosition(pos);                   // 卡片位置
    rect.setOutlineThickness(2);             // 卡片邊框厚度
    rect.setOutlineColor(sf::Color::Black);  // 卡片邊框顏色

    if (faceUp) {
        rect.setFillColor(sf::Color::White); // 卡片正面白色
        window.draw(rect);                   // 畫卡片背景
        sf::Text text(font, name, 24);       // 卡片文字

        text.setFillColor((suit == Suit::Hearts || suit == Suit::Diamonds)
                              ? sf::Color::Red
                              : sf::Color::Black);      // 紅色或黑色
        text.setPosition({pos.x + 20.f, pos.y + 20.f}); // 文字位置
        window.draw(text);                              // 畫卡片文字

    } else {
        rect.setFillColor(sf::Color(70, 70, 150)); // 卡片背面顏色
        window.draw(rect);                         // 畫卡片背面
    }
}

int Card::getValue() const { return value; }
string Card::getName() const { return name; }
